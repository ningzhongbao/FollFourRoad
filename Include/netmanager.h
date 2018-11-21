#ifndef _AL_NET_MANAGER_LIB_H
#define _AL_NET_MANAGER_LIB_H

#include "netstructcolletion.h"

#if defined(WIN32) || defined(WIN64)

#ifdef NET_API_EXPORTS
	#ifndef NET_API
		#define NET_API  __declspec(dllexport)
	#endif
#else
	#ifndef NET_API
		#define NET_API  __declspec(dllimport)
	#endif
#endif

#define CALLBACK	__stdcall
#define CALL_METHOD __stdcall  //__cdecl
#else

#ifndef NET_API
	#define NET_API 
#endif

#define CALLBACK
#define CALL_METHOD  //__cdecl

#endif

#ifdef __cplusplus
extern "C" {
#endif

/////////////////////////////////////////////////////////////////////////////////
//							netmanager library �ӿڶ���					       //
/////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
������		NET_Init
������		[in] fDisConnCB 				�豸������߻ص�����
			[in] dwUser						�û�����
����ֵ��		�ɹ�����TRUE, ʧ�ܷ���FALSE��
˵����		�û���ʹ�������֮ǰ��������г�ʼ��
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_Init(fDisConnectCallBack fDisConnCB, LDWORD dwUser);

/********************************************************************************
������		NET_Exit
������		/	
����ֵ��		/
˵����		�û�ȷ���ڲ�ʹ��������κι���֮����Ҫ�����˳����������������Դ
*********************************************************************************/
NET_API void CALL_METHOD Net_Exit();

/********************************************************************************
������		NET_Version
������		/	
����ֵ��		�����汾��
˵����		��ȡ��汾��Ϣ
*********************************************************************************/
NET_API DWORD CALL_METHOD Net_Version();

/********************************************************************************
������		NET_LastError
������		/	
����ֵ��		��������һ�δ�����ʱ�����Ĵ����룬������±�
˵����		��������԰����û����ٶ�λ���⣬������������ע���������ռ�	
*********************************************************************************/
NET_API DWORD CALL_METHOD Net_LastError(void);

/////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
������		NET_SetReconnectCallBack
������		[in] fReConnectedCB				�豸���������ɹ��ص�����
			[in] dwUser						�û�����
����ֵ��		/
˵����		���ö���ʱ�����ɹ���Ļص�����
*********************************************************************************/
NET_API void CALL_METHOD Net_SetReconnectCallBack(fReConnectedCallBack fReConnectedCB, LDWORD dwUser);

/********************************************************************************
������		NET_SetSubDisconnCallBack
������		[in] fSubDisConnCB					��̬�����Ӷ��߻ص�����
			[in] dwUser							�û�����
����ֵ��		�ɹ�����TRUE, ʧ�ܷ���FALSE��
˵����		���ö�̬�����Ӷ��߻ص�����
*********************************************************************************/
NET_API void CALL_METHOD Net_SetSubDisconnCallBack(fSubDisConnectCallBack fSubDisConnCB, LDWORD dwUser);

/********************************************************************************
������		void NET_SetConnectTime(int nWaitTime, int nTryTimes)
������		[in] nWaitTime						���ӵȴ���ʱʱ�䣨ms��
			[in] nTryTimes						������ӳ��Դ���
����ֵ��		/
˵����		���������豸��ʱʱ��ͳ��Դ���
*********************************************************************************/
NET_API void CALL_METHOD Net_SetConnectTime(int nWaitTime, int nTryTimes);

/********************************************************************************
������		void NET_SetNetworkParam(STU_NET_PARAM *pNetParam)
������		[in] pNetParam						�豸���ӵ��������
����ֵ��		/
˵����		���õ�½���绷��, �û������ڵ����豸֮ǰ��������
*********************************************************************************/
NET_API void CALL_METHOD Net_SetNetworkParam(STU_NET_PARAM* pNetParam);

/********************************************************************************
������		NET_LoginDevice
������		[in] lpszIP							�豸 IP ��ַ
			[in] nPort							�豸����˿�
			[in] lpszUserName					�豸�����û�����
			[in] lpszPassword					�豸�����û�����
			[in] pReserved						Ԥ��λ
			[out] pnError						���������
												0 - �޴���
												1 - �����������Ӵ���
												2 - �����豸��¼�������
												3 - ��¼��Ӧ��ʱ
����ֵ��		�ɹ������豸��������ʧ�ܷ��� <= 0
˵����	    �����豸
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_LoginDevice(char *lpszIP, int nPort, char *lpszUserName, char *lpszPassword, void* pReserved = NULL, int *pError = 0);

/********************************************************************************
������		NET_LogoutDevice
������		[in] lLoginID						�豸������
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		�ǳ��豸
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_LogoutDevice(LLONG lLoginID);

/********************************************************************************
������		NET_GetSessionID
������		[in] lLoginID						�豸������
����ֵ��		�ɹ�����������ID��ʧ�ܷ��� 0��
˵����		��ȡ�����ӻỰID
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_GetSessionID(LLONG lLoginID);

/////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
������		NET_RealPlay
������		[in] lLoginID						�豸������
			[in] nChannelID						ʵʱ����ͨ����
			[in] hWnd							ʵʱ���Ŵ��ھ��
			[in] emType							ʵʱ�����ͣ�Ĭ��ΪʵʱԤ��
����ֵ��		�ɹ�����ʵʱ���ž����ʧ�ܷ��� <= 0��
˵����		��ʼʵʱ���ӡ��û����øú���������ֱ����ָ�����ڲ���ʵʱ��Ƶ��
			�����ŵĴ���Ϊ NULL, ���û���Ҫ���ò��ſ���ؽӿڣ�ʵ�ֲ��ſ��ƣ�
			��ϸ���ÿ��Բμ� NetManagerDemos ֮ RealplayDemo
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_RealPlay(LLONG lLoginID, int nChannelID, HWND hWnd, EM_REALPLAY_STREAM_TYPE rType = REALPLAY_STREAM_TYPE_REAL);

/********************************************************************************
������		NET_StartRealPlay
������		[in] lLoginID						�豸������
			[in] nChannelID						ʵʱ����ͨ����
			[in] hWnd							ʵʱ���Ŵ��ھ��
			[in] emType							ʵʱ������
			[in] fRealDataCB					ʵʱ���ݻص�����������Ϊ NULL
			[in] fRealPlayDisconnCB				ʵʱ���ӶϿ��ص�����������Ϊ NULL
			[in] dwUser							�û�����
			[in] dwWaitTime						ʵʱ���ӳ�ʱʱ�䣨ms��
����ֵ��		�ɹ�����ʵʱ���Ӿ����ʧ�ܷ��� <= 0��
˵����		��ʼʵʱ���š�
			�û����Ե��øú�����ָ�����ڲ����豸ָ��ͨ����ָ���������͵���Ƶ����
			�����ŵĴ���Ϊ NULL, ���û���Ҫ���ò��ſ���ؽӿڣ�ʵ�ֲ��ſ��ƣ�
			��ϸ���ÿ��Բμ� NetManagerDemos ֮ RealplayDemo
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_StartRealPlay(LLONG lLoginID, int nChannelID, HWND hWnd, EM_REALPLAY_STREAM_TYPE rType, 
	fRealPlayDataCallBackEx fRealDataCB, fRealPlayDisConnectCallBack fRealPlayDisconnCB, LDWORD dwUser, DWORD dwWaitTime = 10000);

/********************************************************************************
������		NET_StopRealPlay
������		[in] lRealHandle							ʵʱ���Ӿ��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		ֹͣʵʱ����			
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StopRealPlay(LLONG lRealHandle);

/********************************************************************************
������		Net_StartTalkBack(��֧��Windows)
������		[in] lLoginID						�豸������
			[in] nChannelID						�����Խ�����ͨ����
			[in] rType							ʵʱ��Ƶ�����ͣ�Ĭ�� REALAUDIO_STREAM_TYPE_REAL_MASTER
			[in] cbRealData						ʵʱ�Խ����ݻص�����
			[in] dwUser							�Խ����ݻص��û�����
			[in] dwWaitTime						�Խ�����ʱʱ��
			[in] nVolLevel						�Խ������ȼ� 
												[-2��-1�� 0�� 1�� 2, 3, 4] �ȼ�Խ������Խ��
												0 ��ʾ��������
����ֵ��		�ɹ����������Խ������ʧ�ܷ��� <= 0��
˵����		��ʼ�����Խ����ӡ��û����øú��������Կ��������Խ�
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_StartTalkBack(LLONG lLoginID, int nChannelID, EM_REALAUDIO_STREAM_TYPE rType,
	fTalkBackDataCallBack cbRealData = NULL, LDWORD dwUser = 0, DWORD dwWaitTime = 3000, int nVolLevel = 0);

/********************************************************************************
������		Net_StopTalkBack(��֧��Windows)
������		[in] lTalkHandle							�����Խ����
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		ֹͣ�����Խ�			
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StopTalkBack(LLONG lTalkHandle);

/********************************************************************************
������		Net_SetTalkBackCallBack(��֧��Windows)
������		[in] lTalkHandle					�����Խ����
			[in] cbRealData						�豸�������Խ����ݻص�����
			[in] dwUser							�û�����
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		���������Խ����ݻص�
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_SetTalkBackCallBack(LLONG lTalkHandle, fTalkBackDataCallBack cbRealData, LDWORD dwUser);

/********************************************************************************
������		Net_SetTalkBackVolume(��֧��Windows)
������		[in] lTalkHandle					�����Խ����
			[in] nVolLevel						�Խ������ȼ� 
												[-2��-1�� 0�� 1�� 2, 3, 4] �ȼ�Խ������Խ��
												0 ��ʾ��������
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		���������Խ�������С
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_SetTalkBackVolume(LLONG lTalkHandle, int nVolLevel);

/********************************************************************************
������		NET_AdjustStrategyWhenPlayHD
������		[in] lPlayHandle						��Ƶ���ž��
			[in] bEnable							�Ƿ����ø��岥�Ų���
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		�������Ÿ�����Ƶ�Ĳ��Ų���
			�����ŵ�ָ������Ϊ NULL ʱ���ӿ���Ч����Ҫ���ò��ſ���ؽӿ�ʵ�֡�
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_AdjustStrategyWhenPlayHD(LLONG lPlayHandle, BOOL bEnable);

/********************************************************************************
������		NET_SetRealDataCallBack
������		[in] lRealHandle					ʵʱ���Ӿ��
			[in] cbRealData						ʵʱ�������ݻص�����
			[in] dwUser							�û�����
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		����ʵʱ�������ݻص�
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_SetRealDataCallBack(LLONG lRealHandle, fRealPlayDataCallBack cbRealData, LDWORD dwUser);

/********************************************************************************
������		NET_SetRealDataCallBack
������		[in] lRealHandle					ʵʱ���Ӿ��
			[in] cbRealData						ʵʱ�������ݻص�����
			[in] dwUser							�û�����
			[in] dwFlag							�������ͣ���ǰΪ 1��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		����ʵʱ�������ݻص�
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_SetRealDataCallBackEx(LLONG lRealHandle, fRealPlayDataCallBackEx cbRealData, LDWORD dwUser, DWORD dwFlag);

/********************************************************************************
������		NET_AdjustFluency
������		[in] lRealHandle					ʵʱ���Ӿ��
			[in] nLevel							������ֵ����Χ�� 0 - 6��
												ֵԽ��������Խ�ã�
												ֵԽ��ʵʱ��Խ�á�
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		����ͼ�������ԡ�
			ʵʱ������Ƶ��������Խ�ã�ʵʱ�Ծͻ�Խ�ͣ��û���Ҫѡ�����Ĳ���
            ��ʵʱ���ŵ�ָ������Ϊ NULL ʱ���ӿ���Ч����Ҫ���ò��ſ���ؽӿ�ʵ�֡�
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_AdjustFluency(LLONG lRealHandle, int nLevel);

/********************************************************************************
������		NET_SetDisplayRegion
������		[in] lPlayHandle					��Ƶ���ž��
			[in] nRegionNum						��Ƶ����ţ���ǰΪ 0��
			[in] pSrcRect						��Ƶ���ӷŴ�ֲ�����
			[in] hDestWnd						��Ƶ���Ŵ��ھ��
			[in] bEnable						�Ƿ���ӷŴ�
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		������Ƶ�ֲ��Ŵ�������ʾ
			�����ŵ�ָ������Ϊ NULL ʱ���ӿ���Ч����Ҫ���ò��ſ���ؽӿ�ʵ��
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_SetDisplayRegion(LLONG lPlayHandle, DWORD nRegionNum, STU_RECT_D *pSrcRect, HWND hDestWnd, BOOL bEnable);

/********************************************************************************
������		NET_StartSaveRealData
������		[in] lRealHandle					ʵʱ���Ӿ��
			[in] lpszFileName				    �������ݵ��ļ���
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		��ʼ��������Ϊ�ļ�
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StartSaveRealData(LLONG lRealHandle, const char *lpszFileName);

/********************************************************************************
������		BOOL NET_StopSaveRealData(LLONG lRealHandle)
������		[in] lRealHandle						ʵʱ���Ӿ��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		������������Ϊ�ļ�
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StopSaveRealData(LLONG lRealHandle);

/********************************************************************************
������		NET_SetVideoBasicEffect
������		[in] lPlayHandle						��Ƶ���ž��
			[in] nBrightness						����ֵ��0-128��
			[in] nContrast							�Աȶ�ֵ��0-128��
			[in] nHue								�Ҷ�ֵ��0-128��
			[in] nSaturation						���Ͷ�ֵ��0-128��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		������Ƶͼ����ʾ���ԣ����ú󲻻���Ч��ͼ������
			�����ŵ�ָ������Ϊ NULL ʱ���ӿ���Ч����Ҫ���ò��ſ���ؽӿ�ʵ��
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_SetVideoBasicEffect(LLONG lPlayHandle, unsigned char nBrightness, unsigned char nContrast, unsigned char nHue, unsigned char nSaturation);

/********************************************************************************
������		NET_GetVideoBasicEffect
������		[in] lPlayHandle						��Ƶ���ž��
			[out] nBrightness						����ֵ��0-128��
			[out] nContrast							�Աȶ�ֵ��0-128��
			[out] nHue								�Ҷ�ֵ��0-128��
			[out] nSaturation						���Ͷ�ֵ��0-128��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		��ȡͼ������
			�����ŵ�ָ������Ϊ NULL ʱ���ӿ���Ч����Ҫ���ò��ſ���ؽӿ�ʵ��
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_GetVideoBasicEffect(LLONG lPlayHandle, unsigned char *nBrightness, unsigned char *nContrast, unsigned char *nHue, unsigned char *nSaturation);

/********************************************************************************
������		Net_RegisterDrawCallBack
������		[in] cbDraw								��ͼ�ص�����
			[in] dwUser								�û�����
����ֵ��		/
˵����		������Ļ���ӻص����û�ע�����ͼ�ص������󣬿����ڸú����л�ͼ���ӵ���Ƶ�ϡ�
			���鲻Ҫ�ڸûص��������������ͼ�����������������Ƶ�ӳ�ʱ�䡣
*********************************************************************************/
NET_API void CALL_METHOD Net_RegisterDrawCallBack(fCustomDrawCallBack cbDraw, LDWORD dwUser);

/********************************************************************************
������		NET_CapturePicture
������		[in] lPlayHandle						��Ƶ���ž��
			[in] lpszPicFileName					ͼƬ�ļ�����
			[in] emFormat							ץ��ͼƬ��ʽ
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		ץͼ
			�����ŵ�ָ������Ϊ NULL ʱ���ӿ���Ч����Ҫ���ò��ſ���ؽӿ�ʵ��
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_CapturePicture(LLONG lPlayHandle, const char *lpszPicFileName, EM_SNAPSHOT_FORMAT_TYPE eFormat);

/********************************************************************************
������		LONG Net_GetStatisticFlux(LLONG lLoginID, LLONG lPlayHandle)
������		[in] lLoginID							�豸������
			[in] lPlayHandle						��Ƶ���ž��
����ֵ��		ʵʱ������С
˵����		�û���ȡ��ʵʱ������С����ֵ * 8 / 1024 = (x) kbps
*********************************************************************************/
NET_API LONG CALL_METHOD Net_GetStatisticFlux(LLONG lLoginID, LLONG lPlayHandle);

/********************************************************************************
������		Net_SetPlayMethod
������		[in] lRealHandle��						ʵʱ���Ӿ��	
			[in] nStartTime: 						��ʼ���ŵ�ʱ��(ms)
			[in] nSlowTime:  						��ʼ���ŵ�ʱ��(ms)
			[in] nFastTime:  						��ʼ��ŵ�ʱ��(ms)
			[in] nFailedTime: 						ʧ��ʱ�䣬������ʱ��������Ͷ��ʧ�ܣ�ms��
����ֵ��		�ɹ����� TURE��ʧ�ܷ��� FALSE��
˵����		�û�����ͨ���������ϲ�������ʵʱ���Ų��ԣ�ʵʱ��������Ч��
			��ʵʱ���ŵ�ָ������Ϊ NULL ʱ���ӿ���Ч����Ҫ���ò��ſ���ؽӿ�ʵ�֡�
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_SetPlayMethod(LLONG lRealHandle, int nStartTime, int nSlowTime, int nFastTime, int nFailedTime);

/********************************************************************************
������		NET_SetDataDrawEnable
������		[in] nRenderType						��Ⱦ����
													0-ʵʱ�� 1-����ط���
			[in] lHandle							���ž��
			[in] enable								��ͼʹ��
			[in] reserved							����λ
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		���û�����������ʹ�� 
			��ʵʱ���ŵ�ָ������Ϊ NULL ʱ���ӿ���Ч����Ҫ���ò��ſ���ؽӿ�ʵ�֡�
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_SetDataDrawEnable(int nRenderType, LLONG lHandle, BOOL enable, LONG reserved = 0);

/********************************************************************************
������		NET_OpenSound����Windows��
������		[in] lPlayHandle						��Ƶ���ž��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		������
			NET_OpenSound �� NET_CloseSound ����ʹ��
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_OpenSound(LLONG lPlayHandle);

/********************************************************************************
������		NET_SetVolume����Windows��
������		[in] lPlayHandle						��Ƶ���ž��
			[in] nVolume							������С��0-0xffff��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		����������Ե�������
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_SetVolume(LLONG lPlayHandle, int nVolume);

/********************************************************************************
������		NET_CloseSound����Windows��
������		/
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		�ر�����
			NET_OpenSound �� NET_CloseSound ����ʹ��
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_CloseSound();

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
������		Net_PreFindFile
������		[in] lLoginID					�豸������
			[in] nChannelId					��ѯ��ͨ����
			[in] emDBType					��ѯ�����ݿ����ͣ� �� 0 ��ʾ����ͼƬ���ݿ�
			[in] pstTimeStart				��ѯ�Ŀ�ʼʱ��
			[in] pstTimeEnd					��ѯ�Ľ���ʱ��
			[in] lpszEvents      			��ѯ�Ĺ����¼���������ʽ�� Json �ַ�����
			[in] lpszDirs					��ѯ�Ĺ���Ŀ¼��������ʽ�� Json �ַ�����
			[in] emVStreamType				��Ƶ��������
			[in] emOrderType				��ѯ��������
����ֵ��		�ɹ������ļ���ѯ�����ʧ�ܷ��� 0��
˵����		Ԥ��ѯ�ļ�
			��ȡ���ļ���ѯ�������Ҫ���ùرղ�ѯ�ӿڣ��ﵽ�ջ�����
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_PreFindFile(LLONG lLoginID, 
										  int nChannelId, 
										  EM_DATABASE_TYPE emDBType, 
										  P_STU_TIME pstTimeStart,
										  P_STU_TIME pstTimeEnd, 
										  char* lpszEvents = NULL,
										  char* lpszDirs = NULL,
										  EM_VIDEO_STREAM_TYPE emVStreamType = VIDEO_STREAM_ERROR,
										  EM_ORDER_TYPE emOrderType = ORDER_TYPE_DESCENT, 
										  int nWaitTime = 3000);

/********************************************************************************
������		Net_FindMultiFiles
������		[in] lLoginID						�豸������
			[in] lFindHandle					�ļ����Ҿ����Ԥ��ѯ�ļ���ȡ��
			[out] pnFileCount					��Ҫ���ҵ��ļ�����
			[in] nWaitTime						���ҳ�ʱʱ��
����ֵ��		�ɹ����� TRUE��ʧ�ܷ��� FALSE��
˵����		Ԥ��ѯ�ɹ�����ܵ���
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_FindFileCount(LLONG lLoginID, LLONG lFindHandle, int *pnFileCount, int nWaitTime = 2000);

/********************************************************************************
������		Net_FindOneFile
������		[in] lLoginID						�豸������
			[in] lFindHandle					�ļ����Ҿ����Ԥ��ѯ�ļ���ȡ��
			[out] lpFile						���ҵ����ļ�����Ϣ��
			[in] nWaitTime						���ҳ�ʱʱ��
����ֵ��		�ɹ����� 1��ʧ�ܷ���<=0��
˵����		Ԥ��ѯ�ɹ���һ��ֻ�ܲ���һ���ļ������Բ��ϲ�ѯֱ���ļ���ѯ����
			����ֵΪ 0 ˵��û�в�ѯ����< 0 ���ѯ����> 0 ���ѯ�� 1 ���ļ�
*********************************************************************************/
NET_API int CALL_METHOD Net_FindOneFile(LLONG lLoginID, LLONG lFindHandle, P_STU_T_FILE lpFile, int nWaitTime = 3000);

/********************************************************************************
������		Net_FindMultiFiles
������		[in] lLoginID						�豸������
			[in] lFindHandle					�ļ����Ҿ����Ԥ��ѯ�ļ���ȡ��
			[in] nFileCount						��Ҫ���ҵ��ļ�����
			[out] lpFileList					���ҵ����ļ��б�
			[out] nRealFileCount				ʵ�ʲ��ҵ����ļ�����
			[in] nWaitTime						���ҳ�ʱʱ��
����ֵ��		�ɹ����� TRUE��ʧ�ܷ��� FALSE��
˵����		Ԥ��ѯ�ɹ�����ܵ���
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_FindMultiFiles(LLONG lLoginID, LLONG lFindHandle, 
	int nFileCount, STU_T_FILE* lpFileList, int * pnRealFileCount, int nWaitTime = 10000);

/********************************************************************************
������		Net_CloseFindFile

������		[in] lLoginID						�豸������
			[in] lFindHandle					�ļ���ѯ���
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��ֹ�����ļ�
			�� NET_PreFindFile �ӿ�����ʹ��
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_CloseFindFile(LLONG lLoginID, LLONG lFindHandle, int nWaitTime = 3000);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
������		Net_PlayBackByRecordFile
������		[in] lLoginID					�豸������
			[in] lpRecordFile				¼���ļ�
			[in] hWnd						���Ŵ��ھ��
			[in] cdDownLoadPos				¼��طŽ��Ȼص�
			[in] dwPosUser					���Ȼص��е��û�����
			[in] fDataCB					¼��ط����ݻص�
			[in] dwDataUser					���ݻص��е��û�����
����ֵ��		�ɹ���������¼��طž����ʧ�ܷ��� <= 0��
˵����		���ļ���ʽ�ط�
			����¼��طųɹ�����Ҫ���ùر�����¼��طŽӿڣ��ﵽ�ջ�����
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_PlayBackByRecordFile(LLONG lLoginID, P_STU_T_FILE lpRecordFile, 
	HWND hWnd, fLoadPosCallBack cbDownLoadPos, LDWORD dwPosUser, fPlaybackDataCallBack fDataCB, LDWORD dwDataUser);

/********************************************************************************
������		Net_SeekPlayBackByTime
������		[in] lPlayHandle				����¼��طž��
			[in] pstTime					��λ��ʱ��㣨������ʼʱ��ͽ���ʱ��֮�䣩
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��λ¼��ط���ʼ��
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_SeekPlayBackByTime(LLONG lPlayHandle, STU_TIME* pstTime);

/********************************************************************************
������		Net_SeekPlayBack
������		[in] lPlayHandle				����¼��طž��
			[in] nOffsetTime				ƫ��ʱ�䣨��λ����/s��
			[in] nOffsetByte				ƫ���ֽڣ���λ���ֽ�/Byte��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��λ¼��ط���ʼ��
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_SeekPlayBack(LLONG lPlayHandle, unsigned int nOffsetTime, unsigned int nOffsetByte);

/********************************************************************************
������		Net_PausePlayBack
������		[in] lPlayHandle				����¼��طž��
			[in] bPause						�Ƿ���ͣ��TRUE ��ͣ��FALSE ����
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��ͣ��ָ�¼��ط�
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_PausePlayBack(LLONG lPlayHandle, BOOL bPause);

/********************************************************************************
������		Net_FastPlayBack
������		[in] lPlayHandle				����¼��طž��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		���¼��ط�
			����¼��Ŀ��Ч���ܵ��ն����ܺʹ���Ӱ�죬����ٶ����ŷ�Χ[1-8]
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_FastPlayBack(LLONG lPlayHandle);

/********************************************************************************
������		Net_SlowPlayBack
������		[in] lPlayHandle				����¼��طž��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		����¼��ط�
			ÿ����һ�β����ٶȼ��룬�����ٶ����ŷ�Χ��1/8 �C 1��
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_SlowPlayBack(LLONG lPlayHandle);

/********************************************************************************
������		Net_StepPlayBack
������		[in] lPlayHandle				����¼��طž��
			[in] bStop						�Ƿ�ֹͣ��������
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		����¼��ط�
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StepPlayBack(LLONG lPlayHandle, BOOL bStop);

/********************************************************************************
������		Net_NormalPlayBack
������		[in] lPlayHandle				����¼��طž��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		�ָ������ط��ٶ�
			���øýӿں󣬲����ٶȻָ�����
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_NormalPlayBack(LLONG lPlayHandle);

/********************************************************************************
������		Net_StopPlayBack(LLONG lPlayHandle)
������		[in] lPlayHandle				����¼��طž��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		ֹͣ¼��ط�
			�밴�ļ�����Żؽӿ�����ʹ�ã��ﵽ�ջ�����
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StopPlayBack(LLONG lPlayHandle);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
������		Net_RebootDevice
������		[in] lLoginID					�豸������
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		�����豸
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_RebootDevice(LLONG lLoginID);

/********************************************************************************
������		Net_ResetDevice
������		[in] lLoginID					�豸������
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		�ָ���������
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_ResetDevice(LLONG lLoginID);

/********************************************************************************
������		Net_ActivateDevice(�ݲ�����)
������		[in] stActivateInfo				�������
			[in] lpszLocalIp				ָ���������� IP
			[in] nWaitTime					��Ӧ��ʱʱ�䣨��λ ms��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		UDP����/�鲥�����豸
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_ActivateDevice(STU_DEVICE_ACTIVATE_INFO* stActivateInfo, char* lpszLocalIp = NULL, int nWaitTime = 3000);

/********************************************************************************
������		Net_ModifyDevice(�ݲ�����)
������		[in] pModifyInfo				�����޸Ĳ���
			[in] lpszLocalIp				ָ���������� IP
			[in] nWaitTime					��Ӧ��ʱʱ�䣨��λ ms��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		�޸��豸�������
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_ModifyDevice(STU_DEVICE_NETCFG_MODIFY_INFO *pModifyInfo, char* lpszLocalIp = NULL, int nWaitTime = 3000);

/********************************************************************************
������		ʹ���豸 telnet
������		[in] bEnable					�Ƿ�ʹ�� telnet
			[in] lpszDstIp					Ŀ�� IP
			[in] lpszLocalIp				���� IP
			[in] nWaitTime					��ʱʱ��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE
˵����		�޸��豸�������
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_SetDeviceTelnet(BOOL bEnable, char* lpszDstIp, char* lpszLocalIp = NULL, int nWaitTime = 3000);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
������		Net_GetDeviceCaps
������		[in] lLoginID					�豸��¼���
			[in] dwCommand					�豸������������
			[in] nChannel					�豸ͨ����(�� 0 ��ʼ, 0 ��ʾͨ�� 1��-1 ��ʾ��ʹ��ͨ��)
			[out] lpOutBuffer				���������Ϣ����Ӧ�������͵Ľṹ�壩
			[in] dwOutBufferSize			���������Ϣ��С
			[in] nWaitTime					��Ӧ��ʱʱ�䣨��λ ms��
����ֵ��	�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��ѯ������Ϣ
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_GetDeviceCaps(LLONG lLoginID, EM_DEVICE_CAPS_TYPE emType, LONG nChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, int nWaitTime = 2000);

/********************************************************************************
������		Net_GetDeviceCfg
������		[in] lLoginID					�豸��¼���
			[in] dwCommand					�豸������������
			[in] nChannel					�豸ͨ����(�� 0 ��ʼ, 0 ��ʾͨ�� 1��-1 ��ʾ��ʹ��ͨ��)
			[out] lpOutBuffer				���������Ϣ����Ӧ�������͵Ľṹ�壩
			[in] dwOutBufferSize			���������Ϣ��С
			[in] nWaitTime					��Ӧ��ʱʱ�䣨��λ ms��
����ֵ��	�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��ѯ������Ϣ
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_GetDeviceCfg(LLONG lLoginID, DWORD dwCommand, LONG nChannel, LPVOID lpOutBuffer, DWORD dwOutBufferSize, LPDWORD lpBytesReturned, int nWaitTime = 2000);

/********************************************************************************
������		Net_SetDeviceCfg
������		[in] lLoginID					�豸��¼���
			[in] dwCommand					�豸������������
			[in] nChannel					�豸ͨ����(�� 0 ��ʼ, 0 ��ʾͨ�� 1��-1 ��ʾ��ʹ��ͨ��)
			[in] lpInBuffer					����������Ϣ����Ӧ�������͵Ľṹ�壩
			[in] dwInBufferSize				����������Ϣ��С
			[in] nWaitTime					��Ӧ��ʱʱ�䣨��λ ms��
����ֵ��	�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		����������Ϣ
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_SetDeviceCfg(LLONG lLoginID, DWORD dwCommand, LONG nChannel, LPVOID lpInBuffer, DWORD dwInBufferSize, int nWaitTime = 2000);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
������		Net_SetDeviceCfg
������		[in] lLoginID					�豸��¼���
			[out] pSysInfo					�豸ϵͳ��Ϣ
			[in] nWaitTime					��Ӧ��ʱʱ�䣨��λ ms��
����ֵ��	�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��ȡ�豸ϵͳ��Ϣ
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_GetSysInfo(LLONG lLoginID, STU_SYS_INFO* pSysInfo, int nWaitTime = 2000);

/********************************************************************************
������		Net_GetSpecifiedSysInfo
������		[in] lLoginID					�豸��¼���
			[in] nType						ָ���豸ϵͳ��Ϣ����
											0 - ϵͳ������Ϣ ��Ӧ STU_SYS_INFO �ṹ��
											1 - ϵͳ�豸��Ϣ ��Ӧ STU_SYS_DEVICE_INFO �ṹ��
											2 - ϵͳ����汾��Ϣ ��Ӧ STU_SYS_SOFTWARE_VERSION �ṹ��
											3 - ϵͳӲ���汾��Ϣ ��Ӧ STU_SYS_HARDWARE_VERSION �ṹ��
											4 - ϵͳ��������Ϣ ��Ӧ STU_SYS_PROCESSOR_INFO �ṹ��
											5 - ϵͳ�ڴ���Ϣ ��Ӧ STU_SYS_MEMORY_INFO �ṹ��
			[out] pSysInfo					ָ�����豸ϵͳ��Ϣ
			[in] nSysInfoSize				ָ�����豸ϵͳ��Ϣ��С
			[in] nWaitTime					��Ӧ��ʱʱ�䣨��λ ms��
����ֵ��	�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��ȡָ�����豸ϵͳ��Ϣ
*********************************************************************************/ 
NET_API	BOOL CALL_METHOD Net_GetSpecifiedSysInfo(LLONG lLoginID, int nType, void* pSysInfo, int nSysInfoSize, int nWaitTime = 2000);

/********************************************************************************
������		Net_GetSerialNumber
������		[in] lLoginID					�豸������
			[out] lpszSerialNumber			�豸���к�
			[in] nSize						���к��ַ������С
			[in] nWaitTime					��ʱʱ�� (ms)
����ֵ��	�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��ȡ�豸���к�
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_GetSerialNumber(LLONG lLoginID, char* lpszSerialNumber, int nMaxSize, int nWaitTime = 1500);

/********************************************************************************
������		Net_GetDeviceTime
������		[in] lLoginID					�豸������
			[out] pDeviceTime				�豸ʱ��
			[in] nWaitTime					��ʱʱ�� (ms)
����ֵ��	�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��ȡ�豸��ǰʱ��
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_GetDeviceTime(LLONG lLoginID, STU_TIME* pDeviceTime, int nWaitTime = 1500);

/********************************************************************************
������		Net_SetDeviceTime
������		[in] lLoginID					�豸������
			[in] pDeviceTime				��ͬ�����豸ʱ��
			[in] nWaitTime					��ʱʱ�� (ms)
����ֵ��	�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		ͬ���豸ʱ��
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_SetDeviceTime(LLONG lLoginID, STU_TIME* pDeviceTime, int nWaitTime = 1500);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �û�����

/********************************************************************************
������		Net_GetDeviceUser
������		[in] lLoginID					�豸��¼���
			[out] cfgList					�û���Ϣ�б�
			[in] nWaitTime					��ʱʱ�䣬��λ��ms
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		��ȡ�û���Ϣ
*********************************************************************************/  
NET_API BOOL CALL_METHOD Net_GetDeviceUser(LLONG lLoginID, STU_CFG_USER_GET * cfgList, int nWaitTime);

/********************************************************************************
������		Net_AddDeviceUser
������		[in] lLoginID					�豸��¼���
			[out] cfgList					�û���Ϣ�б�
			[in] nWaitTime					��ʱʱ�䣬��λ��ms
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		����û���Ϣ
*********************************************************************************/  
NET_API BOOL CALL_METHOD Net_AddDeviceUser(LLONG lLoginID, STU_CFG_ADD_USER * cfgList, int nWaitTime);

/********************************************************************************
������		Net_DeleteDeviceUser
������		[in] lLoginID					�豸��¼���
			[out] cfgList					�û���Ϣ�б�
			[in] nWaitTime					��ʱʱ�䣬��λ��ms
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		ɾ���û���Ϣ
*********************************************************************************/  
NET_API BOOL CALL_METHOD Net_DeleteDeviceUser(LLONG lLoginID, STU_CFG_DELETE_USER * cfgList, int nWaitTime);

/********************************************************************************
������		Net_ModifyDeviceUser
������		[in] lLoginID					�豸��¼���
			[out] cfgList					�û���Ϣ�б�
			[in] nWaitTime					��ʱʱ�䣬��λ��ms
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		�޸��û���Ϣ
*********************************************************************************/  
NET_API BOOL CALL_METHOD Net_ModifyDeviceUser(LLONG lLoginID, STU_CFG_MODIFY_USER * cfgList, int nWaitTime);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
������		Net_StartUpgrade
������		[in] lLoginID							�豸������
			[in] lspzFileName						�����ļ��ľ���·��
			[in] fUpgradeCB							�����ص�����
			[in] dwUser								�û�����
����ֵ��		�ɹ������豸Զ�����������ʧ�ܷ���ֵ <= 0��
˵����		��ʼ�����豸����
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_StartUpgrade(LLONG lLoginID, char *lspzFileName, fDeviceUpgradeCallBack fUpgradeCB, LDWORD dwUser, int nWaitTime = 30 * 1000);

/********************************************************************************
������		Net_SendUpgrade(LLONG lUpgradeID)
������		[in] lUpgradeID							�豸Զ���������
����ֵ��	�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��������
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_SendUpgrade(LLONG lUpgradeID);

/********************************************************************************
������		Net_SendUpgrade(LLONG lUpgradeID)
������		[in] lUpgradeID							�豸Զ���������
����ֵ��	�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		���������豸����
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StopUpgrade(LLONG lUpgradeID);

/********************************************************************************
������		Net_UpgradeProgress(LLONG lUpgradeID)
������		[in] lLoginID							�豸��¼���
			[out] pstProgressInfo					������Ϣ
			[in] nWaitTime							��Ӧ��ʱʱ��(ms)
����ֵ��	�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��ȡ�豸���������ȣ����ݴ�����ɺ��豸�Ĵ�����ȣ�
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_UpgradeProgress(LLONG lLoginID, STU_UPGRADE_PROGRESS_INFO* pstProgressInfo, int nWaitTime = 2000);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
������		Net_ImportConfigFile
������		[in] lLoginID							�豸������
			[in] szFileName							���������ļ��ľ���·��
			[in] cbUploadPos						���������ļ����Ȼص�
			[in] dwUser								�û�����
����ֵ��		�ɹ����ص������þ����ʧ�ܷ���ֵ<=0��
˵����		���������ļ�
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_ImportConfigFile(LLONG lLoginID, char *szFileName, fLoadPosCallBack cbUploadPos, LDWORD dwUserData);

/********************************************************************************
������		Net_StopImportCfgFile
������		[in] lImportHandle						�豸���õ�����
����ֵ��	�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		ֹͣ���������ļ�
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StopImportCfgFile(LLONG lImportHandle);

/********************************************************************************
������		Net_ExportConfigFile
������		[in] lLoginID							�豸������
			[in] emConfigFileType					�����ļ�����
			[in] szSavedFilePath					���������ļ��ľ���·��
			[in] cbDownLoadPos						���������ļ����Ȼص�
			[in] dwUser								�û�����
����ֵ��		�ɹ����ص������þ����ʧ�ܷ���ֵ<=0��
˵����		�豸����ͨ�����ã����� emConfigFileType = CONFIG_FILE_ALL
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_ExportConfigFile(LLONG lLoginID, EM_DEVICE_CONFIG_TYPE emConfigFileType, char *szSavedFilePath, fLoadPosCallBack cbDownLoadPos, LDWORD dwUserData);

/********************************************************************************
������		Net_StopExportCfgFile
������		[in] lExportHandle						�豸���õ������
����ֵ��	�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		ֹͣ���������ļ�
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StopExportCfgFile(LLONG lExportHandle);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
������		Net_StartSearchDevices
������		[in] cbSearchDevices					�豸�����ص�����
			[in] pUserData							�û�����
			[in] szLocalIp							����IP��ַ
����ֵ��		�ɹ������豸���������ʧ�ܷ���ֵ<=0��
˵����		�첽�������������豸
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_StartSearchDevices(fSearchDevicesCallBack cbSearchDevices, void* pUserData, char* szLocalIp = NULL);

/********************************************************************************
������		Net_StopSearchDevices
������		[in] lSearchHandle						�豸�������
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		ֹͣ�첽�������������豸
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StopSearchDevices(LLONG lSearchHandle);

// �����ε��������豸
NET_API BOOL CALL_METHOD Net_SearchDevicesByIPs(STU_DEVICE_IP_SEARCH_INFO* pIpSearchInfo, fSearchDevicesCallBack cbSearchDevices, LDWORD dwUserData, char* lpszLocalIp, void* pReserved, int nWaitTime = 10 * 1000);

/********************************************************************************
������		Net_StartSearchDevicesByCondition
������		[in] pSearchCondition					������������
			[in] cbSearchDevices					�豸�����ص�����
			[in] pUserData							�û����ݲ���
			[in] szLocalIp							����IP��ַ
����ֵ��		�ɹ������豸���������ʧ�ܷ���ֵ<=0��
˵����		ָ���������������豸
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_StartSearchDevicesByCondition(STU_DEVICE_SEARCH_CONDITION_INFO* pSearchCondition, fSearchDevicesCallBack cbSearchDevices, void* pUserData, char* szLocalIp = NULL);


///////////////////////////////////////////////////////////////////////////////////////////////////////////
// �����豸�ӿ�

/********************************************************************************
������		Net_RealLoadPicture
������		[in] lLoginID				�豸������
			[in] nChannelID				����ͨ����
			[in] dwEventType			�����¼�����
			[in] nDataType				�����õķ��ص���������
										-1 - ���������ݣ�0-ֻ����������Ϣ��1-����������Ϣ��ͼƬ����
			[in] cbAnalyzeData			���ܷ������ݻص�����
			[in] dwUser				    �û�����
			[in] pReserved				Ԥ��λ
����ֵ��		�ɹ�������������ʵʱ���ľ����ʧ�ܷ���ֵ<=0��
˵����		��ͨ�����¼����ģ�֧�������¼����ģ�
            �û����Զ�ε��� Net_RealLoadPicture �����Ĳ�ͬͨ���Ĳ�ͬ�¼���ע��ά�����ľ���������ͷ�
			ʵʱ�ϴ����ܷ������ݣ��û����Ը��ݶ��ĵ��¼����ͣ���ȡ�豸��ָ�����ܷ�������
			�ͻ���ֱ�ӶԽ��豸ʱ����, �� Net_StopLoadPicture ���ʹ�ã��ջ�����
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_RealLoadPicture(
	LLONG lLoginID, 
	int nChannelID, 
	DWORD dwEventType,
	int nDataType, 
	fAnalyzeDataCallBack cbAnalyzerData, 
	LDWORD dwUser,
	void* pReserved);

/********************************************************************************
������		Net_RealLoadMultiTypePicture
������		[in] lLoginID				�豸������
			[in] nChannelIDArr			����ͨ��������
			[in] nChannelNum			����ͨ������Ŀ��������ͨ��������Ԫ�ظ���һ�£�
			[in] dwEventTypeArr			�����¼���������
			[in] nEventTypeNum			�����¼�������Ŀ�������������¼���������Ԫ�ظ���һ�£�
			[in] nDataType				�����õķ��ص���������
										-1 - ���������ݣ�0-ֻ����������Ϣ��1-����������Ϣ��ͼƬ����
			[in] cbAnalyzeData			���ܷ������ݻص�����
			[in] dwUser				    �û�����
			[in] pReserved				Ԥ��λ
����ֵ��		�ɹ�������������ʵʱ���ľ����ʧ�ܷ���ֵ<=0��
˵����		��ͨ�����¼�����
			�����Ҫ���������¼�����ʹ�� Net_RealLoadPicture���¼�����ѡ�� EVENT_SP_ALL
			ʵʱ�ϴ����ܷ������ݣ��û����Ը��ݶ��ĵ��¼����ͣ���ȡ�豸��ָ�����ܷ�������	
			�ͻ���ֱ�ӶԽ��豸ʱ����, �� Net_StopLoadPicture ���ʹ�ã��ջ�����
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_RealLoadMultiTypePicture(
	LLONG lLoginID, 
	int* nChannelIDArr,
	int nChannelNum, 
	DWORD* dwEventTypeArr, 
	int nEventTypeNum, 
	int nDataType, 
	fAnalyzeDataCallBack cbAnalyzeData,
	LDWORD dwUser, 
	void* pReserved);

/********************************************************************************
������		Net_RealLoadPicture
������		[in] lLoginID				�豸������
			[in] nChannelID				����ͨ����
			[in] dwEventType			�����¼�����
			[in] nDataType				�����õķ��ص���������
										-1 - ���������ݣ�0-ֻ����������Ϣ��1-����������Ϣ��ͼƬ����
			[in] cbAnalyzeData			���ܷ������ݻص�����
			[in] dwUser				    �û�����
			[in] pReserved				Ԥ��λ
����ֵ��		�ɹ�������������ʵʱ���ľ����ʧ�ܷ���ֵ<=0��
˵����		��ͨ�����¼����ģ�֧�������¼����ģ�
            �û����Զ�ε��� Net_LoadOfflinePicture �����Ĳ�ͬͨ���Ĳ�ͬ�¼���ע��ά�����ľ���������ͷ�
			ʵʱ�ϴ����ܷ������ݣ��û����Ը��ݶ��ĵ��¼����ͣ���ȡ�豸��ָ�����ܷ�������
			�ͻ���ֱ�ӶԽ��豸ʱ����, �� Net_StopLoadPicture ���ʹ�ã��ջ�����
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_LoadOfflinePicture(
	LLONG lLoginID, 
	int nChannelID, 
	DWORD dwEventType,
	int nDataType, 
	fAnalyzeDataCallBack cbAnalyzerData, 
	LDWORD dwUser,
	void* pReserved);

/********************************************************************************
������		Net_StopLoadPicture
������		[in] lLoadHandle			�������ݶ��ľ��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		ֹͣ�ϴ����ܷ�������(������Ϣ&ͼƬ����)
			�� Net_RealLoadPicture/Net_LoadOfflinePicture ���ʹ�ã��ջ�����
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StopLoadPicture(LLONG lLoadHandle);

/********************************************************************************
������		Net_StartRecvNetPicStream
������		[in] lLoginID					�豸��¼���
			[in] pstNetPicParam				ͼƬ���Ĳ���
			[in] nParamSize					ͼƬ���Ĳ�����С
			[out] pRecvHandle				ͼƬ�����վ��
			[in] bLoadSingle				�Ƿ�����ͼ
											����ǵ�����ͼ��fNetPicStreamCallBackCV1 �ص���
											ͼƬ����ʼ��ֻ��һ�ű���ͼ��������ͼ
											���豸�����ò�ץȡ����ͼʱ��bLoadSingle ������ TRUE
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		��ʼʵʱ�ϴ����ܷ������ݣ�����ͼƬ��
			�ͻ���ֱ�ӶԽ��豸ʱ����, ������������ⱳ��ͼ��������ͼ
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StartRecvNetPicStream(LLONG lLoginID, 
	NetPicParamCV1* pstNetPicParam, 
	int nParamSize, 
	LLONG* pRecvHandle, 
	BOOL bLoadSingle = FALSE);

/********************************************************************************
������		Net_StopRecvNetPicStream
������		[in] lRecvHandle				ͼƬ�����վ��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		ֹͣʵʱ����ͼƬ���� Net_StartRecvNetPicStream ���ʹ�ã��ջ�����
            �ͻ���ֱ�ӶԽ��豸ʱ����
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StopRecvNetPicStream(LLONG lRecvHandle);

/********************************************************************************
������		Net_StartRecvNetPicStreamByCloud
������		[in] lLoginID					�豸��¼���
			[in] pstNetPicParam				ͼƬ���Ĳ���
			[in] nParamSize					ͼƬ���Ĳ�����С
			[out] pRecvHandle				ͼƬ�����վ��
			[in] bLoadSingle				�Ƿ�����ͼ
											����ǵ�����ͼ��fNetPicStreamCallBackCV1 �ص���
											ͼƬ����ʼ��ֻ��һ�ű���ͼ��������ͼ
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		��ʼʵʱ�ϴ����ܷ������ݣ�����ͼƬ��
			�ͻ���ͨ���Ʒ���Խ��豸ʱ���ã�������������ⱳ��ͼ��������ͼ
			���óɹ�֮���豸ץͼ�����лῪ����ʾ����ͼ
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StartRecvNetPicStreamByCloud(LLONG lLoginID, 
	NetPicParamCV1* pstNetPicParam,
	int nParamSize, 
	LLONG* pRecvHandle, 
	BOOL bLoadSingle = FALSE);

/********************************************************************************
������		Net_StopRecvNetPicStreamByCloud
������		[in] lRecvHandle				ͼƬ�����վ��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		ֹͣʵʱ����ͼƬ���� Net_StartRecvNetPicStreamByCloud ���ʹ�ã��ջ�����
            �ͻ���ͨ���Ʒ���Խ��豸ʱ����
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StopRecvNetPicStreamByCloud(LLONG lRecvHandle);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
������		Net_DownLoadMultiFile
������		[in] lLoginID					�豸������
			[in] pstInParam					���ļ������������
			[out] pstOutParam				���ļ������������
			[in] nWaitTime					��ʱ�ȴ�ʱ�䣨��λ�� ms��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		���������ļ�
			��Net_ StopLoadMultiFile����ʹ�ã�
			��������д��ж��ļ����ؾ�����ڹرվ��ʱʹ��
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_DownLoadMultiFile(LLONG lLoginID, STU_IN_MULTI_FILE_DOWNLOAD_PARAM *pstInParam, STU_OUT_MULTI_FILE_DOWNLOAD_PARAM *pstOutParam, int waittime = 5000);

/********************************************************************************
������		Net_StopLoadMultiFile
������		[in] lDownLoadHandle			�ļ����ؾ��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		ֹͣ����
			��Net_DownLoadMultiFile����ʹ��
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StopLoadMultiFile(LLONG lDownLoadHandle);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
������		Net_TransJsonByRpc
������		[in] lLoginID					�豸������
			[in] szInBuffer					�豸����������Ϣ��Json��ʽ��
			[in] dwInBufferSize				����������Ϣ��С
			[in] szOutBuffer				���ú�Ӧ����Ϣ��Json��ʽ��
			[in] dwOutBufferSize			Ӧ����Ϣ��С
			[in] pReserved					Ԥ������
			[in] nWaitTime					���ݷ��ͳ�ʱʱ�� (ms)
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��JSON ��ʽ��Э������豸����
			�û����Ը�������Ҫ����豸��������
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_TransJsonByRpc(
	LLONG lLoginID, 
	char* szInBuffer, 
	DWORD dwInBufferSize, 
	char* szOutBuffer, 
	DWORD dwOutBufferSize, 
	void* pReserved,
	int nWaitTime = 6000);

/********************************************************************************
������		Net_TransDataByRpc
������		[in] lLoginID					�豸������
			[in] szInBuffer					�豸����������Ϣ��Json��ʽ��
			[in] dwInBufferSize				����������Ϣ��С
			[in] szOutBuffer				���ú�Ӧ����Ϣ��Json��ʽ��
			[in] dwOutBufferSize			Ӧ����Ϣ��С
			[in] pReserved					Ԥ������
			[in] nWaitTime					���ݷ��ͳ�ʱʱ�� (ms)
			[in] pBinData					����������			
			[out] pRetJsonLen				���ص�Json���ݳ���
			[out] pRetBinLen				���صĶ��������ݳ���
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��JSON ��ʽ��Э������豸����
			�û����Ը�������Ҫ����豸��������
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_TransDataByRpc(
	LLONG lLoginID, 
	char* szInBuffer, 
	DWORD dwInBufferSize, 
	char* szOutBuffer, 
	DWORD dwOutBufferSize, 
	void* pReserved,
	int nWaitTime = 6000,
	STU_BIN_DATA* pBinData = NULL, 
	int* pRetJsonLen = NULL, 
	int* pRetBinLen = NULL);

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// ����ע��ӿ�

/********************************************************************************
������		Net_RegStartServer���ݲ�֧�֣�
������		[in] lpszIP						���� IP ��ַ
			[in] nPort						�����˿�
			[in] cbListen					�����������ص�����
			[in] dwUserData					�û����ݲ���
����ֵ��		�ɹ��������������������>0����ʧ�ܷ��� 0��
˵����		����ע�Ṧ�ܣ���������
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_RegStartServer(
	char* lpszIP,
	WORD nPort, 
	fRegServerCallBack cbListen, 
	LDWORD dwUserData);

/********************************************************************************
������		Net_RegStopServer���ݲ�֧�֣�
������		[in] lServerHandle				�������������
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		����ע�Ṧ�ܣ�ֹͣ����
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_RegStopServer(LLONG lServerHandle);

/********************************************************************************
������		Net_RegAccept���ݲ�֧�֣�
������		[in] lpszDevSerial
			[in] lpszIP
			[in] nPort
			[in] bAccept
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		����ע�Ṧ�ܣ���Ӧ�豸��ע������
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_RegAccept(char* lpszDevSerial, char* lpszIP, WORD nPort, BOOL bAccept);

///////////////////////////////////////////////////////////////////////////////////////////////////////////
// ������ & ��������

/********************************************************************************
������		Net_CreateFaceGroup
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_FACE_GROUP_CREATE_IN_PARAM��
			[out] pOutParam					�������	���� STU_FACE_GROUP_CREATE_OUT_PARAM��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		����������
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_CreateFaceGroup(LLONG lLoginID, STU_FACE_GROUP_CREATE_IN_PARAM* pInParam, STU_FACE_GROUP_CREATE_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_DeleteFaceGroup
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_FACE_GROUP_DELETE_IN_PARAM��
			[out] pOutParam					�������	���� STU_FACE_GROUP_DELETE_OUT_PARAM��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		ɾ��������
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_DeleteFaceGroup(LLONG lLoginID, STU_FACE_GROUP_DELETE_IN_PARAM* pInParam, STU_FACE_GROUP_DELETE_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_EditFaceGroup
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_FACE_GROUP_EDIT_IN_PARAM��
			[out] pOutParam					�������	���� STU_FACE_GROUP_EDIT_OUT_PARAM��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		�༭������
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_EditFaceGroup(LLONG lLoginID, STU_FACE_GROUP_EDIT_IN_PARAM* pInParam, STU_FACE_GROUP_EDIT_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_GetAllFaceGroups
������		[in] lLoginID					�豸��¼���
			[out] pOutParam					�������	���� STU_FACE_GROUP_ARRAY_INFO��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��ȡ������������Ϣ
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_GetAllFaceGroups(LLONG lLoginID, STU_FACE_GROUP_ARRAY_INFO* pOutInfo);

////////////////////////////////////////////////////////

/********************************************************************************
������		Net_AddPersonInfo
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_FACE_ADD_IN_PARAM��
			[out] pOutParam					�������	���� STU_FACE_ADD_OUT_PARAM��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		�����Ա��Ϣ&��Ա����ͼ
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_AddPersonInfo(LLONG lLoginID, 
	STU_FACE_ADD_IN_PARAM* pInParam, STU_FACE_ADD_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_AddPersonInfoOnly
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_PERSON_INFO_ADD_IN_PARAM��
			[out] pOutParam					�������	���� STU_PERSON_INFO_ADD_OUT_PARAM��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		�������Ա��Ϣ
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_AddPersonInfoOnly(LLONG lLoginID, 
	STU_PERSON_INFO_ADD_IN_PARAM* pInParam, STU_PERSON_INFO_ADD_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_UpdatePersonInfo
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_PERSON_INFO_UPDATE_IN_PARAM��
			[out] pOutParam					�������	���� STU_PERSON_INFO_UPDATE_OUT_PARAM��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		������Ա��Ϣ
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_UpdatePersonInfo(LLONG lLoginID, 
	STU_PERSON_INFO_UPDATE_IN_PARAM* pInParam, STU_PERSON_INFO_UPDATE_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_DeletePersonInfo
������		[in] lLoginID					�豸��¼���
			[in] nPersonID					��ԱID		
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		ɾ����Ա��Ϣ
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_DeletePersonInfo(LLONG lLoginID, unsigned int nPersonID);

/********************************************************************************
������		Net_AddPersonFaceImage
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_FACE_IMAGE_ADD_IN_PARAM��
			[out] pOutParam					�������	���� STU_FACE_IMAGE_ADD_OUT_PARAM��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		�����Ա����ͼ
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_AddPersonFaceImage(LLONG lLoginID, 
	STU_FACE_IMAGE_ADD_IN_PARAM* pInParam, STU_FACE_IMAGE_ADD_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_DeletePersonFaceImage
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_FACE_IMAGE_DELETE_IN_PARAM��
			[out] pOutParam					�������	���� STU_FACE_IMAGE_DELETE_OUT_PARAM��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		ɾ����Ա����ͼ
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_DeletePersonFaceImage(LLONG lLoginID, 
	STU_FACE_IMAGE_DELETE_IN_PARAM* pInParam, STU_FACE_IMAGE_DELETE_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_UpdatePersonFaceImage
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_FACE_IMAGE_UPDATE_IN_PARAM��
			[out] pOutParam					�������	���� STU_FACE_IMAGE_UPDATE_OUT_PARAM��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		������Ա����ͼ
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_UpdatePersonFaceImage(LLONG lLoginID, 
	STU_FACE_IMAGE_UPDATE_IN_PARAM* pInParam, STU_FACE_IMAGE_UPDATE_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_BindFaceToGroup
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_FACE_BIND_GROUP_IN_PARAM��
			[out] pOutParam					�������	���� STU_FACE_BIND_GROUP_OUT_PARAM��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��Ա����ͼ�󶨵�������
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_BindFaceToGroup(LLONG lLoginID, 
	STU_FACE_BIND_GROUP_IN_PARAM* pInParam, STU_FACE_BIND_GROUP_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_UnBindFaceFromGroup
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_FACE_UNBIND_GROUP_IN_PARAM��
			[out] pOutParam					�������	���� STU_FACE_UNBIND_GROUP_OUT_PARAM��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		��Ա����ͼ����������
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_UnBindFaceFromGroup(LLONG lLoginID, 
	STU_FACE_UNBIND_GROUP_IN_PARAM* pInParam, STU_FACE_UNBIND_GROUP_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_AsyncAddPersonInfo
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_FACE_ADD_IN_PARAM��
			[out] pOutParam					�������	���� STU_FACE_ADD_OUT_PARAM��
����ֵ��		�ɹ�����TRUE��ʧ�ܷ���FALSE��
˵����		�첽�����Ա��Ϣ&��Ա����ͼ��ֻ��ӵ��豸������ģ��
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_AsyncAddPersonInfo(LLONG lLoginID,
	STU_FACE_ADD_IN_PARAM* pInParam, STU_FACE_ADD_OUT_PARAM* pOutParam);

////////////////////////////////////////////////////////
// ������Ϣ���Ҳ���

/********************************************************************************
������		Net_PreFindFaceInfo
������		[in] lLoginID					�豸��¼���
			[out] pnFindInstance			��������ʵ��
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		Ԥ��ʼ����������Ϣ���ɹ������ִ�в���������Ϣ����
            �� Net_CloseFindFaceInfo ���ʹ��
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_PreFindFaceInfo(LLONG lLoginID, unsigned int * pnFindInstance);

/********************************************************************************
������		Net_CloseFindFaceInfo
������		[in] lLoginID					�豸��¼���

����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		��ֹ����������Ϣ���ɹ����������Ҿ����Ч��
            ������ Net_PreFindFaceInfo ���ʹ��
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_CloseFindFaceInfo(LLONG lLoginID, unsigned int nFindInstance);

/********************************************************************************
������		Net_StartFindFaceInfo
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_FACE_UNBIND_GROUP_IN_PARAM��
			[out] pOutParam					�������	���� STU_FACE_UNBIND_GROUP_OUT_PARAM��
											��������� nFindHandle ����������Ϣ���Ҿ�� 
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		��ʼ����������Ϣ; Net_PreFindFaceInfo Ԥ��ѯ�ɹ�����Ե���
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_StartFindFaceInfo(LLONG lLoginID, STU_FACE_INFO_FIND_IN_PARAM* pInParam, STU_FACE_INFO_FIND_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_GetFaceInfoFindResult
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_FACE_INFO_FIND_RESULT_IN_PARAM��
			[out] pOutParam					�������	���� STU_FACE_INFO_FIND_RESULT_OUT_PARAM��
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		��ȡ���ҵ�������Ϣ��Net_StartFindFaceInfo ��ѯ�ɹ�����Ե���
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_GetFaceInfoFindResult(LLONG lLoginID,
	STU_FACE_INFO_FIND_RESULT_IN_PARAM* pInParam, STU_FACE_INFO_FIND_RESULT_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_GetPersonCount
������		[in] lLoginID					�豸��¼���
			[in] nFindInstance				��������ʵ��
			[out] pnPersonCount				��ѯ������Ա��Ŀ
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		��ȡ��ǰ��ѯ�����µ���Ա��Ŀ��Net_StartFindFaceInfo ��ѯ�ɹ�����Ե���
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_GetPersonCount(LLONG lLoginID, unsigned int nFindInstance, int* pnPersonCount);

/********************************************************************************
������		Net_GetFaceCount
������		[in] lLoginID					�豸��¼���
			[in] nFindInstance				��������ʵ��
			[out] pnFaceCount				��ѯ����������Ŀ
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		��ȡ��ǰ��ѯ�����µ�������Ŀ��Net_StartFindFaceInfo ��ѯ�ɹ�����Ե���
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_GetFaceCount(LLONG lLoginID, unsigned int nFindInstance, int* pnFaceCount);

/********************************************************************************
������		Net_GetFaceImage
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_FACE_IMAGE_GET_IN_PARAM��
			[out] pOutParam					����������� STU_FACE_IMAGE_GET_OUT_PARAM��
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		��ȡ����ͼƬ�����浽���أ�Net_PreFindFaceInfo Ԥ��ѯ�ɹ�����Ե���
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_GetFaceImage(LLONG lLoginID,
	STU_FACE_IMAGE_GET_IN_PARAM *pInParam, STU_FACE_IMAGE_GET_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_GetPersonInfoByToken
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_PERSON_INFO_GET_BYTOKEN_IN_PARAM��
			[out] pOutParam					����������� STU_PERSON_INFO_GET_BYTOKEN_OUT_PARAM��
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		ͨ������ͼ��ʶ��ȡ������Ϣ��Net_PreFindFaceInfo Ԥ��ѯ�ɹ�����Ե���
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_GetPersonInfoByToken(LLONG lLoginID,
	STU_PERSON_INFO_GET_BYTOKEN_IN_PARAM *pInParam, STU_PERSON_INFO_GET_BYTOKEN_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_GetPeronInfoByID
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_PERSON_INFO_GET_BYID_IN_PARAM��
			[out] pOutParam					����������� STU_PERSON_INFO_GET_BYID_OUT_PARAM��
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		ͨ������֤��&ID��ȡ������Ϣ��Net_PreFindFaceInfo Ԥ��ѯ�ɹ�����Ե���
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_GetPersonInfoByID(LLONG lLoginID,
	STU_PERSON_INFO_GET_BYID_IN_PARAM* pInParam, STU_PERSON_INFO_GET_BYID_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_GetPeronInfoByID
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_FACE_IMAGE_INFO_GET_IN_PARAM��
			[out] pOutParam					����������� STU_FACE_IMAGE_INFO_GET_OUT_PARAM��
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		��ȡ����ͼ��Ϣ��Net_PreFindFaceInfo Ԥ��ѯ�ɹ�����Ե���
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_GetFaceImageInfo(LLONG lLoginID,
	STU_FACE_IMAGE_INFO_GET_IN_PARAM* pInParam, STU_FACE_IMAGE_INFO_GET_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_CheckPersonNameSuffix
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_PERSON_NAME_CHECK_IN_PARAM��
			[out] pOutParam					����������� STU_PERSON_NAME_CHECK_OUT_PARAM��
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		У�������������������׺��Net_PreFindFaceInfo Ԥ��ѯ�ɹ�����Ե���
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_CheckPersonNameSuffix(LLONG lLoginID,
	STU_PERSON_NAME_CHECK_IN_PARAM* pInParam, STU_PERSON_NAME_CHECK_OUT_PARAM* pOutParam);

////////////////////////////////////////////////////////
// ����ʶ���¼

/********************************************************************************
������		Net_PreFindFaceRecognitionRecord
������		[in] lLoginID					�豸��¼���
			[out] pnFindInstance			����ʵ��
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		Ԥ��ѯ�����ȶԼ�¼
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_PreFindFaceRecognitionRecord(LLONG lLoginID, unsigned int * pnFindInstance);

/********************************************************************************
������		Net_StartFindFaceRecognitionRecord
������		[in] lLoginID					�豸��¼���
			[in] pnFindInstance				����ʵ��
			[in] pInParam					����������� STU_FACE_REC_REC_FIND_IN_PARAM��
			[out] pOutParam					����������� STU_FACE_REC_REC_FIND_OUT_PARAM��
											��������� nFindHandle ������ʶ��Ͳ�ѯ���
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		��ʼ��ѯ�����ȶԼ�¼
            Net_PreFindFaceRecognitionRecord �ɹ���ɵ���
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_StartFindFaceRecognitionRecord(LLONG lLoginID,
	STU_FACE_REC_REC_FIND_IN_PARAM* pInParam, STU_FACE_REC_REC_FIND_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_CloseFindFaceRecognitionRecord
������		[in] lLoginID					�豸��¼���
			[in] nFindInstance			    ��¼���Ҿ��
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		�رղ�ѯ�����ȶԼ�¼���� Net_PreFindFaceRecognitionRecord ���ʹ��
            �رպ�����ʶ���¼���Ҿ����Ч
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_CloseFindFaceRecognitionRecord(LLONG lLoginID, unsigned int nFindInstance);

/********************************************************************************
������		Net_GetFaceRecognitionRecordResult
������		[in] lLoginID					�豸��¼���
			[in] pInParam					����������� STU_FACE_REC_REC_FIND_RESULT_IN_PARAM��
			[out] pOutParam					����������� STU_FACE_REC_REC_FIND_RESULT_OUT_PARAM��
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		��ȡ�����ȶԼ�¼��Net_StartFindFaceRecognitionRecord ��ѯ����Ե���
*********************************************************************************/ 
NET_API BOOL CALL_METHOD Net_GetFaceRecognitionRecordResult(LLONG lLoginID,
	STU_FACE_REC_REC_FIND_RESULT_IN_PARAM* pInParam, STU_FACE_REC_REC_FIND_RESULT_OUT_PARAM* pOutParam);

/********************************************************************************
������		Net_GetFaceRecognitionRecordCount
������		[in] lLoginID					�豸��¼���
			[out] pnRecordCount				�����ȶԼ�¼����
����ֵ��		�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		��ȡ�����ȶԼ�¼������Net_StartFindFaceRecognitionRecord ��ѯ����Ե���
*********************************************************************************/  
NET_API BOOL CALL_METHOD Net_GetFaceRecognitionRecordCount(LLONG lLoginID, unsigned int nFindInstance, unsigned int* pnRecordCount);

/********************************************************************************
������		Net_LoadFaceExtractInfo
������		[in] lLoginID							��¼���
            [in] emType								��������
			[in] cbFaceExtInfo						��Ϣ�ص�
			[in] dwUser								�û�����	
����ֵ��		�ɹ����ض��ľ��
˵����		������ģ������������ģ��Ϣ
			��ģ֮ǰ��Ҫ��֤�豸�׿�����δ��ģ��ͼƬ
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_StartLoadFaceExtractInfo(LLONG lLoginID, 
	EM_FACE_EXTRACT_OPERATE_TYPE emType, fFaceFeatureExtInfoCallBack cbFaceExtInfo, LDWORD dwUser);

/********************************************************************************
������		Net_StopLoadFaceExtractInfo
������		[in] lHandle							���ľ��
����ֵ��		�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		ֹͣ����������ģ��Ϣ
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StopLoadFaceExtractInfo(LLONG lHandle);

/********************************************************************************
������		Net_StartLoadCfgModifyInfo
������		[in] lLoginID							��¼���
            [in] lpszCfgTable						���ñ�����
			[in] cbCfgModifyInfo					��Ϣ�ص�
			[in] dwUser								�û�����	
����ֵ��		�ɹ����ض��ľ��
˵����		�������øĶ���Ϣ����
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_StartLoadCfgModifyInfo(LLONG lLoginID, const char* lpszCfgTable, fCfgModifyInfoCallBack cbCfgModifyInfo, LDWORD dwUser);

/********************************************************************************
������		Net_StopLoadCfgModifyInfo
������		[in] lHandle							���ľ��
����ֵ��		�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		ֹͣ���øĶ���Ϣ����
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StopLoadCfgModifyInfo(LLONG lLoginID);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
������		Net_StartEventSubscribe
������		[in] lLoginID							�豸������
			[in] nChannelID							�豸ͨ����
����ֵ��		�ɹ����ر��������ʧ�ܷ��� <= 0��
˵����		�������ģ�ָ�����Ļص�����
*********************************************************************************/
NET_API LLONG CALL_METHOD Net_StartEventSubscribe(LLONG lLoginID,
	fAlarmInfoCallBack cbAlarmInfo, LDWORD dwUser = 0, DWORD dwWaitTime = 3000);

/********************************************************************************
������		Net_EventSubscribe
������			
			[in] lAlarmHandle						�������
			[in] nType								ΪEM_ALARM_TYPEö�����ͣ�ȡֵΪ-1ʱ�����������¼�
			[in] nChannelID							�豸ͨ����
����ֵ��		�ɹ�����0��ʧ�ܷ��� < 0��
˵����		����eType��ָ���ĵ��������¼�����
			�ýӿڿ��Զ�α����ã�����ֻ�ܶ���һ�������¼��������б����¼�
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_EventSubscribe(LLONG lAlarmHandle, int nChannelID, int nType, DWORD dwWaitTime = 3000);

/********************************************************************************
������		Net_UnEventSubscribe
������		[in] lAlarmHandle						�������
			[in] nType								ΪEM_ALARM_TYPEö�����ͣ�ȡֵΪ-1ʱ����ȡ�����������¼�
			[in] nChannelID							�豸ͨ����
			
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		ȡ���¼�����
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_UnEventSubscribe(LLONG lAlarmHandle, int nChannelID, int nType);
	
/********************************************************************************
������		Net_StopEventSubscribe
������		[in] lAlarmHandle						�������
			
����ֵ��		�ɹ�����TRUE��ʧ�ܷ��� FALSE��
˵����		ֹͣ�¼�����
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_StopEventSubscribe(LLONG lAlarmHandle);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

/********************************************************************************
������		Net_ImageWaterMarkCheck
������		[in] lpszImagePath						����ͼƬ·��
����ֵ��		�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		ͼƬˮӡУ��
*********************************************************************************/
NET_API BOOL CALL_METHOD Net_ImageWaterMarkCheck(const char* lpszImagePath);

///////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
#endif // _AL_NET_MANAGER_LIB_H