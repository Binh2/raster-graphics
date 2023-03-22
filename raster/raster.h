
// raster.h : main header file for the raster application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols


// CrasterApp:
// See raster.cpp for the implementation of this class
//

class CrasterApp : public CWinApp
{
public:
	CrasterApp() noexcept;


// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CrasterApp theApp;
