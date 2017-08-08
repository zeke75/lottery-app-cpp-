// sslDlg.h : header file
//

#if !defined(AFX_SSLDLG_H__222C07CF_0040_46EF_9C16_C6BE31ACDBCC__INCLUDED_)
#define AFX_SSLDLG_H__222C07CF_0040_46EF_9C16_C6BE31ACDBCC__INCLUDED_

#include <iostream.h>
#include <fstream.h>


#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSslDlg dialog

class CSslDlg : public CDialog
{
// Construction
public:
	CString GetLNum(const int & style, const int &zs);


	int people_per_30_minutes();
	void kaijiang();
	int haomageshu();
	int zhushu();
	void int_to_str(int num, char *str);
	
	int str_to_int(char str[]);

	int a;
	int bh,bh0;
	void zhongjiang(int qihao);
	void cxgm(int qihao);
	void cxzj();
	int simul_one_person();
	int simul_one_issue(char* date,int qihao);
	int simul_one_day(char* date);
	void simul_one_month();




CStatusBar m_status;
 
	void change(bool i,bool j,bool k);

	//int str_to_int(char str[]);
	CSslDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSslDlg)
	enum { IDD = IDD_SSL_DIALOG };
	CListCtrl	m_list;
	CDateTimeCtrl	m_date;
	BOOL	m_a1;
	BOOL	m_a10;
	BOOL	m_a2;
	BOOL	m_a3;
	BOOL	m_a5;
	BOOL	m_a4;
	BOOL	m_a6;
	BOOL	m_a7;
	BOOL	m_a9;
	BOOL	m_a8;
	BOOL	m_b2;
	BOOL	m_b10;
	BOOL	m_b1;
	BOOL	m_b8;
	BOOL	m_b6;
	BOOL	m_b4;
	BOOL	m_b3;
	BOOL	m_b5;
	BOOL	m_b7;
	BOOL	m_b9;
	BOOL	m_c10;
	BOOL	m_c9;
	BOOL	m_c8;
	BOOL	m_c6;
	BOOL	m_c7;
	BOOL	m_c5;
	BOOL	m_c4;
	BOOL	m_c3;
	BOOL	m_c2;
	BOOL	m_c1;
	int		m_qishu;
	int		m_beishu;
	int		m_xuanfa;
	COleDateTime	m_date2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSslDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSslDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnDestroy();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnReset();
	afx_msg void Onzhix();
	afx_msg void Onzx6();
	afx_msg void Onzx3();
	afx_msg void Onq2();
	afx_msg void Onh2();
	afx_msg void Onq1();
	afx_msg void Onh1();
	afx_msg void OnQueren();
	afx_msg void OnMENUabout();
	afx_msg void OnTouzhu();
	afx_msg void OnDelete();
	afx_msg void OnQinkong();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void Onsimul_one_issue();
	afx_msg void Onsimul_one_day();
	afx_msg void Onsimul_one_month();
	afx_msg void Oncxzj();
	afx_msg void Oncx();
	afx_msg void OnClose();
	afx_msg void OnJxyz();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SSLDLG_H__222C07CF_0040_46EF_9C16_C6BE31ACDBCC__INCLUDED_)
