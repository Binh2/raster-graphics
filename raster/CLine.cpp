#include "pch.h"
#include "CLine.h"

void CLine::DDALine(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) {
	float slope = (y2 - y1) * 1.0f / (x2 - x1);
	if (abs(slope) < 1)
		if (x1 < x2) CLine::_DDALineSlowChange(pDC, x1, y1, x2, y2, color);
		else CLine::_DDALineSlowChange(pDC, x2, y2, x1, y1, color);
	else 
		if (y1 < y2) CLine::_DDALineFastChange(pDC, x1, y1, x2, y2, color);
		else CLine::_DDALineFastChange(pDC, x2, y2, x1, y1, color);
}

void CLine::BresenhamLine(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) {
	float slope = (y2 - y1) * 1.0f / (x2 - x1);
	if (abs(slope) < 1)
		if (x1 < x2) CLine::_BresenhamLineSlowChange(pDC, x1, y1, x2, y2, color);
		else CLine::_BresenhamLineSlowChange(pDC, x2, y2, x1, y1, color);
	else
		if (y1 < y2) CLine::_BresenhamLineFastChange(pDC, x1, y1, x2, y2, color);
		else CLine::_BresenhamLineFastChange(pDC, x2, y2, x1, y1, color);
}

void CLine::_DDALineSlowChange(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) {
	float slope = (y2 - y1) * 1.0f / (x2 - x1);
	float y = y1;
	for (int x = x1; x <= x2; x++) {
		pDC->SetPixel(x, round(y), color);
		y += slope;
	}
}

void CLine::_DDALineFastChange(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) {
	float inverseSlope = (x2 - x1) * 1.0 / (y2 - y1);
	float x = x1;
	for (int y = y1; y <= y2; y++) {
		pDC->SetPixel(round(x), y, color);
		x += inverseSlope;
	}
}

void CLine::_BresenhamLineSlowChange(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) {
	int dx = x2 - x1, dy = y2 - y1;
	int p = 2 * dy - dx;
	int y = y1;
	for (int x = x1; x <= x2; x++) {
		if (p >= 0) y++;
		pDC->SetPixel(x, y, color);
		p += (p < 0) ? (2 * dy) : (2 * dy - 2 * dx);
	}
}

void CLine::_BresenhamLineFastChange(CDC* pDC, int x1, int y1, int x2, int y2, COLORREF color) {
	int dx = x2 - x1, dy = y2 - y1;
	int p = 2 * dx - dy;
	int x = x1;
	for (int y = y1; y <= y2; y++) {
		if (p >= 0) x++;
		pDC->SetPixel(x, y, color);
		p += (p < 0) ? (2 * dx) : (2 * dx - 2 * dy);
	}
}