#include "pch.h"
#include "CCircle.h"

void CCircle::MidPointCircle(CDC* pDC, int cx, int cy, int r, COLORREF color) {
	// Bottom arc
	CCircle::_MidPointArcSlowChange(pDC, cx, cy, r, -1, 1, color);
	CCircle::_MidPointArcSlowChange(pDC, cx, cy, r, 1, 1, color);
	
	// Right arc
	CCircle::_MidPointArcFastChange(pDC, cx, cy, r, 1, 1, color);
	CCircle::_MidPointArcFastChange(pDC, cx, cy, r, 1, -1, color);

	// Top arc
	CCircle::_MidPointArcSlowChange(pDC, cx, cy, r, 1, -1, color);
	CCircle::_MidPointArcSlowChange(pDC, cx, cy, r, -1, -1, color);

	// Left arc
	CCircle::_MidPointArcFastChange(pDC, cx, cy, r, -1, -1, color);
	CCircle::_MidPointArcFastChange(pDC, cx, cy, r, -1, 1, color);
}

void CCircle::_MidPointArcSlowChange(CDC* pDC, int cx, int cy, int r, int xScalar, int yScalar, COLORREF color) {
	int f = 1 - r;
	int x = 0, y = r;
	int xEnd = round(r / sqrt(2));
	for (; x <= xEnd; x++) {
		if (f > 0) y--;
		pDC->SetPixel(cx + x * xScalar, cy + y * yScalar, color);
		f += (f <= 0) ? (2 * x + 3) : (2 * x - 2 * y + 5);
	}
}

void CCircle::_MidPointArcFastChange(CDC* pDC, int cx, int cy, int r, int xScalar, int yScalar, COLORREF color) {
	int f = 1 - r;
	int x = r, y = 0;
	int yEnd = round(r / sqrt(2));
	for (; y <= yEnd; y++) {
		if (f > 0) x--;
		pDC->SetPixel(cx + x * xScalar, cy + y * yScalar, color);
		f += (f <= 0) ? (2 * y + 3) : (2 * y - 2 * x + 5);
	}
}