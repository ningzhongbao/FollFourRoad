
// FollFourRoadDlg.h : ͷ�ļ�
//

#pragma once

#include <iostream>
using namespace std;
#include "CamConfigFile.h"

static int g_nOpenOrShutFlag = 0;
// CFollFourRoadDlg �Ի���
class CFollFourRoadDlg : public CDialogEx
{
// ����
public:
	CFollFourRoadDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FOLLFOURROAD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	static DWORD WINAPI PVCThreadOne(LPVOID lpar);
	static DWORD  PVCThreadTwo(LPVOID lpar);
	static DWORD PVCThreadThree(LPVOID lpar);
	void   UnInit();  //�˳��������
	void   Init();  //��ʼ�������sdk��
public:
	afx_msg void OnStnClickedRvc1();
	afx_msg void OnBnClickedBtnopen();
	afx_msg void OnBnClickedBtnshutdown();
};
