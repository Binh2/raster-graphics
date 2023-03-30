#pragma once
#include <afxwin.h>
#include <vector>
class CFill {
public:
	static void BoundaryFill(CDC*, int, int, COLORREF, COLORREF);
	static void BoundaryFillEnhanced(CDC*, int, int, COLORREF, COLORREF);

	static void ScanLineFill(CDC*, const std::vector<int>&, const std::vector<int>&, COLORREF);
	//static void ScanLineFill(CDC*, int, int, COLORREF, COLORREF);
};
