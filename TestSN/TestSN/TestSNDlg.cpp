// TestSNDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestSN.h"
#include "TestSNDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CTestSNDlg �Ի���




CTestSNDlg::CTestSNDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTestSNDlg::IDD, pParent)
	, m_strPrefix(_T("A"))
	, m_strSubfix(_T("Z"))
	, m_strSN(_T("000100"))
	, m_nHex(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestSNDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PREFIX, m_strPrefix);
	DDX_Text(pDX, IDC_EDIT_SUBFIX, m_strSubfix);
	DDX_Text(pDX, IDC_EDIT_SN, m_strSN);
	DDX_Control(pDX, IDC_COMBO1, m_cmbHex);
	DDX_CBIndex(pDX, IDC_COMBO1, m_nHex);
}

BEGIN_MESSAGE_MAP(CTestSNDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CTestSNDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CTestSNDlg ��Ϣ�������

BOOL CTestSNDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	//m_cmbHex.AddString(_T("10����"));
	//m_cmbHex.AddString(_T("34����"));

	for (int i = 2; i < 36; i++)
	{
		CString s;
		s.Format(_T("%d����"), i);
		m_cmbHex.AddString(s);
	}

	UpdateData(FALSE);

	CString strMsg;
	strMsg = _T("Ҫ�����34���Ƶĵ�ǰ��ˮ�ż�1\n\
				34����:0123456789ABCDEFGHJKLMNPQRSTUVWXYZ");
	SetDlgItemText(IDC_STATIC_MSG,strMsg);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CTestSNDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTestSNDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ��������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù����ʾ��
//
HCURSOR CTestSNDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CTestSNDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData();

	CString strFormat;
	CString strFullText;


	//if(m_nHex == 0)
	//{//10���Ƽ�1
	//	int nLen = m_strSN.GetLength();
	//	int nSn = _tstoi(m_strSN);
	//	strFormat.Format(_T("%%0%dd"),nLen);
	//	m_strSN.Format(strFormat,nSn+1);
	//}
	//else if(m_nHex == 1)
	//{//�ڴ�������������ˮ�ż�1������34�����������Զ���

	//}

	int base = m_nHex + 2;

	m_strSN = NextSN(m_strSN, base);

	strFullText.Format(_T("%s%s%s"),m_strPrefix,m_strSN,m_strSubfix);
	SetDlgItemText(IDC_EDIT_TEXT,strFullText);
	UpdateData(FALSE);
}


int CTestSNDlg::Char2Num(TCHAR c)
{
	if (c >= _T('0') && c <= _T('9'))
	{
		return c - _T('0');
	}
	else if (c >= _T('A') && c <= _T('Z'))
	{
		return 10 + c - _T('A');
	}
	else if (c >= _T('a') && c <= _T('z'))
	{
		return 10 + c - _T('a');
	}
	else
	{
		return -1;
	}
}


TCHAR CTestSNDlg::Num2Char(int n)
{
	if (n >= 0 && n <= 9)
	{
		return n + _T('0');
	}
	else if (n >= 10 && n <= 35)
	{
		return n - 10 + _T('A');
	}
	else
	{
		return _T('*');
	}
}


CString CTestSNDlg::NextSN(CString sc, int base)
{
	const int LENGTH = sc.GetLength();
	int cum = 1;
	for (int i = LENGTH - 1; i >= 0; i--)
	{
		TCHAR c = sc.GetAt(i);
		int n = Char2Num(c) + cum;
		if (n >= base)
		{
			cum = 1;
			n -= base;
			sc.SetAt(i, Num2Char(n));
		}
		else
		{
			cum = 0;
			sc.SetAt(i, Num2Char(n));
			break;
		}
	}
	return sc;
}
