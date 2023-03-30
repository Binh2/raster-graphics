#pragma once
#include <afxwin.h>
class CEllipse {
public:
	static void MidPointEllipse(CDC*, int, int, int, int, COLORREF);

private:
	static void _MidPointArcSlowChange(CDC*, int, int, int, int, int, int, COLORREF);
	static void _MidPointArcFastChange(CDC*, int, int, int, int, int, int, COLORREF);
};