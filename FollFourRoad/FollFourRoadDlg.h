
// FollFourRoadDlg.h : 头文件
//

#pragma once

#include <iostream>
using namespace std;
#include "CamConfigFile.h"

static int g_nOpenOrShutFlag = 0;
// CFollFourRoadDlg 对话框
class CFollFourRoadDlg : public CDialogEx
{
// 构造
public:
	CFollFourRoadDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FOLLFOURROAD_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

public:
	static DWORD WINAPI PVCThreadOne(LPVOID lpar);
	static DWORD  PVCThreadTwo(LPVOID lpar);
	static DWORD PVCThreadThree(LPVOID lpar);
	void   UnInit();  //退出摄像机库
	void   Init();  //初始化摄像机sdk库
public:
	afx_msg void OnStnClickedRvc1();
	afx_msg void OnBnClickedBtnopen();
	afx_msg void OnBnClickedBtnshutdown();
};
