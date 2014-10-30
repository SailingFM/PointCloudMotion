#ifndef _SHOW_NORMAL_TOOL_H
#define _SHOW_NORMAL_TOOL_H

#include "tool.h"
#include "basic_types.h"

class PaintCanvas;

class ShowNormalTool : public Tool
{

public:
	ShowNormalTool( PaintCanvas* canvas ):Tool(canvas)
	{

	}

	~ShowNormalTool(){}

	virtual void move(QMouseEvent *e){}
	virtual void drag(QMouseEvent *e){}
	virtual void release(QMouseEvent *e){}
	virtual void press(QMouseEvent* e){}
	virtual void draw();


};

#endif