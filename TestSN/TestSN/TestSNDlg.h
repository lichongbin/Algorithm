// TestSNDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"


// CTestSNDlg �Ի���
class CTestSNDlg : public CDialog
{
// ����
public:
	CTestSNDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_TESTSN_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strPrefix;
public:
	CString m_strSubfix;
public:
	CString m_strSN;
public:
	CComboBox m_cmbHex;
public:
	int m_nHex;
public:
	afx_msg void OnBnClickedOk();

private:
	int Char2Num(TCHAR c);
	TCHAR Num2Char(int n);
	CString NextSN(CString sc, int base);
};
