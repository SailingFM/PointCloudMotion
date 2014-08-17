#ifndef _GLOBALS_H
#define _GLOBALS_H
#include "basic_types.h"
#include <QMutex>



#define HELLO

namespace Paint_Param
{
	extern ScalarType	g_point_size;
	extern	ScalarType	g_step_size;
}

#define		LOCK(x)		x.lock()
#define		UNLOCK(x)	x.unlock()

#endif