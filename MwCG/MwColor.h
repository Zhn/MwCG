#pragma once
#include "mwx.h"
#define MwRGB(r, g, b) new MwColor(r, g, b)
#define MwRGBA(r, g, b, a) new MwColor(r, g, b, a)
#define MW_WHITE			1, 1, 1
#define MW_BLACK			0, 0, 0
#define MW_RED				1, 0, 0
#define MW_BLUE				0, 1, 0
#define MW_GREEN			0, 0, 1

class MwColor :
	public MwGLObject
{
	DECLARE_SERIAL(MwColor);
public:
	float r;
	float g;
	float b;
	float a;
public:
	void SetColorRef(COLORREF color);
	void SetColor(MwColor& color);
	void SetColor(float r, float g, float b, float a = 1.0);
	COLORREF GetColorRef();
public:
	MwColor(void);
	MwColor(float fr, float fg, float fb) 
		: r(fr), g(fg), b(fb), a(1.0) {};
	MwColor(float fr, float fg, float fb, float fa)  
		: r(fr), g(fg), b(fb), a(fa) {};
	~MwColor(void);
	inline void GL();
	inline void GL(bool clear);
	//void operator ()(bool clear) { GL(true); };
	void Serialize(CArchive& ar);
};

