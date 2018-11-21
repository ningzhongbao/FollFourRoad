
// FollFourRoadDlg.cpp : ʵ���ļ�
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


// CFollFourRoadDlg �Ի���

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

// CFollFourRoadDlg ��Ϣ�������

BOOL CFollFourRoadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	ShowWindow(SW_MAXIMIZE);

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	// ��ʼ���������Դ
	Net_Init(disconnect_callback, NULL);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CFollFourRoadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
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
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
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
	// �˴����ǽ�����Ͷ�ݵ����ſⲥ��
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
	LONG  nPlayPort;   // ��Ƶ��������ͨ����

	//// ��ʼ���������Դ
	//Net_Init(disconnect_callback, NULL);

	// Զ�̵�¼�豸
	lLoginId = Net_LoginDevice("192.168.35.2", 3000, "admin", "admin123", NULL, &nError);
	if (0 >= lLoginId)
	{
		::MessageBox(NULL, L"Զ���豸��½ʧ��", L"����", MB_ICONERROR);

		return 0;
	}

	// ��ȡ���в���ͨ����
	PlayMS_GetFreePort(&nPlayPort);

	//����
	HWND hwnd = pFollRold->GetDlgItem(IDC_RVC1)->GetSafeHwnd();
	//HWND hwnd1 = GetDlgItem(IDC_STATIC_Play2)->GetSafeHwnd();

	// ����ʵʱ��ģʽ��������ļ�����ѡ�� STREAM_TYPE_FILE��
	BOOL bRet = PlayMS_SetStreamOpenMode(nPlayPort, STREAM_TYPE_REALTIME);

	// ����������ʼ������أ���С MIN_SOURCE_BUF_SIZE - MAX_SOURCE_BUF_SIZE��
	bRet &= PlayMS_OpenStream(nPlayPort, 1024 * 1024 * 20);
	// �ڴ��� hwnd ����������
	bRet &= PlayMS_Play(nPlayPort, hwnd);

	//// ���ý���ص�����������ص��л�ȡ֡���ݺ�֡��Ϣ
	//bRet &= PlayMS_SetVisibleDecodeCallBack(nPlayPort, (fDecodeCallBack)visible_decode_callback, NULL);

	// ָ�����Ŵ��� hwnd = NULL����ʱ����������ͨ�� Net_SetRealDataCallBack ����ʵʱ���ݻص���
	// �� PlayMS_InputData ֱ���ɲ��ſ���Ʋ���
	lRealPlayId = Net_RealPlay(lLoginId, nChannel, NULL, REALPLAY_STREAM_TYPE_REAL);
	if (0 >= lRealPlayId)
	{
		printf("real play error.\n");
		Net_LogoutDevice(lLoginId);
		return 0;
	}

	// ����ʵʱ���ݻص�����
	Net_SetRealDataCallBack(lRealPlayId, (fRealPlayDataCallBack)realdata_callback, (DWORD)&nPlayPort);	

	while (TRUE)
	{
	}
	if (0 < nPlayPort)
	{
		// ���ý���ص�Ϊ NULL
		PlayMS_SetVisibleDecodeCallBack(nPlayPort, NULL, NULL);

		// ֹͣ��������
		PlayMS_Stop(nPlayPort);

		// �ر�����
		PlayMS_CloseStream(nPlayPort);

		// �ͷ�������ģʽ�µĻ�������
		//���ر������������ջ������ݣ���������֡����������
		PlayMS_ResetSourceBuffer(nPlayPort);
	}

	// ֹͣʵʱԤ��
	if (0 < lRealPlayId)
		Net_StopRealPlay(lRealPlayId);

	lRealPlayId = 0;
	nPlayPort = 0;

	Sleep(2000);

	// �ǳ��豸
	Net_LogoutDevice(lLoginId);

	// �����������Դ
	Net_Exit();
}




DWORD CFollFourRoadDlg::PVCThreadTwo(LPVOID lpar)
{
	int   nError = 0;
	LLONG lLoginId = 0;
	LLONG lRealPlayId = 0;
	int   nChannel = 0;
	LONG  nPlayPort;   // ��Ƶ��������ͨ����

	
	// Զ�̵�¼�豸
	lLoginId = Net_LoginDevice("192.168.35.123", 3000, "admin", "admin123", NULL, &nError);
	if (0 >= lLoginId)
	{
		::MessageBox(NULL, L"Զ���豸��½ʧ��", L"����", MB_ICONERROR);

		return 0;
	}

	// ��ȡ���в���ͨ����
	PlayMS_GetFreePort(&nPlayPort);

	//����
	HWND hwnd = pFollRold->GetDlgItem(IDC_RVC2)->GetSafeHwnd();
	
	// ����ʵʱ��ģʽ��������ļ�����ѡ�� STREAM_TYPE_FILE��
	BOOL bRet = PlayMS_SetStreamOpenMode(nPlayPort, STREAM_TYPE_REALTIME);

	// ����������ʼ������أ���С MIN_SOURCE_BUF_SIZE - MAX_SOURCE_BUF_SIZE��
	bRet &= PlayMS_OpenStream(nPlayPort, 1024 * 1024 * 20);
	// �ڴ��� hwnd ����������
	bRet &= PlayMS_Play(nPlayPort, hwnd);

	//// ���ý���ص�����������ص��л�ȡ֡���ݺ�֡��Ϣ
	//bRet &= PlayMS_SetVisibleDecodeCallBack(nPlayPort, (fDecodeCallBack)visible_decode_callback, NULL);

	// ָ�����Ŵ��� hwnd = NULL����ʱ����������ͨ�� Net_SetRealDataCallBack ����ʵʱ���ݻص���
	// �� PlayMS_InputData ֱ���ɲ��ſ���Ʋ���
	lRealPlayId = Net_RealPlay(lLoginId, nChannel, NULL, REALPLAY_STREAM_TYPE_REAL);
	if (0 >= lRealPlayId)
	{
		printf("real play error.\n");
		Net_LogoutDevice(lLoginId);
		return 0;
	}

	// ����ʵʱ���ݻص�����
	Net_SetRealDataCallBack(lRealPlayId, (fRealPlayDataCallBack)realdata_callback, (DWORD)&nPlayPort);

	while (TRUE)
	{
	}
	if (0 < nPlayPort)
	{
		// ���ý���ص�Ϊ NULL
		PlayMS_SetVisibleDecodeCallBack(nPlayPort, NULL, NULL);

		// ֹͣ��������
		PlayMS_Stop(nPlayPort);

		// �ر�����
		PlayMS_CloseStream(nPlayPort);

		// �ͷ�������ģʽ�µĻ�������
		//���ر������������ջ������ݣ���������֡����������
		PlayMS_ResetSourceBuffer(nPlayPort);
	}

	// ֹͣʵʱԤ��
	if (0 < lRealPlayId)
		Net_StopRealPlay(lRealPlayId);

	lRealPlayId = 0;
	nPlayPort = 0;

	Sleep(2000);

	// �ǳ��豸
	Net_LogoutDevice(lLoginId);

	// �����������Դ
	Net_Exit();
}



DWORD CFollFourRoadDlg::PVCThreadThree(LPVOID lpar)
{
	int   nError = 0;
	LLONG lLoginId = 0;
	LLONG lRealPlayId = 0;
	int   nChannel = 0;
	LONG  nPlayPort;   // ��Ƶ��������ͨ����

					   // Զ�̵�¼�豸
	lLoginId = Net_LoginDevice("192.168.36.2", 3000, "admin", "admin123", NULL, &nError);
	if (0 >= lLoginId)
	{
		::MessageBox(NULL, L"Զ���豸��½ʧ��", L"����", MB_ICONERROR);

		return 0;
	}

	// ��ȡ���в���ͨ����
	PlayMS_GetFreePort(&nPlayPort);

	//����
	HWND hwnd = pFollRold->GetDlgItem(IDC_RVC3)->GetSafeHwnd();
	//HWND hwnd1 = GetDlgItem(IDC_STATIC_Play2)->GetSafeHwnd();

	// ����ʵʱ��ģʽ��������ļ�����ѡ�� STREAM_TYPE_FILE��
	BOOL bRet = PlayMS_SetStreamOpenMode(nPlayPort, STREAM_TYPE_REALTIME);

	// ����������ʼ������أ���С MIN_SOURCE_BUF_SIZE - MAX_SOURCE_BUF_SIZE��
	bRet &= PlayMS_OpenStream(nPlayPort, 1024 * 1024 * 20);
	// �ڴ��� hwnd ����������
	bRet &= PlayMS_Play(nPlayPort, hwnd);

	//// ���ý���ص�����������ص��л�ȡ֡���ݺ�֡��Ϣ
	//bRet &= PlayMS_SetVisibleDecodeCallBack(nPlayPort, (fDecodeCallBack)visible_decode_callback, NULL);

	// ָ�����Ŵ��� hwnd = NULL����ʱ����������ͨ�� Net_SetRealDataCallBack ����ʵʱ���ݻص���
	// �� PlayMS_InputData ֱ���ɲ��ſ���Ʋ���
	lRealPlayId = Net_RealPlay(lLoginId, nChannel, NULL, REALPLAY_STREAM_TYPE_REAL);
	if (0 >= lRealPlayId)
	{
		printf("real play error.\n");
		Net_LogoutDevice(lLoginId);
		return 0;
	}

	// ����ʵʱ���ݻص�����
	Net_SetRealDataCallBack(lRealPlayId, (fRealPlayDataCallBack)realdata_callback, (DWORD)&nPlayPort);

	while (TRUE)
	{
	}
	if (0 < nPlayPort)
	{
		// ���ý���ص�Ϊ NULL
		PlayMS_SetVisibleDecodeCallBack(nPlayPort, NULL, NULL);

		// ֹͣ��������
		PlayMS_Stop(nPlayPort);
		 
		// �ر�����
		PlayMS_CloseStream(nPlayPort);

		// �ͷ�������ģʽ�µĻ�������
		//���ر������������ջ������ݣ���������֡����������
		PlayMS_ResetSourceBuffer(nPlayPort);
	}

	// ֹͣʵʱԤ��
	if (0 < lRealPlayId)
		Net_StopRealPlay(lRealPlayId);

	lRealPlayId = 0;
	nPlayPort = 0;

	Sleep(2000);

	// �ǳ��豸
	Net_LogoutDevice(lLoginId);

	// �����������Դ
	Net_Exit();
}


void CFollFourRoadDlg::OnStnClickedRvc1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void CFollFourRoadDlg::OnBnClickedBtnopen()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CloseHandle(CreateThread(NULL, 0, PVCThreadOne, (LPVOID)NULL, 0, 0));
	CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)PVCThreadTwo, (LPVOID)NULL, 0, 0));
	CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)PVCThreadThree, (LPVOID)NULL, 0, 0));
}


void CFollFourRoadDlg::OnBnClickedBtnshutdown()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	g_nOpenOrShutFlag = 1;
	
}
