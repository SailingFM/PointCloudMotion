#include "sample_properity.h"
#include <Eigen/Dense>
#include "basic_types.h"
#include "sample_set.h"
#include <unordered_set>
using namespace std;

namespace SampleManipulation{
void compute_normal( IndexType selected_smp,  NormalType& baseline )
{
	const IndexType k = 18;

	Sample& smp = SampleSet::get_instance()[selected_smp];

	for ( IndexType i=0; i < smp.num_vertices(); i++ )
	{
		MatrixX3	k_nearest_verts(k, 3);
		IndexType		neighbours[k];
		ScalarType dist[k];
		smp.neighbours( i, k, neighbours, dist );
		for ( IndexType j=0; j<k; j++ )
		{
			IndexType neighbour_idx = neighbours[j];

			k_nearest_verts.row(j) << smp[neighbour_idx].x(), smp[neighbour_idx].y(), smp[neighbour_idx].z();
		}

		MatrixX3 vert_mean = k_nearest_verts.colwise().mean();
		MatrixX3 Q(k, 3);
		for (  IndexType j=0; j<k;j++)
		{
			Q.row(j) = k_nearest_verts.row(j) - vert_mean;
		}

		Matrix33 sigma = Q.transpose() * Q;

		Eigen::EigenSolver<Matrix33> eigen_solver(sigma, Eigen::ComputeFullU | Eigen::ComputeFullV);
		auto ev = eigen_solver.eigenvectors();
		NormalType nv; 
		nv(0) = (ev.col(0))(0).real();
		nv(1) = (ev.col(0))(1).real();
		nv(2) = (ev.col(0))(2).real();

		nv.normalize();
		if ( baseline.dot(nv) < 0 )
		{
			nv = - nv;
		}

		smp[i].set_normal( nv );
	}
}

void SampleManipulation::generate_hypothesis( IndexType seed_vtx_idx, IndexType sample_vtx_idx, IndexType sample_size, ScalarType sigma )
{
	//unfinished
	Sample& smp = SampleSet::get_instance()[0];
	ScalarType* exp_dist = new ScalarType[ smp.num_vertices() ];
	for ( IndexType i=0; i < smp.num_vertices(); i++ )
	{
		ScalarType dist_sq = ( smp[i].x() - smp[seed_vtx_idx].x() )*( smp[i].x() - smp[seed_vtx_idx].x() )
			+ ( smp[i].y() - smp[seed_vtx_idx].y() )*( smp[i].y() - smp[seed_vtx_idx].y() )
			+ ( smp[i].z() - smp[seed_vtx_idx].z() )*( smp[i].z() - smp[seed_vtx_idx].z() );
		exp_dist[i] = exp( -dist_sq/sigma );
	}

}

SubSampleSolution::SubSampleSolution( Sample& s, Sample& t, IndexType r ):source_sample_(s),
	target_sample_(t), resolv_(r)
{ 
	int depth = 0;
	int re = r;
	while ( re )
	{
		++depth;
		re = re>>1;
	}
	if ( depth!=0 )
	{
		ScalarType near_corner[3];
		ScalarType far_corner[3];
		for (int i=0;i<3; ++i)
		{
			near_corner[i] = source_sample_.box_near_corner()(i);
			far_corner[i] = source_sample_.box_far_corner()(i);
		}
		otree_.init_octree( depth, near_corner, far_corner ); 
	}

}

vector<IndexType> SubSampleSolution::compute()
{

	for ( IndexType i=0; i<source_sample_.num_vertices(); ++i )
	{
		ScalarType position[] = { source_sample_[i].x(), source_sample_[i].y(), source_sample_[i].z() };
		otree_.insert( position, i );

	}
	vector<IndexType> vtx_map;
	build_subSample( otree_.return_all_domain_tag(),vtx_map );
	return vtx_map;
}

void SubSampleSolution::build_subSample( vector<vector<IndexType> >& groups, vector<IndexType>& vtx_map)
{
	//Construct sub Sample
	for ( vector<vector<IndexType>>::iterator vv_iter = groups.begin(); 
		vv_iter!=groups.end();++vv_iter )
	{

		vector<IndexType>& group = *vv_iter;
		vector<PointType> point_inside_group( group.size() );
		
		for ( int i=0; i<group.size(); ++i)
		{
			point_inside_group[i] = PointType(source_sample_[group[i]].x()
				,source_sample_[group[i]].y(), source_sample_[group[i]].z() ) ;
		}
		PointType center_point(0.,0.,0.);
		for ( int i=0;i<point_inside_group.size();++i)
		{
			center_point += point_inside_group[i];
		}
		center_point = center_point/point_inside_group.size();
		IndexType idx_nearest_center_in_group=0;
		ScalarType min_dist = l1_distance( point_inside_group[0], center_point );
		for( int i=1; i<point_inside_group.size(); ++i )
		{
			ScalarType cur_dist = l1_distance( point_inside_group[i], center_point );
			if ( cur_dist<min_dist )
			{
				min_dist = cur_dist;
				idx_nearest_center_in_group = i;
			}
		}
		//index in source sample
		IndexType idx_ss = group[idx_nearest_center_in_group];
		target_sample_.add_vertex( 
			PointType(source_sample_[idx_ss].x(), source_sample_[idx_ss].y(),source_sample_[idx_ss].z()),
			NormalType(source_sample_[idx_ss].nx(), source_sample_[idx_ss].ny(),source_sample_[idx_ss].nz()),
			ColorType(1.,1.,1.,1.));
		vtx_map.push_back(idx_ss);
	}
	target_sample_.build_kdtree();
}

SubSampleSolution::~SubSampleSolution()
{

	otree_.release();
}

}