#include "stdafx.h"
#include "MwGLContent.h"

using namespace mw;

IMPLEMENT_SERIAL(GlContent, GlElement, 1);

GlContent::GlContent(void)
{
	canvas_.reset(new Canvas());
	canvas_->set_color(MW_WHITE);
	screen_.reset(new GlScreen());

	mouse_.reset(new Point());
	mouse_->set_size(10);
	mouse_->set_color(1, 0, 0);
}


GlContent::~GlContent(void)
{
}


void GlContent::Serialize(CArchive& ar)
{
	//GlElement::Serialize(ar);

	canvas_->Serialize(ar);
}

void GlContent::Draw()
{
	//This function is called every time when updating a frame
	//Events should be coming before
	//Update screen
	screen_->GL();

	//Handle events
	HitTest();
	//TODO: keyboard

	//Canvas
	canvas_->Draw();

	//Contents
	for (UINT i = 0; i < Elements.size(); i++)
	{
		Elements.at(i)->Draw();
	}

	//Decorator & interaction layer
	mouse_->Draw();
}

bool GlContent::HitTest()
{
	//TODO: point of optimization

	for (UINT i = 0; i < Elements.size(); i++)
	{
		if (Elements.at(i)->HitTest())
			return true;
	}
	return false;
}

void GlContent::set_mouse(const CPoint& viewPoint) const
{
	//Translate to canvas coordinate system
	Vector2 xyPos = screen_->ScreenToXY(viewPoint.x, viewPoint.y);
	mouse_->set_position(xyPos);
}