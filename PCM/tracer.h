#ifndef _TRACER_H
#define _TRACER_H

#include <vector>
#include <map>
#include "basic_types.h"
#include "sample_set.h"
#include "sample.h"
#include "vertex.h"
#include "globals.h"

using namespace std;

class Tracer
{
public:

	typedef pair<IndexType, IndexType>	Sample_Vertex_Index;


	static Tracer& get_instance()
	{
		static Tracer	instance;
		return instance;
	}

	void add_record( IndexType sample0_idx,
					IndexType sample0_vtx_idx,
					IndexType sample1_idx,
					IndexType sample1_vtx_idx)
	{
		head_.push_back( make_pair( sample0_idx, sample0_vtx_idx ) );
		tail_.push_back( make_pair(sample1_idx, sample1_vtx_idx) );
	}

	void clear_records()
	{
		head_.clear();
		tail_.clear();
	}

	void draw()
	{
		IndexType	num_record = head_.size();
		assert( num_record == tail_.size() );

		if (num_record==0)
		{
			return;
		}

		SampleSet&	set = SampleSet::get_instance();

		glColor4f(1.,0.,0.,1.);
		glLineWidth( Paint_Param::g_point_size );
		glBegin(GL_LINES);
		for ( IndexType i=0; i < num_record; i++ )
		{
			IndexType	sample0_idx = head_[i].first;
			IndexType	sample0_vtx_idx = head_[i].second;
			IndexType	sample1_idx = tail_[i].first;
			IndexType	sample1_vtx_idx = tail_[i].second;
			Vertex&		sample0_vtx = set[ sample0_idx ][ sample0_vtx_idx ];
			Vertex&		sample1_vtx = set[ sample1_idx ][ sample1_vtx_idx ];
			
			Vec4	first_v	= set[sample0_idx].matrix_to_scene_coord() *
				Vec4(sample0_vtx.x(), sample0_vtx.y(),sample0_vtx.z(),1.0);
			Vec4	second_v	= set[sample1_idx].matrix_to_scene_coord() *
				Vec4(sample1_vtx.x(), sample1_vtx.y(),sample1_vtx.z(),1.0);
			glVertex3f( first_v(0),first_v(1),first_v(2) + Paint_Param::g_step_size*sample0_idx );
			glVertex3f( second_v(0), second_v(1),second_v(2) + Paint_Param::g_step_size*sample1_idx );



		}
		glEnd();
	}

private:
	Tracer(){}
	~Tracer(){};
	Tracer( const Tracer&);
	void operator=(const Tracer&);

private:
	vector< Sample_Vertex_Index >		head_;
	vector< Sample_Vertex_Index >	tail_;

};

#endif