
// rasterView.cpp : implementation of the CrasterView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "raster.h"
#endif

#include "rasterDoc.h"
#include "rasterView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CrasterView

IMPLEMENT_DYNCREATE(CrasterView, CView)

BEGIN_MESSAGE_MAP(CrasterView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CrasterView construction/destruction

CrasterView::CrasterView() noexcept
{
	// TODO: add construction code here

}

CrasterView::~CrasterView()
{
}

BOOL CrasterView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CrasterView drawing
#include "CLine.h"
#include "CCircle.h"
#include "CEllipse.h"
#include "CFill.h"
#include "CShape.h"
void CrasterView::OnDraw(CDC* pDC)
{
	CrasterDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
	//int offsetX = 0, offsetY = 0;
	//CLine::DDALine(pDC, offsetX, offsetY, offsetX + 100, offsetY + 100, RGB(255, 0, 0));
	//CLine::DDALine(pDC, offsetX, offsetY, offsetX + 100, offsetY + 200, RGB(0, 255, 0));
	//CLine::DDALine(pDC, offsetX, offsetY, offsetX + 200, offsetY + 100, RGB(0, 0, 255));

	//// Draw DDA line in opposite direction than the previous 3
	//offsetY = 250;
	//CLine::DDALine(pDC, offsetX + 100, offsetY + 100, offsetX, offsetY, RGB(255, 255, 0));
	//CLine::DDALine(pDC, offsetX + 100, offsetY + 200, offsetX, offsetY, RGB(0, 255, 255));
	//CLine::DDALine(pDC, offsetX + 200, offsetY + 100, offsetX, offsetY, RGB(255, 0, 255));


	//offsetX = 250; offsetY = 0;
	//CLine::BresenhamLine(pDC, offsetX, offsetY, offsetX + 100, offsetY + 100, RGB(255, 0, 0));
	//CLine::BresenhamLine(pDC, offsetX, offsetY, offsetX + 100, offsetY + 200, RGB(0, 255, 0));
	//CLine::BresenhamLine(pDC, offsetX, offsetY, offsetX + 200, offsetY + 100, RGB(0, 0, 255));

	//// Draw Bresenham line in opposite direction than the previous 3
	//offsetY = 250;
	//CLine::BresenhamLine(pDC, offsetX + 100, offsetY + 100, offsetX, offsetY, RGB(255, 255, 0));
	//CLine::BresenhamLine(pDC, offsetX + 100, offsetY + 200, offsetX, offsetY, RGB(0, 255, 255));
	//CLine::BresenhamLine(pDC, offsetX + 200, offsetY + 100, offsetX, offsetY, RGB(255, 0, 255));


	//CCircle::MidPointCircle(pDC, 100, 100, 50, RGB(255, 0, 0));
	//CCircle::MidPointCircle(pDC, 200, 100, 100, RGB(0, 255, 0));
	//CCircle::MidPointCircle(pDC, 200, 200, 200, RGB(0, 0, 255));

	/*CEllipse::MidPointEllipse(pDC, 100, 100, 100, 50, RGB(255, 0, 0));*/
	CEllipse::MidPointEllipse(pDC, 100, 100, 100, 100, RGB(0, 255, 0));
	//CFill::BoundaryFill(pDC, 200, 100, RGB(0, 255, 0), RGB(255, 0, 0));
	//CFill::BoundaryFillEnhanced(pDC, 100, 100, RGB(0, 255, 0), RGB(255, 0, 0));
	CFill::ScanLineFill(pDC, std::vector<int>{100, 200, 300}, std::vector<int>{200, 300, 100}, RGB(255, 0, 0));
	/*CEllipse::MidPointEllipse(pDC, 200, 200, 50, 100, RGB(0, 0, 255));*/
	
	//CShape::Hexagon(pDC, 100, 100, 50, RGB(255, 0, 0));
	//CShape::Pentagon(pDC, 200, 100, 50, RGB(0, 255, 0));
	//CShape::Star(pDC, 100, 200, 50, RGB(0, 0, 255));
}


// CrasterView printing

BOOL CrasterView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CrasterView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CrasterView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CrasterView diagnostics

#ifdef _DEBUG
void CrasterView::AssertValid() const
{
	CView::AssertValid();
}

void CrasterView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CrasterDoc* CrasterView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CrasterDoc)));
	return (CrasterDoc*)m_pDocument;
}
#endif //_DEBUG


// CrasterView message handlers
