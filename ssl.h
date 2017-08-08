// ssl.h : main header file for the SSL application
//

#if !defined(AFX_SSL_H__3548E730_A5FC_424A_86AF_A3BE35398A0E__INCLUDED_)
#define AFX_SSL_H__3548E730_A5FC_424A_86AF_A3BE35398A0E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSslApp:
// See ssl.cpp for the implementation of this class
//

class CSslApp : public CWinApp
{
public:
	CSslApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSslApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSslApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSL_H__3548E730_A5FC_424A_86AF_A3BE35398A0E__INCLUDED_)
