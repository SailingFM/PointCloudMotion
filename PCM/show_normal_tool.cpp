#include "show_normal_tool.h"
#include "sample.h"
#include "sample_set.h"
#include "globals.h"
void ShowNormalTool::draw()
{
	Sample& cur_smp = SampleSet::get_instance()[ cur_sample_to_operate_ ];

	glColor4f(1.,0.,0.,1.);
	glLineWidth( 1. );
	glBegin( GL_LINES );
	ScalarType scale_factor = Paint_Param::g_point_size * 0.02;
	for ( IndexType i=0; i < cur_smp.num_vertices(); i++ )
	{
		Vertex& smp_vtx = cur_smp[ i ];
		Vec3 nv(smp_vtx.nx(), smp_vtx.ny(), smp_vtx.nz() );
		nv.normalize();
		Vec4 v1 = cur_smp.matrix_to_scene_coord() * Vec4( smp_vtx.x(), smp_vtx.y(), smp_vtx.z(), 1. );
		Vec4 v2 = Vec4( v1(0) + nv(0)*scale_factor , v1(1) + nv(1)*scale_factor,v1(2) + nv(2)*scale_factor , 1.);

		glVertex3f( v1(0), v1(1), v1(2) );
		glVertex3f( v2(0), v2(1), v2(2) );
	}
	glEnd();

	cur_smp.draw(ColorMode::ObjectColorMode());
}