#pragma once
#include <afxwin.h>

static class CLine {
public:
	static void DDALine(CDC*, int, int, int, int, COLORREF);
	static void BresenhamLine(CDC*, int, int, int, int, COLORREF);

private:
	static void _DDALineSlowChange(CDC*, int, int, int, int, COLORREF);
	static void _DDALineFastChange(CDC*, int, int, int, int, COLORREF);
	static void _BresenhamLineSlowChange(CDC*, int, int, int, int, COLORREF);
	static void _BresenhamLineFastChange(CDC*, int, int, int, int, COLORREF);
};