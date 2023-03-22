#pragma once
#include <afxwin.h>
class CCircle {
public:
	static void MidPointCircle(CDC*, int, int, int, COLORREF);

private:
	static void _MidPointArcSlowChange(CDC*, int, int, int, int, int, COLORREF);
	static void _MidPointArcFastChange(CDC*, int, int, int, int, int, COLORREF);
};