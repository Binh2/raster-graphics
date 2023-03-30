#pragma once
#include <afxwin.h>

class CShape
{
public:
	static void Pentagon(CDC* pDC, int xc, int yc, int r, COLORREF color);
	static void Hexagon(CDC* pDC, int xc, int yc, int r, COLORREF color);

	static void Star(CDC* pDC, CPoint I, int R, COLORREF color, int n = 5);
	static void Star(CDC* pDC, int xc, int yc, int R, COLORREF color, int n = 5);
};
