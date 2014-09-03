#include "file_io.h"
#include "basic_types.h"
#include "sample_set.h"
#include <stdio.h>

namespace FileIO
{
	Sample* load_point_cloud_file( std::string filename, FILE_TYPE type, IndexType sample_idx )
	{
		FILE* in_file = fopen(filename.c_str(), "r");

		if(in_file==NULL)
			return nullptr;

		Sample* new_sample = new Sample;
//		ScalarType vx0,vy0,vz0;
// 		bool first_vertex = true;
		while ( true )
		{

			ScalarType vx,vy,vz,nx,ny,nz,cx,cy,cz;
			int status = fscanf(in_file, "%f %f %f %f %f %f %f %f %f\n",&vx,&vy,&vz,
				&nx,&ny,&nz,
				&cx,&cy,&cz);
			if(status==EOF)break;
// 			if ( first_vertex )
// 			{
// 				vx0 = vx,vy0 = vy, vz0 = vz;
// 				PointType v(0.,0.,0.);
// 				ColorType cv(cx/255.,cy/255.,cz/255.,1.);
// 				NormalType nv(nx,ny,nz);
// 				new_sample->add_vertex(v, nv, cv);
// 				first_vertex = false;
// 				continue;
// 			}
// 			PointType v(vx - vx0,vy - vy0,vz - vz0);
			PointType v(vx,vy,vz);
			ColorType cv(cx/255.,cy/255.,cz/255.,1.);
			NormalType nv(nx,ny,nz);

			new_sample->add_vertex(v, nv, cv);
		

		}

		//give the new sample a color
		new_sample->set_visble(false);
		new_sample->set_color( Color_Utility::span_color_from_table( sample_idx ) );
		new_sample->build_kdtree();
		return new_sample;

	}

	void save_point_cloud_to_file(  std::string filename_prefix, FILE_TYPE type  )
	{
		SampleSet& set = SampleSet::get_instance();
		char filename[FILENAME_MAX];
		for (IndexType s_idx=0; s_idx<set.size(); s_idx++)
		{
			sprintf(filename, "%s%d.xyz", filename_prefix.c_str(), s_idx);
			FILE* out_file = fopen( filename, "w" );
			if (out_file==NULL)
			{
				Logger << "write "<<filename<<" error.\n"; 
				return;
			}
			for (IndexType v_idx=0; v_idx<set[s_idx].num_vertices(); v_idx++)
			{
				Vertex& v = set[s_idx][v_idx];

				fprintf( out_file, "%f %f %f %f %f %f %f %f %f\n", v.x(), v.y(),v.z(),
								v.nx(), v.ny(),v.nz(),
								v.r(), v.g(), v.b() );
			}
			fclose( out_file );
		}

		Logger << "finished write files.\n";
	}
}