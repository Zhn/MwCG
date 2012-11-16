#include "stdafx.h"
#include "PointTool.h"

#include "AddElementToContent.h"
#include "MwPoint.h"
#include "PointDecorator.h"

using namespace mw;

PointTool::PointTool(void) : isFinished_(false)
{
	decorator_.reset(new PointDecorator());
}


PointTool::~PointTool(void)
{
}

mw::OperationPtr mw::PointTool::PopNewOperation()
{
	point_ -= decorator_;
	return OperationPtr(new AddElementToContent(content(), point_));
}

void mw::PointTool::DoUpdateInput()
{
	point_->set_hidden(false);
	point_->set_position(current());
}

void mw::PointTool::Draw()
{
	point_->Draw();
}

void mw::PointTool::DoNew()
{
	point_.reset(new Point());
	point_->set_hidden(true);
	point_->set_size(5);
	point_ += decorator_;
	isFinished_ = false;
}

void mw::PointTool::DoNextInput()
{
	isFinished_ = true;
}

void mw::PointTool::DoFixInput()
{
	point_->set_position(current());
}

bool mw::PointTool::IsFinished() const
{
	return isFinished_;
}
