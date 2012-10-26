#include "stdafx.h"
#include "MwGLContent.h"

IMPLEMENT_SERIAL(MwGLContent, CObject, 1)

MwGLContent::MwGLContent(void)
{
	m_pCanvas = new MwCanvas();
	m_pCanvas->Color.SetColor(MW_WHITE);
	Elements.push_back(MwElementSafePtr(m_pCanvas));
}


MwGLContent::~MwGLContent(void)
{
	delete m_pCanvas;
}


void MwGLContent::Serialize(CArchive& ar)
{
	CObject::Serialize(ar);

	if (ar.IsStoring())
	{	
		// storing code
		//int element_number = m_vElements.size();
		//ar<<element_number;
		//for (int i = 0; i < element_number; i++)
		//{
		//	ar<<m_vElements.at(i);
		//}
		ar<<m_pCanvas;
	}
	else
	{	
		// loading code
		//int element_number = 0;
		//ar>>element_number;
		//for (int i = 0; i < element_number; i++)
		//{
		//}
		ar>>m_pCanvas;
	}
}
