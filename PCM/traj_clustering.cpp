#include "traj_clustering.h"
#include "J_linkage.h"
#include "J_linkage_II.h"
#include "traj2model_distance.h"
#include "DeformaleRegistration.h"
#include "tracer.h"
#include <vector>
#include "color_table.h"
#include <Eigen/Dense>
#include <engine.h>
#include "globals.h"
#include "sample_properity.h"

using namespace Eigen;
using namespace std;

void TrajClusteringThread::run()
{
	Sample& smp0 = SampleSet::get_instance()[0];
	Sample sub_smp;
	SampleManipulation::SubSampleSolution solv( smp0, sub_smp, 128*128*128 );
	vector<IndexType> vtx_map = solv.compute();

	for ( int i=0; i<smp0.num_vertices();i++ )
	{
		smp0[i].set_visble(false);
	}
	for (int i=0; i<vtx_map.size(); ++i)
	{
		smp0[vtx_map[i]].set_visble(true);
	}

	Logger<<"sample size: "<<vtx_map.size()<<endl;

	//Logger << "Begin Trajectory Clustering.\n";

	//DeformableRegistration nonrigid;

	//vector<PCloudTraj> totalTraj;
	////nonrigid.calculateLifeSpansTraj(totalTraj,2);
	////nonrigid.calculateFixedLengthTraj(totalTraj,5,8);
	//nonrigid.produceDreamTraj(totalTraj);
	//Tracer& tracer = Tracer::get_instance();
	//tracer.clear_records();

	////visualize trajectorys
	////for ( IndexType i=0; i < totalTraj.size(); i+=20 )
	////{
	////	PCloudTraj& traj = totalTraj[i];
	////	IndexType traj_len_minus_one =  traj.trajNode.size() - 1;
	////	for ( IndexType j = 0; j < traj_len_minus_one; ++j )
	////	{
	////		tracer.add_record( traj.trajLifeSpan.start + j, traj.trajNode[j],
	////			traj.trajLifeSpan.start + j + 1, traj.trajNode[j+1]);
	////	}

	////}

	//vector<PCloudModel> totalModel;
	//nonrigid.sampleModel(totalTraj,totalModel,4000);
	////nonrigid.sampleModelByNeig(totalTraj,totalModel,2000);

	//vector<IndexType> labels;
	//labels.resize( totalTraj.size() );
	//J_LinkageAdapter<PCloudTraj, PCloudModel, Traj2ModDistanceFunc>	algo_adaptor(totalTraj, totalModel, labels, Traj2ModDistanceFunc(0.02));
	//algo_adaptor.compute();

	//Logger << "End Clustering.\n";

	////SampleSet& set  = SampleSet::get_instance();
	////LOCK( set[5] );
	////Sample& sample0 = set[5];
	////IndexType i = 0;
	////for (Sample::vtx_iterator v_iter = sample0.begin();
	////	v_iter != sample0.end();
	////	v_iter++,i++ )
	////{
	////	//(*v_iter)->set_label( labels.at<IndexType>(i) );
	////	(*v_iter)->set_label( labels[i]);
	////}

	////UNLOCK(set[5]);

	////Visualize
	//	Sample& smp0 = SampleSet::get_instance()[0];

	//int k=0;
	//for ( int i=0; i<smp0.num_vertices();i++ )
	//{
	//	if ( k<labels.size() && totalTraj[k].trajNode[0]== i )
	//	{
	//		smp0[ i ].set_visble(true);
	//		smp0[ i ].set_label( labels[k] );
	//		++k;
	//	}
	//	else
	//	{
	//		smp0[ i ].set_visble(false);
	//	}
	//}
	//for ( IndexType i=0; i < totalTraj.size(); ++i )
	//{
	//	IndexType color_idx = ( labels[i]*13 ) % 256;
	//	PCloudTraj& traj = totalTraj[i];
	//	IndexType traj_len_minus_one =  traj.trajNode.size() - 1;
	//	for ( IndexType j = 0; j < traj_len_minus_one; ++j )
	//	{
	//		tracer.add_record( traj.trajLifeSpan.start + j, traj.trajNode[j],
	//									traj.trajLifeSpan.start + j + 1, traj.trajNode[j+1],
	//									ColorType( Color_Utility::color_table[color_idx][0],
	//									Color_Utility::color_table[color_idx][1],
	//									Color_Utility::color_table[color_idx][2], 1.));
	//	}

	//}


}