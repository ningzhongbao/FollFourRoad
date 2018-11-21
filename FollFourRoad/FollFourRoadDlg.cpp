
// FollFourRoadDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "FollFourRoad.h"
#include "FollFourRoadDlg.h"
#include "afxdialogex.h"
#include "../Include/netmanager.h"
#include "../Include/PlayV1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFollFourRoadDlg 对话框

CFollFourRoadDlg *pFollRold = NULL;


CFollFourRoadDlg::CFollFourRoadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_FOLLFOURROAD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	
	pFollRold = this;
}

void CFollFourRoadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CFollFourRoadDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_STN_CLICKED(IDC_RVC1, &CFollFourRoadDlg::OnStnClickedRvc1)
	ON_BN_CLICKED(IDC_BtnOpen, &CFollFourRoadDlg::OnBnClickedBtnopen)
	ON_BN_CLICKED(IDC_BtnShutDown, &CFollFourRoadDlg::OnBnClickedBtnshutdown)
END_MESSAGE_MAP()



void CALLBACK disconnect_callback(LLONG lLoginID,
	char *lpszIP,
	LONG nPort,
	LDWORD dwUser)
{
	MessageBox(NULL, L"disconnect.\n", NULL, MB_OK);
}

// CFollFourRoadDlg 消息处理程序

BOOL CFollFourRoadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	ShowWindow(SW_MAXIMIZE);

	// TODO: 在此添加额外的初始化代码

	// 初始化网络库资源
	Net_Init(disconnect_callback, NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CFollFourRoadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CFollFourRoadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CALLBACK realdata_callback(long lRealHandle,
	DWORD dwDataType,
	BYTE *pBuffer,
	DWORD dwBufSize,
	LDWORD dwUser)
{
	// 此处仅是将数据投递到播放库播放
	LONG* pPlayPort = (LONG*)dwUser;
	PlayMS_InputData(*pPlayPort, pBuffer, dwBufSize);
}

void CFollFourRoadDlg::UnInit()
{
	Net_Exit();
}

void CFollFourRoadDlg::Init()
{
	UpdateData(TRUE);
	//m_strIP = "192.168.20.100";
	//m_nPort = 3000;
	//m_strUser = "admin";
	//m_strPswd = "admin123";
	UpdateData(FALSE);

	Net_Init(NULL, NULL);
}



DWORD CFollFourRoadDlg::PVCThreadOne(LPVOID lpar)
{
	int   nError = 0;
	LLONG lLoginId = 0;
	LLONG lRealPlayId = 0;
	int   nChannel = 0;
	LONG  nPlayPort;   // 视频播放虚拟通道号

	//// 初始化网络库资源
	//Net_Init(disconnect_callback, NULL);

	// 远程登录设备
	lLoginId = Net_LoginDevice("192.168.35.2", 3000, "admin", "admin123", NULL, &nError);
	if (0 >= lLoginId)
	{
		::MessageBox(NULL, L"远程设备登陆失败", L"警告", MB_ICONERROR);

		return 0;
	}

	// 获取空闲播放通道号
	PlayMS_GetFreePort(&nPlayPort);

	//播放
	HWND hwnd = pFollRold->GetDlgItem(IDC_RVC1)->GetSafeHwnd();
	//HWND hwnd1 = GetDlgItem(IDC_STATIC_Play2)->GetSafeHwnd();

	// 设置实时流模式（如果是文件可以选择 STREAM_TYPE_FILE）
	BOOL bRet = PlayMS_SetStreamOpenMode(nPlayPort, STREAM_TYPE_REALTIME);

	// 打开流，并初始化缓存池（大小 MIN_SOURCE_BUF_SIZE - MAX_SOURCE_BUF_SIZE）
	bRet &= PlayMS_OpenStream(nPlayPort, 1024 * 1024 * 20);
	// 在窗口 hwnd 播放流数据
	bRet &= PlayMS_Play(nPlayPort, hwnd);

	//// 设置解码回调函数，解码回调中获取帧内容和帧信息
	//bRet &= PlayMS_SetVisibleDecodeCallBack(nPlayPort, (fDecodeCallBack)visible_decode_callback, NULL);

	// 指定播放窗口 hwnd = NULL，此时网络流数据通过 Net_SetRealDataCallBack 设置实时数据回调后，
	// 由 PlayMS_InputData 直接由播放库控制播放
	lRealPlayId = Net_RealPlay(lLoginId, nChannel, NULL, REALPLAY_STREAM_TYPE_REAL);
	if (0 >= lRealPlayId)
	{
		printf("real play error.\n");
		Net_LogoutDevice(lLoginId);
		return 0;
	}

	// 设置实时数据回调函数
	Net_SetRealDataCallBack(lRealPlayId, (fRealPlayDataCallBack)realdata_callback, (DWORD)&nPlayPort);	

	while (TRUE)
	{
	}
	if (0 < nPlayPort)
	{
		// 设置解码回调为 NULL
		PlayMS_SetVisibleDecodeCallBack(nPlayPort, NULL, NULL);

		// 停止播放码流
		PlayMS_Stop(nPlayPort);

		// 关闭码流
		PlayMS_CloseStream(nPlayPort);

		// 释放流播放模式下的缓存数据
		//（关闭码流后必须清空缓存数据，否则会出现帧残留的现象）
		PlayMS_ResetSourceBuffer(nPlayPort);
	}

	// 停止实时预览
	if (0 < lRealPlayId)
		Net_StopRealPlay(lRealPlayId);

	lRealPlayId = 0;
	nPlayPort = 0;

	Sleep(2000);

	// 登出设备
	Net_LogoutDevice(lLoginId);

	// 清理网络库资源
	Net_Exit();
}




DWORD CFollFourRoadDlg::PVCThreadTwo(LPVOID lpar)
{
	int   nError = 0;
	LLONG lLoginId = 0;
	LLONG lRealPlayId = 0;
	int   nChannel = 0;
	LONG  nPlayPort;   // 视频播放虚拟通道号

	
	// 远程登录设备
	lLoginId = Net_LoginDevice("192.168.35.123", 3000, "admin", "admin123", NULL, &nError);
	if (0 >= lLoginId)
	{
		::MessageBox(NULL, L"远程设备登陆失败", L"警告", MB_ICONERROR);

		return 0;
	}

	// 获取空闲播放通道号
	PlayMS_GetFreePort(&nPlayPort);

	//播放
	HWND hwnd = pFollRold->GetDlgItem(IDC_RVC2)->GetSafeHwnd();
	
	// 设置实时流模式（如果是文件可以选择 STREAM_TYPE_FILE）
	BOOL bRet = PlayMS_SetStreamOpenMode(nPlayPort, STREAM_TYPE_REALTIME);

	// 打开流，并初始化缓存池（大小 MIN_SOURCE_BUF_SIZE - MAX_SOURCE_BUF_SIZE）
	bRet &= PlayMS_OpenStream(nPlayPort, 1024 * 1024 * 20);
	// 在窗口 hwnd 播放流数据
	bRet &= PlayMS_Play(nPlayPort, hwnd);

	//// 设置解码回调函数，解码回调中获取帧内容和帧信息
	//bRet &= PlayMS_SetVisibleDecodeCallBack(nPlayPort, (fDecodeCallBack)visible_decode_callback, NULL);

	// 指定播放窗口 hwnd = NULL，此时网络流数据通过 Net_SetRealDataCallBack 设置实时数据回调后，
	// 由 PlayMS_InputData 直接由播放库控制播放
	lRealPlayId = Net_RealPlay(lLoginId, nChannel, NULL, REALPLAY_STREAM_TYPE_REAL);
	if (0 >= lRealPlayId)
	{
		printf("real play error.\n");
		Net_LogoutDevice(lLoginId);
		return 0;
	}

	// 设置实时数据回调函数
	Net_SetRealDataCallBack(lRealPlayId, (fRealPlayDataCallBack)realdata_callback, (DWORD)&nPlayPort);

	while (TRUE)
	{
	}
	if (0 < nPlayPort)
	{
		// 设置解码回调为 NULL
		PlayMS_SetVisibleDecodeCallBack(nPlayPort, NULL, NULL);

		// 停止播放码流
		PlayMS_Stop(nPlayPort);

		// 关闭码流
		PlayMS_CloseStream(nPlayPort);

		// 释放流播放模式下的缓存数据
		//（关闭码流后必须清空缓存数据，否则会出现帧残留的现象）
		PlayMS_ResetSourceBuffer(nPlayPort);
	}

	// 停止实时预览
	if (0 < lRealPlayId)
		Net_StopRealPlay(lRealPlayId);

	lRealPlayId = 0;
	nPlayPort = 0;

	Sleep(2000);

	// 登出设备
	Net_LogoutDevice(lLoginId);

	// 清理网络库资源
	Net_Exit();
}



DWORD CFollFourRoadDlg::PVCThreadThree(LPVOID lpar)
{
	int   nError = 0;
	LLONG lLoginId = 0;
	LLONG lRealPlayId = 0;
	int   nChannel = 0;
	LONG  nPlayPort;   // 视频播放虚拟通道号

					   // 远程登录设备
	lLoginId = Net_LoginDevice("192.168.36.2", 3000, "admin", "admin123", NULL, &nError);
	if (0 >= lLoginId)
	{
		::MessageBox(NULL, L"远程设备登陆失败", L"警告", MB_ICONERROR);

		return 0;
	}

	// 获取空闲播放通道号
	PlayMS_GetFreePort(&nPlayPort);

	//播放
	HWND hwnd = pFollRold->GetDlgItem(IDC_RVC3)->GetSafeHwnd();
	//HWND hwnd1 = GetDlgItem(IDC_STATIC_Play2)->GetSafeHwnd();

	// 设置实时流模式（如果是文件可以选择 STREAM_TYPE_FILE）
	BOOL bRet = PlayMS_SetStreamOpenMode(nPlayPort, STREAM_TYPE_REALTIME);

	// 打开流，并初始化缓存池（大小 MIN_SOURCE_BUF_SIZE - MAX_SOURCE_BUF_SIZE）
	bRet &= PlayMS_OpenStream(nPlayPort, 1024 * 1024 * 20);
	// 在窗口 hwnd 播放流数据
	bRet &= PlayMS_Play(nPlayPort, hwnd);

	//// 设置解码回调函数，解码回调中获取帧内容和帧信息
	//bRet &= PlayMS_SetVisibleDecodeCallBack(nPlayPort, (fDecodeCallBack)visible_decode_callback, NULL);

	// 指定播放窗口 hwnd = NULL，此时网络流数据通过 Net_SetRealDataCallBack 设置实时数据回调后，
	// 由 PlayMS_InputData 直接由播放库控制播放
	lRealPlayId = Net_RealPlay(lLoginId, nChannel, NULL, REALPLAY_STREAM_TYPE_REAL);
	if (0 >= lRealPlayId)
	{
		printf("real play error.\n");
		Net_LogoutDevice(lLoginId);
		return 0;
	}

	// 设置实时数据回调函数
	Net_SetRealDataCallBack(lRealPlayId, (fRealPlayDataCallBack)realdata_callback, (DWORD)&nPlayPort);

	while (TRUE)
	{
	}
	if (0 < nPlayPort)
	{
		// 设置解码回调为 NULL
		PlayMS_SetVisibleDecodeCallBack(nPlayPort, NULL, NULL);

		// 停止播放码流
		PlayMS_Stop(nPlayPort);
		 
		// 关闭码流
		PlayMS_CloseStream(nPlayPort);

		// 释放流播放模式下的缓存数据
		//（关闭码流后必须清空缓存数据，否则会出现帧残留的现象）
		PlayMS_ResetSourceBuffer(nPlayPort);
	}

	// 停止实时预览
	if (0 < lRealPlayId)
		Net_StopRealPlay(lRealPlayId);

	lRealPlayId = 0;
	nPlayPort = 0;

	Sleep(2000);

	// 登出设备
	Net_LogoutDevice(lLoginId);

	// 清理网络库资源
	Net_Exit();
}


void CFollFourRoadDlg::OnStnClickedRvc1()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CFollFourRoadDlg::OnBnClickedBtnopen()
{
	// TODO: 在此添加控件通知处理程序代码
	CloseHandle(CreateThread(NULL, 0, PVCThreadOne, (LPVOID)NULL, 0, 0));
	CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)PVCThreadTwo, (LPVOID)NULL, 0, 0));
	CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)PVCThreadThree, (LPVOID)NULL, 0, 0));
}


void CFollFourRoadDlg::OnBnClickedBtnshutdown()
{
	// TODO: 在此添加控件通知处理程序代码
	g_nOpenOrShutFlag = 1;
	
}
