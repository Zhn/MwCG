#include "stdafx.h"
#include "AnchorDecorator.h"
#include "MwGLElement.h"
#include "MwPoint.h"

using namespace mw;

IMPLEMENT_DECORATOR_OP(GlElement, AnchorDecorator);

AnchorDecorator::AnchorDecorator(void) : hit_anchor_index_(-1)
{
	InitializeAnchor();
}


AnchorDecorator::~AnchorDecorator(void)
{
}

void mw::AnchorDecorator::DoDecorate()
{
	int anchor_count = decoratee()->anchor_count();

	for (int i = 0; i < anchor_count; i++)
	{
		Vector2 anchor_pos = decoratee()->anchor(i);
		//TODO: draw it.
		anchor_->set_position(anchor_pos);
		anchor_->Draw();
	}
}

void mw::AnchorDecorator::BeginInput( const Vector2& worldPos )
{
	//TODO: HitTest anchor point, begin move
	int new_hit_index = 0;
	for (new_hit_index = 0; new_hit_index < decoratee()->anchor_count(); new_hit_index++)
	{
		float dist = (decoratee()->anchor(new_hit_index) - worldPos).magnitude();
		//TODO: the anchor size
		if (dist < anchor_->size())
		{
			//Hit!
			break;
		}
	}
	//No hit
	if (new_hit_index == decoratee()->anchor_count())
	{
		new_hit_index = -1;
	}
	else
	{
		//TODO: begin preview operation
	}
	hit_anchor_index_ = new_hit_index;
}

void mw::AnchorDecorator::UpdateInput( const Vector2& worldPos )
{
	if (hit_anchor_index_ != -1)
	{
		//TODO: update preview
		Vector2 newPos = decoratee()->transform().WorldToLocal(worldPos);
		decoratee()->set_anchor(hit_anchor_index_, newPos);
	}
}

void mw::AnchorDecorator::EndInput( const Vector2& worldPos )
{
	if (hit_anchor_index_ != -1)
	{
		//TODO: commit operation
		hit_anchor_index_ = -1;
	}
}

void mw::AnchorDecorator::InitializeAnchor()
{
	anchor_.reset(new Point());
	anchor_->set_color(1, 0, 0);
	anchor_->set_size(10);
}