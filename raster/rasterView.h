
// rasterView.h : interface of the CrasterView class
//

#pragma once


class CrasterView : public CView
{
protected: // create from serialization only
	CrasterView() noexcept;
	DECLARE_DYNCREATE(CrasterView)

// Attributes
public:
	CrasterDoc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CrasterView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in rasterView.cpp
inline CrasterDoc* CrasterView::GetDocument() const
   { return reinterpret_cast<CrasterDoc*>(m_pDocument); }
#endif

