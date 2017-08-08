// sslDlg.cpp : implementation file
//

#include <iostream.h>
#include <fstream.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <cstring>
#include <window.h>
#include "stdafx.h"
#include "ssl.h"
#include "sslDlg.h"
#include "string.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSslDlg dialog

CSslDlg::CSslDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSslDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSslDlg)
	m_a1 = FALSE;
	m_a10 = FALSE;
	m_a2 = FALSE;
	m_a3 = FALSE;
	m_a5 = FALSE;
	m_a4 = FALSE;
	m_a6 = FALSE;
	m_a7 = FALSE;
	m_a9 = FALSE;
	m_a8 = FALSE;
	m_b2 = FALSE;
	m_b10 = FALSE;
	m_b1 = FALSE;
	m_b8 = FALSE;
	m_b6 = FALSE;
	m_b4 = FALSE;
	m_b3 = FALSE;
	m_b5 = FALSE;
	m_b7 = FALSE;
	m_b9 = FALSE;
	m_c10 = FALSE;
	m_c9 = FALSE;
	m_c8 = FALSE;
	m_c6 = FALSE;
	m_c7 = FALSE;
	m_c5 = FALSE;
	m_c4 = FALSE;
	m_c3 = FALSE;
	m_c2 = FALSE;
	m_c1 = FALSE;
	m_qishu = 0;
	m_beishu = 1;
	m_xuanfa = 0;
	m_date2 = COleDateTime::GetCurrentTime();
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSslDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSslDlg)
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_date);
	DDX_Check(pDX, IDC_A1, m_a1);
	DDX_Check(pDX, IDC_A10, m_a10);
	DDX_Check(pDX, IDC_A2, m_a2);
	DDX_Check(pDX, IDC_A3, m_a3);
	DDX_Check(pDX, IDC_A5, m_a5);
	DDX_Check(pDX, IDC_A4, m_a4);
	DDX_Check(pDX, IDC_A6, m_a6);
	DDX_Check(pDX, IDC_A7, m_a7);
	DDX_Check(pDX, IDC_A9, m_a9);
	DDX_Check(pDX, IDC_A8, m_a8);
	DDX_Check(pDX, IDC_B2, m_b2);
	DDX_Check(pDX, IDC_B10, m_b10);
	DDX_Check(pDX, IDC_B1, m_b1);
	DDX_Check(pDX, IDC_B8, m_b8);
	DDX_Check(pDX, IDC_B6, m_b6);
	DDX_Check(pDX, IDC_B4, m_b4);
	DDX_Check(pDX, IDC_B3, m_b3);
	DDX_Check(pDX, IDC_B5, m_b5);
	DDX_Check(pDX, IDC_B7, m_b7);
	DDX_Check(pDX, IDC_B9, m_b9);
	DDX_Check(pDX, IDC_C10, m_c10);
	DDX_Check(pDX, IDC_C9, m_c9);
	DDX_Check(pDX, IDC_C8, m_c8);
	DDX_Check(pDX, IDC_C6, m_c6);
	DDX_Check(pDX, IDC_C7, m_c7);
	DDX_Check(pDX, IDC_C5, m_c5);
	DDX_Check(pDX, IDC_C4, m_c4);
	DDX_Check(pDX, IDC_C3, m_c3);
	DDX_Check(pDX, IDC_C2, m_c2);
	DDX_Check(pDX, IDC_C1, m_c1);
	DDX_CBIndex(pDX, IDC_Qishu, m_qishu);
	DDX_Text(pDX, IDC_EDIT1, m_beishu);
	DDV_MinMaxInt(pDX, m_beishu, 1, 50);
	DDX_Radio(pDX, IDC_zhix, m_xuanfa);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_date2);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSslDlg, CDialog)
	//{{AFX_MSG_MAP(CSslDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_DESTROY()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Reset, OnReset)
	ON_BN_CLICKED(IDC_zhix, Onzhix)
	ON_BN_CLICKED(IDC_zx6, Onzx6)
	ON_BN_CLICKED(IDC_zx3, Onzx3)
	ON_BN_CLICKED(IDC_q2, Onq2)
	ON_BN_CLICKED(IDC_h2, Onh2)
	ON_BN_CLICKED(IDC_q1, Onq1)
	ON_BN_CLICKED(IDC_h1, Onh1)
	ON_BN_CLICKED(IDC_BUTTON3, OnQueren)
	ON_COMMAND(ID_MENUabout, OnMENUabout)
	ON_BN_CLICKED(IDC_BUTTON1, OnTouzhu)
	ON_BN_CLICKED(IDC_BUTTON4, OnDelete)
	ON_BN_CLICKED(IDC_BUTTON5, OnQinkong)
	ON_WM_TIMER()
	ON_COMMAND(ID_simul_one_issue, Onsimul_one_issue)
	ON_COMMAND(ID_simul_one_day, Onsimul_one_day)
	ON_COMMAND(ID_simul_one_month, Onsimul_one_month)
	ON_COMMAND(ID_cxzj, Oncxzj)
	ON_BN_CLICKED(IDC_cx, Oncx)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_JXYZ, OnJxyz)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSslDlg message handlers

BOOL CSslDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	CString	m_today=CTime::GetCurrentTime().Format("%Y年%m月%d日");
	CString m_time=CTime::GetCurrentTime().Format("%H:%M:%S");

	// TODO: Add extra initialization here

	//状态栏
	BOOL m_iscreated;
	m_iscreated=m_status.Create(this);
	UINT i[3];
	for(int j=0;j<3;j++) i[j]=50+j;
	m_status.SetIndicators(i,3);
	CRect rect;
	GetClientRect(rect);
	UINT pw=rect.Width()/3;
	for(int n=0;n<3;n++) m_status.SetPaneInfo(n,50+n*10,SBPS_NORMAL,pw);

	
	m_status.SetPaneText(0,"时时乐欢迎您---祝您中奖！");
    m_status.SetPaneText(1,m_today);
	m_status.SetPaneText(2,m_time);

	RepositionBars(AFX_IDW_CONTROLBAR_FIRST,AFX_IDW_CONTROLBAR_LAST,0);
	this->Invalidate();

	SetTimer(100,1000,NULL);//


	// 设定日起范围
	COleDateTime dtMin(2007,12,1,0,0,0);
	COleDateTime dtMax(2007,12,31,0,0,0);
	m_date.SetRange(&dtMin,&dtMax);

    m_date.SetFormat("yy'-'MM'-'dd");
    m_list.InsertColumn(0,"投注方式",LVCFMT_CENTER,70);
    m_list.InsertColumn(1,"号码",LVCFMT_CENTER,60);
	m_list.InsertColumn(2,"注数",LVCFMT_CENTER,60);

	//模拟初始化
	srand(time(NULL));
	int init=simul_one_person();
	ifstream in1;
	bh=0;
	in1.open("last.log",ios::in);
	
	in1 >> bh;
	
	in1.close();
	

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSslDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

void CSslDlg::OnDestroy()
{
	WinHelp(0L, HELP_QUIT);
	CDialog::OnDestroy();
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSslDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSslDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CSslDlg::OnReset() 
{
    m_a1=false;	m_a2=false;	m_a3=false;	m_a4=false; m_a5=false;	
	m_a6=false;	m_a7=false;	m_a8=false;	m_a9=false;	m_a10=false;	
	m_b1=false;	m_b2=false;	m_b3=false;	m_b4=false; m_b5=false;	
	m_b6=false;	m_b7=false;	m_b8=false;	m_b9=false; m_b10=false;	
	m_c1=false;	m_c2=false;	m_c3=false;	m_c4=false; m_c5=false;	
	m_c6=false;	m_c7=false;	m_c8=false;	m_c9=false;	m_c10=false;	
    UpdateData(FALSE);
}

void CSslDlg::change(bool i, bool j, bool k)
{
		GetDlgItem(IDC_A10)->EnableWindow(i);
		GetDlgItem(IDC_A1)->EnableWindow(i);
		GetDlgItem(IDC_A2)->EnableWindow(i);
		GetDlgItem(IDC_A3)->EnableWindow(i);
		GetDlgItem(IDC_A4)->EnableWindow(i);
		GetDlgItem(IDC_A5)->EnableWindow(i);
		GetDlgItem(IDC_A6)->EnableWindow(i);
		GetDlgItem(IDC_A7)->EnableWindow(i);
		GetDlgItem(IDC_A8)->EnableWindow(i);
		GetDlgItem(IDC_A9)->EnableWindow(i);
		GetDlgItem(IDC_B10)->EnableWindow(j);
		GetDlgItem(IDC_B1)->EnableWindow(j);
		GetDlgItem(IDC_B2)->EnableWindow(j);
		GetDlgItem(IDC_B3)->EnableWindow(j);
		GetDlgItem(IDC_B4)->EnableWindow(j);
		GetDlgItem(IDC_B5)->EnableWindow(j);
		GetDlgItem(IDC_B6)->EnableWindow(j);
		GetDlgItem(IDC_B7)->EnableWindow(j);
		GetDlgItem(IDC_B8)->EnableWindow(j);
		GetDlgItem(IDC_B9)->EnableWindow(j);
		GetDlgItem(IDC_C10)->EnableWindow(k);
		GetDlgItem(IDC_C1)->EnableWindow(k);
		GetDlgItem(IDC_C2)->EnableWindow(k);
		GetDlgItem(IDC_C3)->EnableWindow(k);
		GetDlgItem(IDC_C4)->EnableWindow(k);
		GetDlgItem(IDC_C5)->EnableWindow(k);
		GetDlgItem(IDC_C6)->EnableWindow(k);
		GetDlgItem(IDC_C7)->EnableWindow(k);
		GetDlgItem(IDC_C8)->EnableWindow(k);
		GetDlgItem(IDC_C9)->EnableWindow(k);
}

void CSslDlg::Onzhix() 
{
	// TODO: Add your control notification handler code here
	change(true,true,true);
}

void CSslDlg::Onzx6() 
{
	change(true,true,true);
}

void CSslDlg::Onzx3() 
{
	change(true,true,true);
}

void CSslDlg::Onq2() 
{
	change(true,true,false);
}

void CSslDlg::Onh2() 
{
	change(false,true,true);
}

void CSslDlg::Onq1() 
{
	change(true,false,false);
}

void CSslDlg::Onh1() 
{
	change(false,false,true);
}

void CSslDlg::OnQueren() 
{
	
    UpdateData(TRUE);
	int a[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
        b[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1},
		c[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
    if(m_a1) a[1]=1;   if(m_a2) a[2]=2;   if(m_a3) a[3]=3;   if(m_a4) a[4]=4;   if(m_a5) a[5]=5; 
	if(m_a6) a[6]=6;   if(m_a7) a[7]=7;   if(m_a8) a[8]=8;   if(m_a9) a[9]=9;   if(m_a10) a[0]=0;
	if(m_b1) b[1]=1;   if(m_b2) b[2]=2;   if(m_b3) b[3]=3;   if(m_b4) b[4]=4;   if(m_b5) b[5]=5;
	if(m_b6) b[6]=6;   if(m_b7) b[7]=7;   if(m_b8) b[8]=8;   if(m_b9) b[9]=9;   if(m_b10) b[0]=0;
	if(m_c1) c[1]=1;   if(m_c2) c[2]=2;   if(m_c3) c[3]=3;   if(m_c4) c[4]=4;   if(m_c5) c[5]=5;
	if(m_c6) c[6]=6;   if(m_c7) c[7]=7;   if(m_c8) c[8]=8;   if(m_c9) c[9]=9;   if(m_c10) c[0]=0;


	
	
    char str[5],temp[4];
	CString zs;
	bool cc=false;
	int i,j,k,n;
	if (m_beishu>=1 && m_beishu<=50)
	{
		if (m_xuanfa==0)
		{	for (i=0;i<=9;i++)
				for (j=0;j<=9;j++)
					for (k=0;k<=9;k++)
					{
						if (a[i]!=-1 && b[j]!=-1 && c[k]!=-1)
						{
							strcpy(str,"直选");
							temp[0]='0'+i;
							temp[1]='0'+j;
							temp[2]='0'+k;
							temp[3]='\0';
							zs.Format("%d",m_beishu);
							n=m_list.InsertItem(0,str); 
							m_list.SetItemText(n,1,temp);
							m_list.SetItemText(n,2,zs);
							cc=true;
						}
					}
			if (!cc) MessageBox("没有被添加到号码组中！",MB_OK,MB_ICONINFORMATION);
		}
		
		if (m_xuanfa==1)
		{
			for (i=0;i<=9;i++)
				for (j=0;j<=9;j++)
					for (k=0;k<=9;k++)
					{
						if (a[i]!=-1 && b[j]!=-1 && c[k]!=-1 && i!=j && j!=k && k!=i)
						{
							strcpy(str,"组六");
							temp[0]='0'+i;
							temp[1]='0'+j;
							temp[2]='0'+k;
							temp[3]='\0';
							zs.Format("%d",m_beishu);
							n=m_list.InsertItem(0,str);
							m_list.SetItemText(n,1,temp);
							m_list.SetItemText(n,2,zs);
							cc=true;
						}
					}
			if (!cc) MessageBox("号码格式不对，没有被添加到号码组中！\n组六:百十个位至少选一个数字，且三个都不同。比如:123。",MB_OK,MB_ICONINFORMATION);
		}
			
		if (m_xuanfa==2)
		{
			for (i=0;i<=9;i++)
				for (j=0;j<=9;j++)
					for (k=0;k<=9;k++)
					{
						if (a[i]!=-1 && b[j]!=-1 && c[k]!=-1 
							&& ((i==j && j!=k ) || (i==k && i!=j) || (j==k && j!=i))) 
						{
							strcpy(str,"组三");
							temp[0]='0'+i;
							temp[1]='0'+j;
							temp[2]='0'+k;
							temp[3]='\0';
							zs.Format("%d",m_beishu);
							n=m_list.InsertItem(0,str); 
							m_list.SetItemText(n,1,temp);
							m_list.SetItemText(n,2,zs);
							cc=true;
						}
					}
			 if (!cc) MessageBox("号码格式不对，没有被添加到号码组中！\n组三:需要两个位置号码相同。比如:112。",MB_OK,MB_ICONINFORMATION);
		}
    
		if (m_xuanfa==3)
		{
			for (i=0;i<=9;i++)	
			{
				for (j=0;j<=9;j++)
				{
					if (a[i]!=-1 && b[j]!=-1)
					{
						strcpy(str,"前二");
						temp[0]='0'+i;
						temp[1]='0'+j;
						temp[2]='#';
						temp[3]='\0';
						zs.Format("%d",m_beishu);
						n=m_list.InsertItem(0,str); 
						m_list.SetItemText(n,1,temp);
						m_list.SetItemText(n,2,zs);
						cc=true;
					}
				}
			}
			if (!cc) MessageBox("号码格式不对，没有被添加到号码组中！",MB_OK,MB_ICONINFORMATION);
		}
		
		if (m_xuanfa==4)
		{
			for (j=0;j<=9;j++)
			{	
				for (k=0;k<=9;k++)
				{
					if (b[j]!=-1 && c[k]!=-1)
					{
						strcpy(str,"后二");
						temp[0]='#';
						temp[1]='0'+j;
						temp[2]='0'+k;
						temp[3]='\0';
						zs.Format("%d",m_beishu);
						n=m_list.InsertItem(0,str); 
						m_list.SetItemText(n,1,temp);
						m_list.SetItemText(n,2,zs);
						cc=true;
					}
				}
			}
			if (!cc) MessageBox("号码格式不对，没有被添加到号码组中！",MB_OK,MB_ICONINFORMATION);
		}

		if (m_xuanfa==5)
		{
			for (i=0;i<=9;i++)
			{
				if (a[i]!=-1) 
				{
					strcpy(str,"前一");
					temp[0]='0'+i;
					temp[1]='#';
					temp[2]='#';
					temp[3]='\0';
					zs.Format("%d",m_beishu);
					n=m_list.InsertItem(0,str);
					m_list.SetItemText(n,1,temp);
					m_list.SetItemText(n,2,zs);
					cc=true;
				}
			}
			if (!cc) MessageBox("请选择号码！",MB_OK,MB_ICONINFORMATION);
		}
			
		if (m_xuanfa==6)
		{
			for (int i=0;i<=9;i++)
			{
				if (c[i]!=-1) 
				{
					strcpy(str,"后一");
					temp[0]='#';
					temp[1]='#';
					temp[2]='0'+i;
					temp[3]='\0';
					zs.Format("%d",m_beishu);
					n=m_list.InsertItem(0,str);
					m_list.SetItemText(n,1,temp);
					m_list.SetItemText(n,2,zs);
					cc=true;
				}
			}
			if (!cc) MessageBox("请选择号码！",MB_OK,MB_ICONINFORMATION);
		}

		
			
		UpdateData(FALSE);
	}
}

void CSslDlg::OnDelete() 
{
	int i=m_list.GetNextItem(-1,LVNI_ALL | LVNI_SELECTED);
	m_list.DeleteItem(i);
}

void CSslDlg::OnQinkong() 
{
	m_list.DeleteAllItems();
}

void CSslDlg::OnMENUabout() 
{
	// TODO: Add your command handler code here
	CAboutDlg d;
	d.DoModal();
}


void CSslDlg::OnTouzhu() 
{
	UpdateData(TRUE);
	int i=m_list.GetNextItem(-1,LVNI_ALL | LVNI_SELECTED);
	int zzs=0;
	COleDateTime now;
	now=COleDateTime::GetCurrentTime();
	bool t=true;
//	m_qishu
	int nowqi=(now.GetHour()-10)*2+1+now.GetMinute()/30;
	if ((now.GetDay()>m_date2.GetDay())
	|| ((now.GetDay()==m_date2.GetDay())&&(nowqi>m_qishu)))
//	||(((now.GetDay()==m_date2.GetDay())&&(now.GetHour()==m_date2.GetHour()))&&(now.GetMinute()>m_date2.GetMinute()))
//	||((((now.GetDay()==m_date2.GetDay())&&(now.GetHour()==m_date2.GetHour()))&&(now.GetMinute()==m_date2.GetMinute()))&&(now.GetSecond()>m_date2.GetSecond())))
	{
		MessageBox("您选择的期号已开奖!",MB_OK,MB_ICONINFORMATION);
		t=false;
	}
 	if (((now.GetMinute()>=25)&&(now.GetMinute()<=30))||(now.GetMinute()>=55))
	{
		MessageBox("现在不能购买彩票!",MB_OK,MB_ICONINFORMATION);
		t=false;
	}
	if (t==true)
	{ 
		CString cp,str,qihao,money,xuanfa,cpbh;
	    for (i=0;i<m_list.GetItemCount();i++)
		{
			str=m_list.GetItemText(i,2);
			zzs+=atoi(str);
			int zs=atoi(m_list.GetItemText(i,2));
			CString xx;
			if (zs<10)
				xx="0"+m_list.GetItemText(i,2);
			else 
				xx=m_list.GetItemText(i,2);
			xuanfa+=m_list.GetItemText(i,0)+"---"+m_list.GetItemText(i,1)+"---"+
				    xx+"注"+"\n";
		}	
		
		qihao.Format("%d%d%02d%02d",m_date2.GetYear(),m_date2.GetMonth(),m_date2.GetDay(),m_qishu+1);
		money.Format("\n金额:共%d注,需%d元.",zzs,zzs*2);
		cpbh.Format("%s%d",qihao,1000+bh);
		
		cp="您的彩票\n期号:"+qihao+"\n彩票编号:"+cpbh+"\n\n"+xuanfa+money;
	
		if (zzs!=0) 
		{
			MessageBox(cp,MB_OK);
			bh++;
		}
		else MessageBox("请确认号码！",MB_OK,MB_ICONASTERISK);
	
	    
			
		UpdateData(FALSE);
	
	
		char date[30];
		char yy[5],mm[3],dd[3];
		int_to_str(m_date2.GetYear(),yy);
		int_to_str(m_date2.GetMonth(),mm);
		int_to_str(m_date2.GetDay(),dd);
	
		strcpy(date,yy);
		strcat(date,mm);
		if((m_date2.GetDay())<10)
			strcat(date,"0");
		strcat(date,dd);
		int qi_hao;
		qi_hao=m_qishu+1;
		char qh[3];
		int_to_str(qi_hao,qh);
			
		if (qi_hao<10)
		{	
			char zero[3];
			strcpy(zero,"0");
			strcat(zero,qh);
			strcpy(qh,zero);
		}
		char filename[40];
	
	//	strcpy(filename,"");
		strcpy(filename,date);
		strcat(filename,qh);
		strcat(filename,".txt");
		//cout << filename <<endl;

	
		char touzhu[40];
		touzhu[0]='\0';
		ofstream out1;
		ifstream in1;
		out1.open("temp.log",ios::out);
	
			out1 << xuanfa;
	
	
		out1.close();
		in1.open("temp.log",ios::in);
		FILE *fp=fopen(filename,"a");
			//fputc('\n',fp);
			fprintf(fp,"%s",cpbh);
			fputc('\n',fp);
			fclose(fp);
		for (i=0;i<m_list.GetItemCount();i++) 
		{
			in1 >> touzhu;
	

		FILE *fp=fopen(filename,"a");
		//FILE *fp=fopen("d:\\wzy\\ssl inner\\test.txt","a");
		//for (i=0;i<m_list.GetItemCount();i++)
	
		fprintf(fp,"%s",touzhu);
		fputc('\n',fp);
		
		fclose(fp);
		}
		in1.close();
	
		a=m_list.GetItemCount();
		m_list.DeleteAllItems();
	}
};



/*int str_to_int(char str[])
{
	int len=strlen(str),n=0;
	for (int i=0;i<len;i++)
		n=n*10+(str[i]-'0');
	return n;
}*/

void CSslDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default

 if (nIDEvent==100) //刚才设定的是100编号定时器
    {
        CTime t1;
        t1=CTime::GetCurrentTime();
        m_status.SetPaneText(2,t1.Format("%H:%M:%S"));
    }
	
	CDialog::OnTimer(nIDEvent);
}

void CSslDlg::Onsimul_one_issue() 
{
	UpdateData(TRUE);
	char date[30];
//	int y[5],m[3],d[3];
	char yy[5],mm[3],dd[3];
	int_to_str(m_date2.GetYear(),yy);
	int_to_str(m_date2.GetMonth(),mm);
	int_to_str(m_date2.GetDay(),dd);
	//cout << yy <<endl;
//	strcpy(yy,m_date2.GetYear());
//	strcpy(mm,m_date2.GetMonth());
//	strcpy(dd,m_date2.GetDay());
	strcpy(date,yy);
	strcat(date,mm);
	if ((m_date2.GetDay())<10)
		strcat(date,"0");
	
	strcat(date,dd);
	int qihao;
	qihao=m_qishu+1;
	int x;
	char qh[3];
		int_to_str(qihao,qh);
		
		if (qihao<10)
		{	
			char zero[3];
			strcpy(zero,"0");
			strcat(zero,qh);
			strcpy(qh,zero);
		}
	char filename[40];
//	strcpy(filename,"d:\\wzy\\ssl inner\\");
	strcpy(filename,date);
	strcat(filename,qh);
	strcat(filename,".txt");
	//FILE *fp=fopen(filename,"w");
	//fclose(fp);
	
	x=simul_one_issue(date,qihao);
	ifstream in2;
	char touzhu[30];
	//in2.open("d:\\wzy\\ssl inner\\temp.log",ios::in);
	FILE *fp=fopen(filename,"r");
	FILE *fp7=fopen("kaijiang.txt","r");
	char kj[4];
	fscanf(fp7,"%s",&kj);
	fclose(fp7);
	for (int i=0;i<a;i++) 
	{	
		//in2 >> touzhu;
		fscanf(fp,"%s",&touzhu);
		char style[5],num[4],zs[3];
			for (int k=0;k<4;k++) style[k]=touzhu[k];style[4]='\0';
			for (k=0;k<3;k++) num[k]=touzhu[k+7];num[3]='\0';
			for (k=0;k<2;k++) zs[k]=touzhu[k+13];zs[2]='\0';
		
			int zhushu=str_to_int(zs);
		FILE *fp4=fopen("zhongjiangqingkuang.txt","a");
	
		if ((strcmp(style,"前一")==0) && (num[0]==kj[0]))
			{
				fprintf(fp4,"%s","恭喜您中奖了!");
				fputc('\n',fp4);
				fprintf(fp4,"%s","购买情况：");
				fprintf(fp4,"%s",touzhu);
				fputc('\n',fp4);
				fprintf(fp4,"%s","中奖金额：");
				fprintf(fp4,"%d%s",zhushu*10,"元");
				fputc('\n',fp4);
				fputc('\n',fp4);
			}
			else if ((strcmp(style,"后一")==0) && (num[2]==kj[2]))
			{
				fprintf(fp4,"%s","恭喜您中奖了!");
				fputc('\n',fp4);
				fprintf(fp4,"%s","购买情况：");
				fprintf(fp4,"%s",touzhu);
				fputc('\n',fp4);
				fprintf(fp4,"%s","中奖金额：");
				fprintf(fp4,"%d%s",zhushu*10,"元");
				fputc('\n',fp4);
				fputc('\n',fp4);
			}
			else if ((strcmp(style,"前二")==0) && (num[0]==kj[0]) && (num[1]==kj[1]))
			{
				fprintf(fp4,"%s","恭喜您中奖了!");
				fputc('\n',fp4);
				fprintf(fp4,"%s","购买情况：");
				fprintf(fp4,"%s",touzhu);
				fputc('\n',fp4);
				fprintf(fp4,"%s","中奖金额：");
				fprintf(fp4,"%d%s",zhushu*98,"元");
				fputc('\n',fp4);
				fputc('\n',fp4);
			}
			else if ((strcmp(style,"后二")==0) && (num[2]==kj[2]) && (num[1]==kj[1]))
			{
				fprintf(fp4,"%s","恭喜您中奖了!");
				fputc('\n',fp4);
				fprintf(fp4,"%s","购买情况：");
				fprintf(fp4,"%s",touzhu);
				fputc('\n',fp4);
				fprintf(fp4,"%s","中奖金额：");
				fprintf(fp4,"%d%s",zhushu*98,"元");
				fputc('\n',fp4);
				fputc('\n',fp4);
			}
			else if ((strcmp(style,"单选")==0) && (strcmp(num,kj)==0))
			{
				fprintf(fp4,"%s","恭喜您中奖了!");
				fputc('\n',fp4);
				fprintf(fp4,"%s","购买情况：");
				fprintf(fp4,"%s",touzhu);
				fputc('\n',fp4);
				fprintf(fp4,"%s","中奖金额：");
				fprintf(fp4,"%d%s",zhushu*980,"元");
				fputc('\n',fp4);
				fputc('\n',fp4);
			}
			else if ((strcmp(style,"组六")==0) && 
				((num[0]!=num[1])&&(num[0]!=num[2])&&(num[2]!=num[1]))
				&&(((num[0]==kj[0]) && (num[1]==kj[1])&&(num[2]==kj[2])) || ((num[0]==kj[0]) && (num[1]==kj[2])&&(num[2]==kj[1])) 
				|| ((num[0]==kj[1]) && (num[1]==kj[0])&&(num[2]==kj[2])) || ((num[0]==kj[1]) && (num[1]==kj[2])&&(num[2]==kj[0])) 
				|| ((num[0]==kj[2]) && (num[1]==kj[0])&&(num[2]==kj[1])) || ((num[0]==kj[2]) && (num[1]==kj[2])&&(num[2]==kj[0]))))
			{
				fprintf(fp4,"%s","恭喜您中奖了!");
				fputc('\n',fp4);
				fprintf(fp4,"%s","购买情况：");
				fprintf(fp4,"%s",touzhu);
				fputc('\n',fp4);
				fprintf(fp4,"%s","中奖金额：");
				fprintf(fp4,"%d%s",zhushu*320,"元");
				fputc('\n',fp4);
				fputc('\n',fp4);
			}
			else if ((strcmp(style,"组三")==0) && (((kj[0]==kj[1])&&(kj[2]!=kj[0]))||((kj[0]==kj[2])&&(kj[1]!=kj[0]))||((kj[2]==kj[1])&&(kj[2]!=kj[0])))
				&&(((num[0]==kj[0]) && (num[1]==kj[1])&&(num[2]==kj[2])) || ((num[0]==kj[0]) && (num[1]==kj[2])&&(num[2]==kj[1])) 
				|| ((num[0]==kj[1]) && (num[1]==kj[0])&&(num[2]==kj[2])) || ((num[0]==kj[1]) && (num[1]==kj[2])&&(num[2]==kj[0])) 
				|| ((num[0]==kj[2]) && (num[1]==kj[0])&&(num[2]==kj[1])) || ((num[0]==kj[2]) && (num[1]==kj[2])&&(num[2]==kj[0]))))
			{
				fprintf(fp4,"%s","恭喜您中奖了!");
				fputc('\n',fp4);
				fprintf(fp4,"%s","购买情况：");
				fprintf(fp4,"%s",touzhu);
				fputc('\n',fp4);
				fprintf(fp4,"%s","中奖金额：");
				fprintf(fp4,"%d%s",zhushu*160,"元");
				fputc('\n',fp4);
				fputc('\n',fp4);
			}
			fclose(fp4);
	}
//	in2.close();
	//FILE *fp=fopen(filename,"a");
	
	fclose(fp);
	
	
	bool yn=true;
	DeleteFile("该期模拟结果.txt");
	CopyFile(filename,"该期模拟结果.txt",yn);
	ShellExecute(this->m_hWnd,_T("open"),_T("notepad.exe"),_T("该期模拟结果.txt"),_T(""),SW_SHOW   );
	m_status.SetPaneText(0,"模拟完毕");
	UpdateData(FALSE);

}

void CSslDlg::Onsimul_one_day() 
{
	char date[30];
//	int y[5],m[3],d[3];
	char yy[5],mm[3],dd[3];
	int_to_str(m_date2.GetYear(),yy);
	int_to_str(m_date2.GetMonth(),mm);
	int_to_str(m_date2.GetDay(),dd);

//	strcpy(yy,m_date2.GetYear());
//	strcpy(mm,m_date2.GetMonth());
//	strcpy(dd,m_date2.GetDay());
	strcpy(date,yy);
	strcat(date,mm);
	strcat(date,dd);
	int y;
	y=simul_one_day(date);
}





//模拟每一期购买的人数
int CSslDlg::people_per_30_minutes()
{
	const int CONSUMERS_PER_30_MINUTES_LEAST=10;
	const int CONSUMERS_PER_30_MINUTES_MAX=15;
	int cpm1;
	cpm1=CONSUMERS_PER_30_MINUTES_LEAST+rand() % CONSUMERS_PER_30_MINUTES_MAX;
	return cpm1;
}
//模拟开奖
void CSslDlg::kaijiang()
{
	FILE *fp=fopen("kaijiang.txt","w");
//	if (fp==NULL)
//	{
//		cerr << "文件打开失败1\n";
//		exit(-1);
//	};
	//fprintf(fp,"%s%d%s","第",qihao,"期中奖号码为：");
		fprintf(fp,"%d%d%d",rand()%10,rand()%10,rand()%10);
		//fputc('\n',fp);
		fclose(fp);
				
};




//每个人购买的号码的个数
int CSslDlg::haomageshu()
{
	int x=(rand() % 105);
	if (x<100) return 1+(int)(x/14);
	else return 10+rand() % 40;
};
//每个号码购买的注数
int CSslDlg::zhushu()
{
	int zs=rand()%100;
	if (zs<95) return 1+rand()%10;
	else return 10*(1+rand()%5);
};

void CSslDlg::int_to_str(int num, char *str)
{ 
	char c;
    int i=0;
    while (num != 0)
	{ str[i] = num%10 + '0';
      num /= 10;
      i++;
	}
    str[i] = '\0';
    for (int j = 0; j < i/2; j++)
	{ c = str[j];
      str[j] = str[i-j-1];
      str[i-j-1] = c;
	}
};

int CSslDlg::str_to_int(char str[])
{
	int len=strlen(str),n=0;
	for (int i=0;i<len;i++)
		n=n*10+(str[i]-'0');
	return n;
}


//对一个人（彩票编号）的模拟
int CSslDlg::simul_one_person()
{
	int y=haomageshu();
	FILE *fp=fopen("haoma.txt","w");
//	if (fp==NULL)
//	{
//		cerr << "文件打开失败2\n";
//		exit(-1);
//	};
	for (int i=0;i<y;i++)
	{
		int style=rand()%10,a,b,c;
		int zs=zhushu();
		
		switch (style)
		{
		case 0:case 7:case 8: case 9: fprintf(fp,"%s---%d%d%d---%02d%s","单选",rand() % 10,rand() % 10,rand() % 10,zs,"注");
					break;
			case 1: a=rand()%10;
					do b=rand()%10; while (b==a);
					do c=rand()%10; while ((c==b)||(c==a));
					fprintf(fp,"%s---%d%d%d---%02d%s","组六",a,b,c,zs,"注");
					break;
			case 2: a=rand()%10;
					do b=rand()%10; while (b==a);
					c=b;
					fprintf(fp,"%s---%d%d%d---%02d%s","组三",a,b,c,zs,"注");
					break;
			case 3: fprintf(fp,"%s---%d%s---%02d%s","前一",rand()%10,"##",zs,"注");
					break;
			case 4: fprintf(fp,"%s---%s%d---%02d%s","后一","##",rand()%10,zs,"注");
					break;
			case 5: fprintf(fp,"%s---%d%d%c---%02d%s","前二",rand()%10,rand()%10,'#',zs,"注");
					break;
			case 6: fprintf(fp,"%s---%c%d%d---%02d%s","后二",'#',rand()%10,rand()%10,zs,"注");
					break;
//			default: 
//			{
//				cerr << "error\n";
//				exit(-1);
//			};
//				break;
			
		}
		
		fputc('\n',fp);
		
	}
		fclose(fp);
	return y;
};


//模拟一期
int CSslDlg::simul_one_issue(char* date,int qihao)
{
	FILE *fp1=fopen("haoma.txt","r");
//	if (fp1==NULL)
//	{
//		cerr << "文件打开失败3\n";
//		exit(-1);
//	};

	kaijiang();
	FILE *fp3=fopen("kaijiang.txt","r");
			char kj[4];
			int zhushu;
			fscanf(fp3,"%s",&kj);
			 fclose(fp3);
	FILE *fp4=fopen("zhongjiangqingkuang.txt","a");
		fprintf(fp4,"%s%02d%s%s",date,qihao,"期中奖号码为：",kj);
		fputc('\n',fp4);
		fputc('\n',fp4);
		fclose(fp4);
	char qh[3];
		int_to_str(qihao,qh);
		
		if (qihao<10)
		{	
			char zero[3];
			strcpy(zero,"0");
			strcat(zero,qh);
			strcpy(qh,zero);
		}
	char filename[40];
	char QH[10];
	strcpy(QH,date);
	strcat(QH,qh);
//	strcpy(filename,"d:\\wzy\\ssl inner\\");
	strcpy(filename,date);
	strcat(filename,qh);
	strcat(filename,".txt");
	//cout << filename <<endl;

	FILE *fp2=fopen(filename,"a");
//	if (fp2==NULL)
//	{
//		cerr << "文件打开失败4\n";
//		exit(-1);
//	};
	int cpm=people_per_30_minutes();
	char str1[18];
	char style[5],num[4],zs[3];
	FILE *fp5=fopen("statistics.txt","a");
	fprintf(fp5,"%s%s%d%s",QH,"期共有",cpm,"人购买，");
	fputc('\n',fp5);
	fprintf(fp5,"%s%s%d%s",QH,"期销售额为",cpm*2,"元。");
	fputc('\n',fp5);
	fclose(fp5);
	int money=0;
	for (int ii=0;ii<cpm;ii++)
	{
		//cout << ii << endl;
		fprintf(fp2,"%s%02d%04d",date,qihao,ii+1);
		fputc('\n',fp2);
		//cout << simul_one_person() << endl;
		for (int j=0;j<simul_one_person();j++)
		{
			fscanf(fp1,"%s",str1);
			for (int k=0;k<4;k++) style[k]=str1[k];style[4]='\0';
			for (k=0;k<3;k++) num[k]=str1[k+7];num[3]='\0';
			for (k=0;k<2;k++) zs[k]=str1[k+13];zs[2]='\0';
			zhushu=str_to_int(zs);
			//cout << style << endl;
			//cout <<kj<<endl;
			
			FILE *fp4=fopen("zhongjiangqingkuang.txt","a");
			//fprintf(fp4,"%s%s","本期中奖号码为：",kj);
			//fputc('\n',fp4);
			
			//fprintf(fp4,"%s%02d%04d",date,qihao,ii+1);
			//cout << strcmp(kj,num)<<endl;
			if ((strcmp(style,"前一")==0) && (num[0]==kj[0]))
			{
				fprintf(fp4,"%s","中奖号码：");
				fprintf(fp4,"%s%02d%04d",date,qihao,ii+1);
				fputc('\n',fp4);
				fprintf(fp4,"%s","购买情况：");
				fprintf(fp4,"%s",str1);
				fputc('\n',fp4);
				fprintf(fp4,"%s","中奖金额：");
				fprintf(fp4,"%d%s",zhushu*10,"元");
				money+=zhushu*10;
				fputc('\n',fp4);
				fputc('\n',fp4);
			}
			else if ((strcmp(style,"后一")==0) && (num[2]==kj[2]))
			{
				fprintf(fp4,"%s","中奖号码：");
				fprintf(fp4,"%s%02d%04d",date,qihao,ii+1);
				fputc('\n',fp4);
				fprintf(fp4,"%s","购买情况：");
				fprintf(fp4,"%s",str1);
				fputc('\n',fp4);
				fprintf(fp4,"%s","中奖金额：");
				fprintf(fp4,"%d%s",zhushu*10,"元");
				money+=zhushu*10;
				fputc('\n',fp4);
				fputc('\n',fp4);
			}
			else if ((strcmp(style,"前二")==0) && (num[0]==kj[0]) && (num[1]==kj[1]))
			{
			fprintf(fp4,"%s","中奖号码：");
				fprintf(fp4,"%s%02d%04d",date,qihao,ii+1);
				fputc('\n',fp4);
				fprintf(fp4,"%s","购买情况：");
				fprintf(fp4,"%s",str1);
				fputc('\n',fp4);
				fprintf(fp4,"%s","中奖金额：");
				fprintf(fp4,"%d%s",zhushu*98,"元");
				money+=zhushu*98;
				fputc('\n',fp4);
				fputc('\n',fp4);
			}
			else if ((strcmp(style,"后二")==0) && (num[2]==kj[2]) && (num[1]==kj[1]))
			{
				fprintf(fp4,"%s","中奖号码：");
				fprintf(fp4,"%s%02d%04d",date,qihao,ii+1);
				fputc('\n',fp4);
				fprintf(fp4,"%s","购买情况：");
				fprintf(fp4,"%s",str1);
				fputc('\n',fp4);
				fprintf(fp4,"%s","中奖金额：");
				fprintf(fp4,"%d%s",zhushu*98,"元");
				money+=zhushu*98;
				fputc('\n',fp4);
				fputc('\n',fp4);
			}
			else if ((strcmp(style,"单选")==0) && (strcmp(num,kj)==0))
			{
				fprintf(fp4,"%s","中奖号码：");
				fprintf(fp4,"%s%02d%04d",date,qihao,ii+1);
				fputc('\n',fp4);
				fprintf(fp4,"%s","购买情况：");
				fprintf(fp4,"%s",str1);
				fputc('\n',fp4);
				fprintf(fp4,"%s","中奖金额：");
				fprintf(fp4,"%d%s",zhushu*980,"元");
				money+=zhushu*980;
				fputc('\n',fp4);
				fputc('\n',fp4);
			}
			else if ((strcmp(style,"组六")==0) && 
				((num[0]!=num[1])&&(num[0]!=num[2])&&(num[2]!=num[1]))
				&&(((num[0]==kj[0]) && (num[1]==kj[1])&&(num[2]==kj[2])) || ((num[0]==kj[0]) && (num[1]==kj[2])&&(num[2]==kj[1])) 
				|| ((num[0]==kj[1]) && (num[1]==kj[0])&&(num[2]==kj[2])) || ((num[0]==kj[1]) && (num[1]==kj[2])&&(num[2]==kj[0])) 
				|| ((num[0]==kj[2]) && (num[1]==kj[0])&&(num[2]==kj[1])) || ((num[0]==kj[2]) && (num[1]==kj[2])&&(num[2]==kj[0]))))
			{
				fprintf(fp4,"%s","中奖号码：");
				fprintf(fp4,"%s%02d%04d",date,qihao,ii+1);
				fputc('\n',fp4);
				fprintf(fp4,"%s","购买情况：");
				fprintf(fp4,"%s",str1);
				fputc('\n',fp4);
				fprintf(fp4,"%s","中奖金额：");
				fprintf(fp4,"%d%s",zhushu*320,"元");
				money+=zhushu*320;
				fputc('\n',fp4);
				fputc('\n',fp4);
			}
			else if ((strcmp(style,"组三")==0) && (((kj[0]==kj[1])&&(kj[2]!=kj[0]))||((kj[0]==kj[2])&&(kj[1]!=kj[0]))||((kj[2]==kj[1])&&(kj[2]!=kj[0])))
				&&(((num[0]==kj[0]) && (num[1]==kj[1])&&(num[2]==kj[2])) || ((num[0]==kj[0]) && (num[1]==kj[2])&&(num[2]==kj[1])) 
				|| ((num[0]==kj[1]) && (num[1]==kj[0])&&(num[2]==kj[2])) || ((num[0]==kj[1]) && (num[1]==kj[2])&&(num[2]==kj[0])) 
				|| ((num[0]==kj[2]) && (num[1]==kj[0])&&(num[2]==kj[1])) || ((num[0]==kj[2]) && (num[1]==kj[2])&&(num[2]==kj[0]))))
			{
				fprintf(fp4,"%s","中奖号码：");
				fprintf(fp4,"%s%02d%04d",date,qihao,ii+1);
				fputc('\n',fp4);
				fprintf(fp4,"%s","购买情况：");
				fprintf(fp4,"%s",str1);
				fputc('\n',fp4);
				fprintf(fp4,"%s","中奖金额：");
				fprintf(fp4,"%d%s",zhushu*160,"元");
				money+=zhushu*160;
				fputc('\n',fp4);
				fputc('\n',fp4);
			}
			/*
			else 
			{
				fprintf(fp4,"%s","本期无人中奖。");
				fputc('\n',fp4);
				fputc('\n',fp4);
			}
			*/
		//	cout << kj << endl;
			//fscanf(fp1,"%d",str2);
		//	cout << style << endl;
			//cout << str1 << endl;
		//	cout << num << endl;
		//	cout << zs << endl;
			fclose (fp4);
			fprintf(fp2,"%s",str1);
			fputc('\n',fp2);
		}
		
		fclose(fp1);
		fp1=fopen("haoma.txt","r");
	}
	FILE *fp9=fopen("zhongjiangqingkuang.txt","a");
		fprintf(fp9,"%s%d%s","总奖金为",money,"元。");
		fputc('\n',fp9);
		fclose(fp9);
		
		fclose(fp1);
		fclose(fp2);
		return cpm;
};
//
//void CSslDlg::cxgm(int qihao)
//{
//	char filename[40];
//	char qh[20];
//	strcpy(filename,"d:\\wzy\\ssl inner\\");
//	int_to_str(qihao,qh);
//	strcat(filename,qh);
//	strcat(filename,".txt");
	
//}
//模拟一天
int CSslDlg::simul_one_day(char* date)
{
	int count=0;
	for (int j=0;j<23;j++)
	{
		char qh[3];
		int_to_str(j+1,qh);
		
		if (j<9)
		{	
			char zero[3];
			strcpy(zero,"0");
			strcat(zero,qh);
			strcpy(qh,zero);
		}
		//cout << qh<< endl;
		char filename[40];
//	strcpy(filename,"d:\\wzy\\ssl inner\\");
		strcpy(filename,date);
		strcat(filename,qh);
		strcat(filename,".txt");
//		cout << filename <<endl;
		//FILE *fp2=fopen(filename,"w");
		FILE *fp2=fopen(filename,"a");
//		if (fp2==NULL)
//		{
//			cerr << "文件打开失败5\n";
//			exit(-1);
//		};
		    count+=simul_one_issue(date,j+1);
//			cout << count << endl;
		fclose(fp2);
	}
	FILE *fp5=fopen("statistics.txt","a");
	fprintf(fp5,"%s%s%d%s",date,"当天共有",count,"人购买，");
	fputc('\n',fp5);
	fprintf(fp5,"%s%s%d%s",date,"当天销售额为",count*2,"元。");
	fputc('\n',fp5);
	fclose(fp5);
	return count;
};

//模拟三十天
void CSslDlg::simul_one_month()
{
	int cnt=0;
	FILE *fp=fopen("zhongjiangqingkuang.txt","a");
		fclose(fp);
	char date[20];
	char day[3];
	
	for(int k=1;k<=30;k++)
	{
		if (k<10)
		{
			strcpy(date,"2007120");
			int_to_str(k,day);
			strcat(date,day);
			cnt+=simul_one_day(date);
		}
		else
		{
			strcpy(date,"200712");
			int_to_str(k,day);
			strcat(date,day);
			cnt+=simul_one_day(date);
		}
	FILE *fp5=fopen("statistics.txt","a");
	
	fputc('\n',fp5);
	fclose(fp5);

	}
	FILE *fp5=fopen("statistics.txt","a");
	fprintf(fp5,"%s%d%s","30天总计共有",cnt,"人购买，");
	fputc('\n',fp5);
	fprintf(fp5,"%s%d%s","30天销售额总计",cnt*2,"元。");
	fputc('\n',fp5);
	fclose(fp5);
};



void CSslDlg::Onsimul_one_month() 
{
	m_status.SetPaneText(0,"正在模拟中...");

	int cnt=0;
	FILE *fp=fopen("zhongjiangqingkuang.txt","a");
		fclose(fp);
	char date[20];
	char day[3];
	
	for(int k=1;k<=30;k++)
	{
		if (k<10)
		{
			strcpy(date,"2007120");
			int_to_str(k,day);
			strcat(date,day);
			cnt+=simul_one_day(date);
		}
		else
		{
			strcpy(date,"200712");
			int_to_str(k,day);
			strcat(date,day);
			cnt+=simul_one_day(date);
		}

	FILE *fp5=fopen("statistics.txt","a");
	
	fputc('\n',fp5);
	fclose(fp5);

	}
	FILE *fp5=fopen("statistics.txt","a");
	fprintf(fp5,"%s%d%s","30天总计共有",cnt,"人购买");
	fputc('\n',fp5);
	fclose(fp5);
	m_status.SetPaneText(0,"模拟完毕");

}

void CSslDlg::Oncxzj() 
{
	DeleteFile("中奖情况.txt");
	bool yn=true;
	CopyFile("zhongjiangqingkuang.txt","中奖情况.txt",yn);

	ShellExecute(this->m_hWnd,_T("open"),_T("notepad.exe"),_T("中奖情况.txt"),_T(""),SW_SHOW   );
	
}

void CSslDlg::Oncx() 
{
	UpdateData(TRUE);
	char date[30];
//	int y[5],m[3],d[3];
	char yy[5],mm[3],dd[3];
	int_to_str(m_date2.GetYear(),yy);
	int_to_str(m_date2.GetMonth(),mm);
	int_to_str(m_date2.GetDay(),dd);
	//cout << yy <<endl;
//	strcpy(yy,m_date2.GetYear());
//	strcpy(mm,m_date2.GetMonth());
//	strcpy(dd,m_date2.GetDay());
	strcpy(date,yy);
	strcat(date,mm);
	if ((m_date2.GetDay())<10)
		strcat(date,"0");
	
	strcat(date,dd);
	int qihao;
	qihao=m_qishu+1;
	
	char qh[3];
		int_to_str(qihao,qh);
		
		if (qihao<10)
		{	
			char zero[3];
			strcpy(zero,"0");
			strcat(zero,qh);
			strcpy(qh,zero);
		}
	char filename[40];
	char output[40];
	strcpy(output,date);
	strcat(output,qh);
	strcat(output,".txt");
//	strcpy(filename,"d:\\wzy\\ssl inner\\");
	strcpy(filename,date);
	strcat(filename,qh);
	strcat(filename,".txt");
	
	bool yn=true;
	CString fn=filename;
	DeleteFile("模拟结果查询.txt");
	CopyFile(fn,"模拟结果查询.txt",yn);
	ShellExecute(this->m_hWnd,_T("open"),_T("notepad.exe"),_T("模拟结果查询.txt"),_T(""),SW_SHOW   );
	
}

void CSslDlg::OnClose() 
{
	
	ofstream out1;
	
	out1.open("last.log",ios::out);

		out1 << bh;
	
	
	out1.close();
	
	CDialog::OnClose();
}

void CSslDlg::OnJxyz() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString temp;
	temp=GetLNum(m_xuanfa,m_beishu);
	int n=m_list.InsertItem(0,temp.Left(4));
	m_list.SetItemText(n,1,temp.Mid(7,3));
	int z=atoi(temp.Mid(13,4));
	char zz[4];
	zz[0]='\0';
	int_to_str(z,zz);
	m_list.SetItemText(n,2,zz);
}

CString CSslDlg::GetLNum(const int &style , const int &zs)
{		
	CString temp;
	int a,b,c;
	switch (style)
		{
		case 0:case 7:case 8: case 9: temp.Format("%s---%d%d%d---%02d%s","单选",rand() % 10,rand() % 10,rand() % 10,zs,"注");
					break;
			case 1: a=rand()%10;
					do b=rand()%10; while (b==a);
					do c=rand()%10; while ((c==b)||(c==a));
					temp.Format("%s---%d%d%d---%02d%s","组六",a,b,c,zs,"注");
					break;
			case 2: a=rand()%10;
					do b=rand()%10; while (b==a);
					c=b;
					temp.Format("%s---%d%d%d---%02d%s","组三",a,b,c,zs,"注");
					break;
			case 5: temp.Format("%s---%d%s---%02d%s","前一",rand()%10,"##",zs,"注");
					break;
			case 6: temp.Format("%s---%s%d---%02d%s","后一","##",rand()%10,zs,"注");
					break;
			case 3: temp.Format("%s---%d%d%c---%02d%s","前二",rand()%10,rand()%10,'#',zs,"注");
					break;
			case 4: temp.Format("%s---%c%d%d---%02d%s","后二",'#',rand()%10,rand()%10,zs,"注");
					break;
//			default: 
//			{
//				cerr << "error\n";
//				exit(-1);
//			};
//				break;
			
		}
		return temp;
}
