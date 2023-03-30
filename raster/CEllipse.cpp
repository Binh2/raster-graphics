#include "pch.h"
#include "CEllipse.h"

void CEllipse::MidPointEllipse(CDC* pDC, int cx, int cy, int rx, int ry, COLORREF color) {
	// Bottom arc
	CEllipse::_MidPointArcSlowChange(pDC, cx, cy, rx, ry, -1, 1, color);
	CEllipse::_MidPointArcSlowChange(pDC, cx, cy, rx, ry, 1, 1, color);
	
	// Right arc
	CEllipse::_MidPointArcFastChange(pDC, cx, cy, rx, ry, 1, 1, color);
	CEllipse::_MidPointArcFastChange(pDC, cx, cy, rx, ry, 1, -1, color);

	// Top arc
	CEllipse::_MidPointArcSlowChange(pDC, cx, cy, rx, ry, 1, -1, color);
	CEllipse::_MidPointArcSlowChange(pDC, cx, cy, rx, ry, -1, -1, color);

	// Left arc
	CEllipse::_MidPointArcFastChange(pDC, cx, cy, rx, ry, -1, -1, color);
	CEllipse::_MidPointArcFastChange(pDC, cx, cy, rx, ry, -1, 1, color);
}

void CEllipse::_MidPointArcSlowChange(CDC* pDC, int cx, int cy, int rx, int ry, int xScalar, int yScalar, COLORREF color) {
	int a = rx, b = ry;
	int f = round(a * a / 4) + b * b - a * a * b;
	int x = 0, y = b;
	int M = b * b * (2 * x + 3), N = M + a * a * (-2 * y + 2);
	const int twoBSquared = 2 * b * b, twoASquared = 2 * a * a;
	int xEnd = round(a * a / sqrt(a * a + b * b));
	for (; x <= xEnd; x++) {
		if (f > 0) {
			y--;
			N += twoASquared;
		}
		M += twoBSquared;
		N += twoBSquared;
		pDC->SetPixel(cx + x * xScalar, cy + y * yScalar, color);
		f += (f < 0) ? M : N;
	}
}

void CEllipse::_MidPointArcFastChange(CDC* pDC, int cx, int cy, int rx, int ry, int xScalar, int yScalar, COLORREF color) {
	int a = rx, b = ry;
	int f = round(b * b / 4) + a * a - b * b * a;
	int x = a, y = 0;
	int M = a * a * (2 * y + 3), N = M + b * b * (-2 * x + 2);
	const int twoBSquared = 2 * b * b, twoASquared = 2 * a * a;
	int yEnd = round(b * b / sqrt(a * a + b * b));
	for (; y <= yEnd; y++) {
		if (f >= 0) {
			x--;
			N += twoBSquared;
		}
		M += twoASquared;
		N += twoASquared;
		pDC->SetPixel(cx + x * xScalar, cy + y * yScalar, color);
		f += (f < 0) ? M : N;
	}
}