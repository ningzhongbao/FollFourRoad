#ifndef _AL_PLAY_V1_H
#define _AL_PLAY_V1_H

#if (defined(WIN32) || defined(WIN64))
#ifdef PLAYMS_API_EXPORTS
#define PLAYMS_API __declspec(dllexport)
#else
#define PLAYMS_API __declspec(dllimport)
#endif
#define CALLBACK   __stdcall
#define CALLMETHOD __stdcall
#else
#define CALLMETHOD
#define CALLBACK
#define PLAYMS_API
#endif

#if defined(WIN32) || defined(WIN64)
	#include <windows.h>
#else
	#ifdef __OBJC__
		#include "objc/objc.h"
	#endif

#ifndef BYTE
	#define BYTE		unsigned char
#endif

#ifndef PBYTE
	#define PBYTE		BYTE*
#endif

#ifndef LPBYTE
	#define LPBYTE		BYTE*
#endif

#ifndef LONG
	#define LONG		long
#endif

#ifndef DWORD
	#define DWORD		unsigned long
#endif

#ifndef NULL
#define NULL 0
#endif

#ifndef WORD
#define WORD		unsigned short
#endif

#ifndef COLORREF
#define COLORREF	DWORD
#endif

#ifndef HDC
#define HDC			void*
#endif

#ifndef HWND
#define HWND		void*
#endif

#ifndef LPSTR
#define LPSTR		char*
#endif

#ifndef UINT
#define UINT		unsigned int
#endif

#ifndef BOOL
#define BOOL	int
#endif

#ifndef TRUE
#define TRUE		1
#endif

#ifndef FALSE
#define FALSE		0
#endif

#ifndef ULONGLONG
#define ULONGLONG	unsigned long long
#endif

#ifndef LONGLONG
#define LONGLONG	long long
#endif

#ifndef INT64
#define INT64 int64
#endif

#ifndef UINT64
#define UINT64 uint64
#endif

typedef struct _SYSTEMTIME
{
    WORD wYear;
    WORD wMonth;
    WORD wDayOfWeek;
    WORD wDay;
    WORD wHour;
    WORD wMinute;
    WORD wSecond;
    WORD wMilliseconds;
} SYSTEMTIME, *PSYSTEMTIME, *LPSYSTEMTIME;

#endif

#ifdef	__cplusplus
extern "C" {
#endif

///////////////////////////////////////////////////////////////////////////////////

// ��֡��Ż�ȡ�ؼ�֡
#define TYPE_BY_FRAME_NUMBER			1
// ��֡�¼���ȡ�ؼ�֡
#define TYPE_BY_FRAME_TIME				2

#define MAX_SOURCE_BUF_SIZE				1024 * 1024 * 100	// ��������������󳤶�
#define MIN_SOURCE_BUF_SIZE				1024 * 50			// ��������������С����

#define STREAM_TYPE_REALTIME			0					// ʵʱ��ģʽ
#define STREAM_TYPE_FILE				1					// �ļ���ģʽ

#define PlayMS_QueryTime				1					//������ʱ����Ϣ
#define PlayMS_QueryFileRate			2					//֡����Ϣ
#define PlayMS_QueryMediaInfo			3					//ý����Ϣ
#define PlayMS_QueryRenderNum			4					//��ǰҪ��Ⱦ��֡��
#define PlayMS_QueryRenderTime			5					//��ǰҪ��Ⱦ��ʱ��
#define PlayMS_QuerySrcTime				6					//��ƵԴ�е�ʱ����Ϣ
#define PlayMS_QueryCurRenderNum		7					//��ǰ֡�š�4����һ֡��֡��
#define PlayMS_QueryRenderPTS			8					//��ǰҪ��Ⱦ��֡ʱ���

///////////////////////////////////////////////////////////////////////////////////
// YUV ��������
typedef enum
{
	// UYVY���͵�YUV����
	TYPE_UYUV = 1,
	// 4:2:0����YUV����
	TYPE_IYUV = 3,
	// RGB32����YUV����
	TYPE_RGB32 = 7,
}ENUM_YUV_TYPE;

// ��Ƶ��������
typedef enum
{
	// 8λ��Ƶ��������
	TYPE_AUDIO_DATA_8 = 100,
	// 16λ��Ƶ��������
	TYPE_AUDIO_DATA_16 = 101,	
}ENUM_AUDIO_DATA_TYPE;

// ֡��������
typedef enum
{
	// ��ƵԴ����
	TYPE_MEDIA_VIDEO_SRC_BUF = 1,
	// ��ƵԴ����
	TYPE_MEDIA_AUDIO_SRC_BUF = 2,
	// �������Ƶ���ݻ���
	TYPE_MEDIA_VIDEO_RENDER_BUF = 3,
	// �������Ƶ���ݻ���
	TYPE_MEDIA_AUDIO_RENDER_BUF = 4,
}ENUM_MEDIA_BUF_TYPE;

// ��ý��֡����
typedef enum
{
	MEDIA_FRAME_TYPE_VIDEO = 0,		// ��Ƶ֡����
	MEDIA_FRAME_TYPE_AUDIO = 1,		// ��Ƶ֡����
}ENUM_MEDIA_FRAME_TYPE;

// ֡������
typedef enum
{
	SUB_FRAME_TYPE_VIDEO_I = 0,				// I֡
	SUB_FRAME_TYPE_VIDEO_P,					// P֡
	SUB_FRAME_TYPE_VIDEO_B,					// B֡
	SUB_FRAME_TYPE_VIDEO_S,					// S֡
	
	SUB_FRAME_TYPE_VIDEO_MJPEG = 8,			// MJPEG
}ENUM_SUB_FRAME_TYPE;

// �����ʽ
typedef enum
{
	VIDEO_ENCODE_TYPE_UNKNOWN = 0x00,		// δ֪��Ƶ�����ʽ
	VIDEO_ENCODE_TYPE_MPEG4 = 0x01,			// MPEG4 ��Ƶ�����ʽ
	VIDEO_ENCODE_TYPE_HISI_H264 = 0x02,		// ��˼H264��Ƶ�����ʽ
	VIDEO_ENCODE_TYPE_JPEG = 0x03,			// ��׼JPEG��Ƶ�����ʽ

	VIDEO_ENCODE_TYPE_AVS = 0x07,			// ��׼AVS��Ƶ�����ʽ
	VIDEO_ENCODE_TYPE_STD_H264 = 0x08,		// ��׼H264��Ƶ�����ʽ
	VIDEO_ENCODE_TYPE_MPEG2 = 0x09,			// MPEG2��Ƶ�����ʽ

	VIDEO_ENCODE_TYPE_RY_H264 = 0x0D,		// ��˾H264��Ƶ�����ʽ
	VIDEO_ENCODE_TYPE_RY_H265 = 0x0E,		// ��˾H265��Ƶ�����ʽ
}ENUM_VIDEO_ENCODE_TYPE;

typedef enum
{
	STREAM_PACKAGE_TYPE_UNKNOWN = 0x00,		// δ֪����
	STREAM_PACKAGE_TYPE_MPEG4 = 0x01,		// MPEG4

	STREAM_PACKAGE_TYPE_AUDIO = 0x06,		// ��Ƶ
	STREAM_PACKAGE_TYPE_PS = 0x07,			// PS��MPEG-2��

	STREAM_PACKAGE_TYPE_ASF = 0x09,			// ASF

	STREAM_PACKAGE_TYPE_TS = 0x0C,			// TS��MPEG-2��
	STREAM_PACKAGE_TYPE_SVC = 0x0D,			// SVC
	STREAM_PACKAGE_TYPE_AVI = 0x0E,			// AVI
	STREAM_PACKAGE_TYPE_MP4 = 0x0F,			// MP4
	STREAM_PACKAGE_TYPE_CGI = 0x10,			// CGI
	STREAM_PACKAGE_TYPE_WAV = 0x11,			// WAV��Ƶ
	STREAM_PACKAGE_TYPE_FLV = 0x12,			// FLV
	
	STREAM_PACKAGE_TYPE_RYMS = 0x13,		// ��˾����

	STREAM_PACKAGE_TYPE_MKV = 0x14,			// MKV
	STREAM_PACKAGE_TYPE_RTP = 0x15,			// RTP
	STREAM_PACKAGE_TYPE_RAW_MPEG4 = 0x16,	// MPEG4������
	STREAM_PACKAGE_TYPE_RAW_H264 = 0x17,	// H264������
	STREAM_PACKAGE_TYPE_RAW_H265 = 0x18,	// H265������
	STREAM_PACKAGE_TYPE_WMV = 0x19,			// WMV
	STREAM_PACKAGE_TYPE_RAW_MPEG2 = 0x20,	// MPEG2������
	STREAM_PACKAGE_TYPE_RAW_SVAC = 0x21,	// SVAC������
	STREAM_PACKAGE_TYPE_MOV = 0x22,			// MOV
	STREAM_PACKAGE_TYPE_VOB = 0x23,			// VOB

}ENUM_STREAM_PACKAGE_TYPE;

///////////////////////////////////////////////////////////////////////////////////
//ʱ��ṹ
#ifndef _ALTIME_
#define _ALTIME_
typedef struct _ALTIME								
{
	DWORD second	:6;					//	��	0-59		
	DWORD minute	:6;					//	��	0-59		
	DWORD hour		:5;					//	ʱ	0-23		
	DWORD day		:5;					//	��	1-31		
	DWORD month		:4;					//	��	1-12		
	DWORD year		:6;					//	��	2000-2063	
} ALTIME, *pALTIME;
#endif

// ֡��λ��Ϣ
typedef struct
{
	LONGLONG		nFilePos;				// ֡���ļ��е�ƫ��λ��
	LONG			nFrameLen;				// ֡����
	LONG			nFrameNum;				// ֡���
	LONG			nFrameTime;				// ֡ʱ��
	LONG			nErrorFrameNum;			// δ����
	SYSTEMTIME*		pErrorTime;				// δ����
	LONG			nErrorLostFrameNum;		// δ����
	LONG			nErrorFrameSize;		// δ����		
}FRAME_POS_INFO, *PFRAME_POS_INFO;

// ����֡������Ϣ
typedef struct
{
	LONG			nWidth;					// �����,��λ����
	LONG			nHeight;				// �����,��λ����
	LONG			nStamp;					// ʱ����Ϣ,��λ����
	LONG			nType;					// ��Ƶ֡����,TYPE_IYUV,TYPE_AUDIODATA_16,TYPE_RGB32
	LONG			nFrameRate;				// ͼ��֡��
}FRAME_ATTRI_INFO;

// ����֡������Ϣ
typedef struct
{
	int				nFrameType;				// ֡����
											// 0 - MEDIA_FRAME_TYPE_VIDEO����Ƶ֡��
											// 1 - MEDIA_FRAME_TYPE_AUDIO����Ƶ֡��
	int				nSubFrameType;			// ֡�����ͣ��μ� ENUM_SUB_FRAME_TYPE ö��ֵ��
	int				nEncodeType;			// �������ͣ��μ� ENUM_VIDEO_ENCODE_TYPE ö��ֵ��
	int				nStreamType;			// ������װ���ͣ��μ� ENUM_STREAM_PACKAGE_TYPE ö��ֵ��
	
	unsigned char*	pFrameData;				// ֡����
	unsigned int	nFrameDataLen;			// ֡���ݳ���
	unsigned char*	pFrameBodyData;			// ֡������
	unsigned int	nFrameBodyLen;			// ֡�����ݳ���

	int				nFrameSeq;				// ֡���
	int				nStamp;					// ʱ����Ϣ(��λ:ms)
	int				nWidth;					// �����(��λ:����)
	int 			nHeight;				// �����(��λ:����)
	int				nFrameRate;				// ͼ��֡��
	int				nChannels;				// ��Ƶͨ����
	int				nBitPerSample;			// ��Ƶ����λ��
	int				nSamplesPerSec;			// ��Ƶ����Ƶ��
	int				nRemainData;			// ����ʣ��������
	SYSTEMTIME		nDataTime;				// ʱ��
	int				nReserved[48];			// ����λ
}FRAME_ATTRI_INFO_EX;

// ����֡����
typedef struct 
{
	int				nFrameType;				// ֡���� 
											// 0 - MEDIA_FRAME_TYPE_VIDEO����Ƶ֡��
											// 1 - MEDIA_FRAME_TYPE_AUDIO����Ƶ֡��
	int				nSubFrameType;			// ֡�����ͣ��μ� ENUM_SUB_FRAME_TYPE ö��ֵ��
	
	void*			pAudioData;				// ��Ƶ���ݣ���Ƶ֡��Ч��
	int				nAudioDataLen;			// ��Ƶ���ݳ���

	void*			pVideoData[3];			// �ֱ��ʾ��Ƶ��YUV������������Ƶ֡��Ч��
	int				nStride[3];				// �ֱ��ʾYUV���������Ŀ�ࣨ��Ƶ֡��Ч��
	int				nWidth[3];				// �ֱ��ʾYUV���������Ŀ�ȣ���Ƶ֡��Ч��
	int				nHeight[3];				// �ֱ��ʾYUV���������ĸ߶ȣ���Ƶ֡��Ч��
	int				nReserved[64];			// ����λ
}FRAME_DEC_INFO;

/////////////////////////////////////////////////////////////////////////////////////////

/**********************************************************************************
������		PlayMS_Play
������		[in] LONG nPort��			ͨ����
			[in] HWND hWnd��    		���Ŵ��ھ��
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		��ʼ���š� �����ǰ�Ѿ��ǲ���״̬����ָ������������ٶȡ�
			�ڽ����߳��У�������ھ��ΪNULL������ʾ���棬����Ӱ����롣
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_Play(LONG nPort, HWND hWnd);

/**********************************************************************************
������		PlayMS_Stop
������		[in] LONG nPort��			ͨ����
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		ֹͣ���š�
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_Stop(LONG nPort);

/**********************************************************************************
������		PlayMS_GetCurrentFrameRate
������		[in] LONG nPort��			ͨ����
����ֵ��	��ǰ֡��
˵����		��ȡ��ǰ֡�ʡ�
**********************************************************************************/
PLAYMS_API DWORD CALLMETHOD PlayMS_GetCurrentFrameRate(LONG nPort);

/**********************************************************************************
������		PlayMS_GetCurrentFrameRate
������		[in] LONG nPort��			ͨ����
			[out] double *pBitRate:		ʵʱ����ֵ
����ֵ��	ʵʱ����
˵����		��ȡʵʱ���ʡ�
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_GetRealFrameBitRate(LONG nPort, double* pBitRate);

/**********************************************************************************
������		PlayMS_GetPictureSize
������		[in] LONG nPort��			ͨ����
			[in] LONG *pWidth:			ͼƬ���
			[in] LONG *pHeight:			ͼƬ�߶�
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		��ȡ������ԭʼͼ��Ĵ�С���ú���ֻ�е����ſ�ʼ����ܻ�ȡ׼ȷ��ֵ��
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_GetPictureSize(LONG nPort, LONG *pWidth, LONG *pHeight);

/**********************************************************************************
������		PlayMS_GetStreamOpenMode
������		[in] LONG nPort��			ͨ����
����ֵ��	�ɹ�������ģʽ��ʧ�ܷ���-1
˵����		��ȡ������ģʽ��
			0 - STREAM_TYPE_REALTIME��ʵʱ��ģʽ�� 
			1 - STREAM_TYPE_FILE���ļ���ģʽ��
**********************************************************************************/
PLAYMS_API LONG CALLMETHOD PlayMS_GetStreamOpenMode(LONG nPort);

/**********************************************************************************
������		PlayMS_SetStreamOpenMode
������		[in] LONG nPort��			ͨ����
			[in] DWORD nMode��			����ģʽ
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		����������ģʽ������PlayMS_Play֮ǰ����
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_SetStreamOpenMode(LONG nPort, DWORD dwMode);

/**********************************************************************************
������		BOOL PlayMS_GetFreePort
������		[out] LONG *pnPort			ͨ����	
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		��ȡδʹ�õ�ͨ���ţ�ͨ���ŵ�����Ϊ500��
			ͨ����ͨ���������ֲ�ͬ·����Ƶ����PlayMS_ReleasePortƥ��ʹ�á�
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_GetFreePort(LONG *pnPort);

/**********************************************************************************
������		BOOL PlayMS_ReleasePort
������		[in] LONG nPort				ͨ����	
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		�ͷ�ͨ���ţ���PlayMS_GetFreePortƥ��ʹ�á�
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_ReleasePort(LONG nPort);

/**********************************************************************************
������		PlayMS_ResetSourceBuffer
������		[in] LONG nPort��			ͨ����
����ֵ��	�ɹ�����TRUE, ʧ�ܷ��� FLASE.
˵����		���������ģʽ��Դ�������ݣ�һ���ڹر���������á�
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_ResetSourceBuffer(LONG nPort);

/**********************************************************************************
����:		PlayMS_RegisterDrawCallBack
����:		ע��һ����ͼ����
����:		[in]nPort			�˿ں�
			[in]fRegDrawCB		��ͼ�ص�����
					nPort		�˿ں�
					hDc			��ͼ�豸�����ľ��
					pUserData	�û�����
			[in]pUserData		�ص��������û�����
����ֵ:		�ɹ�����TRUE, ʧ�ܷ���FALSE
˵��:		ע��һ����ͼ�ص��������û������ڸû�ͼ�ص������л����û�˽�����ݣ�
			���û���������Ƶ�������һ�����ο򡣻�ͼ�ص������в��������������
			��������ڸ���������Ĺ���ʱ�䣬�Ӷ�������Ƶʵʱ���ܵ�Ӱ�졣
**********************************************************************************/
typedef void (CALLBACK* fRegDrawCallBack)(LONG nPort, HDC hDc, void* pUserData);
PLAYMS_API BOOL CALLMETHOD PlayMS_RegisterDrawCallBack(LONG nPort, fRegDrawCallBack fRegDrawCB, void* pUserData);

/**********************************************************************************
������		PlayMS_OpenStream
������		[in] LONG nPort:			ͨ����
			[in] DWORD nBufPoolSize:	�����������ݵĻ�������С��
										��Χ��[SOURCE_BUF_MIN~ SOURCE_BUF_MAX]
										����������ݽϾ��ȣ��ɵ�С��ֵ��
										����������ݲ����ȣ��ɵ����ֵ��
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		���������š�
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_OpenStream(LONG nPort, DWORD nBufPoolSize);

/**********************************************************************************
������		BOOL PlayMS_CloseStream(LONG nPort)
������		[in] LONG nPort��			ͨ����
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		�ر��������š�
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_CloseStream(LONG nPort);

/**********************************************************************************
������		PlayMS_InputData
������		[in] LONG nPort��			ͨ����
			[in] PBYTE pBuf��			���������ݵ�ַ		
			[in] DWORD nSize��			���������ݴ�С
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE��
˵����		���������������ڴ�����PlayMS_OpenStream���Ҳ��ţ�PlayMS_Play��������������ݡ�
			�������FALSE���ܿ����ǻ������������ɵȴ�һ������������ݣ��������󻺳�����
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_InputData(LONG nPort, PBYTE pBuf, DWORD nSize);

/**********************************************************************************
������		PlayMS_SetDecodeCallBack
������		[in] LONG nPort��						ͨ����	
			[in] fDecodeCallBack fDecCB:  			����ص�����ָ��
					nPort:							ͨ����
					pFrameDecodeInfo:				֡����
					pFrameInfo:						֡��Ϣ
					pUser:							�û�����
			[in] void* pUser:  						�û��Զ������
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		���ý������ݻص���������ֻ���벻��ʾ�������
			����PlayMS_Play֮����ã��ڵ���PlayMS_Stop֮���Զ�ʧЧ
**********************************************************************************/
typedef void (CALLBACK* fDecodeCallBack)(LONG nPort, FRAME_DEC_INFO* pFrameDecodeInfo, FRAME_ATTRI_INFO_EX* pFrameInfo, void* pUserData);
PLAYMS_API BOOL CALLMETHOD PlayMS_SetDecodeCallBack(LONG nPort, fDecodeCallBack fDecCB, void* pUserData);

/**********************************************************************************
������		PlayMS_SetVisibleDecodeCallBack
������		[in] LONG nPort��						ͨ����	
			[in] fDecodeCallBack fDecCB:  			����ص�����ָ��
					nPort:							ͨ����
					pFrameDecodeInfo:				֡����
					pFrameInfo:						֡��Ϣ
					pUser:							�û�����
			[in] void* pUserData:  					�û��Զ������
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		���ý������ݻص��������ڽ�������ʾ�������
			����PlayMS_Play֮����ã��ڵ���PlayMS_Stop֮���Զ�ʧЧ
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_SetVisibleDecodeCallBack(LONG nPort, fDecodeCallBack fDecCB, void* pUserData);

/**********************************************************************************
������		PlayMS_SetDisplayCallBack
������		[in] LONG nPort��						ͨ����	
			[in] fDisplayCallBack fDisplayCB:		��ʾ�ص�����ָ��
					nPort:							ͨ����
					pYuvBuf:						��Ƶ֡ YUV ����
					nYuvSize:						YUV ���ݴ�С	
					nWidth:							�����,��λ����
					nHeight:						�����,��λ����
					nStamp:							ʱ�����Ϣ
					nType:							��Ƶ֡����, TYPE_IYUV, TYPE_AUDIODATA_16, TYPE_RGB32
					pReserved:						��������
			[in] void* pUserData: 					�û��Զ������
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		������Ƶץͼ�ص����������û���õ�һ��ʱ���ڵ�ץͼ���ݣ��ɵ��øú�����
			�����ص���������ΪNULLʱ, ֹͣ�����ص���
			�������õĻص�������ֻ�����н�������ʱ�ű����ã������û�����ץͼ���ݡ�
			�ú��������κ�ʱ�����
**********************************************************************************/
typedef void (CALLBACK* fDisplayCallBack)(LONG nPort, char * pYuvBuf, LONG nYuvSize, LONG nWidth, LONG nHeight, LONG nStamp, LONG nType, void* pReserved);
PLAYMS_API BOOL CALLMETHOD PlayMS_SetDisplayCallBack(LONG nPort, fDisplayCallBack fDisplayCB, void* pUserData);

/**********************************************************************************
������		PlayMS_CatchPic
������		[in] LONG nPort��			ͨ����	
			[in] char* sFileName: 		ͼƬ���ļ�����
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		ץͼ�����û���ʵ��һ��ץһ��ͼ���ɵ��øú�����
			�ú�������Ƶ��ͣ����֡����ʱҲ��ʹ�á�
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_CatchPic(LONG nPort, char* sFileName);

/**********************************************************************************
������		PlayMS_SetPlayMethod
������		[in] LONG nPort��			ͨ����	
			[in] int nStartTime: 		��ʼ���ŵ�ʱ��(ms)
			[in] int nSlowTime:  		��ʼ���ŵ�ʱ��(ms)
			[in] int nFastTime:  		��ʼ��ŵ�ʱ��(ms)
			[in] int nFailedTime: 		ʧ��ʱ�䣬������ʱ��������Ͷ��ʧ�ܣ�ms��
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		���ò��ŵķ������ԣ��ú���ֻ����ʵʱ����ʱ���ò���Ч��
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_SetPlayMethod(LONG nPort, int nStartTime, int nSlowTime, int nFastTime, int nFailedTime);

/**********************************************************************************
������		PlayMS_SetDecCBStream
������		[in] LONG nPort��			ͨ����	
			[in] DWORD dwStream:  		�������ͣ�1Ϊ��Ƶ����2Ϊ��Ƶ����3Ϊ������
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		���ý���ص����������ͣ��ú�������PlayMS_Play֮ǰ����
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_SetDecCBStream(LONG nPort, DWORD dwStream);

/**********************************************************************************
������		PlayMS_SetAudioCallBack
������		[in] LONG nPort��						ͨ����	
			[in] fAudioCallBack fAudioCB: 			��Ƶ�ص�����ָ��
						nPort:						ͨ����
						pAudioBuf:					��Ƶ��������
						nSize:						�������ݴ�С
						nStamp:						ʱ����Ϣ,��λ����
						nType:						��Ƶ��������
													8λ��Ƶ�������� TYPE_AUDIO_DATA_8 = 100,
													16λ��Ƶ�������� TYPE_AUDIO_DATA_16 = 101,
						pUserData:					�û�����
			[in] void* pUserData:  					�û�����
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		������Ƶ�������ݻص�
**********************************************************************************/
typedef void (CALLBACK * fAudioCallBack)(LONG nPort, char * pAudioBuf, LONG nSize, LONG nStamp, LONG nType, void* pUserData);
PLAYMS_API BOOL CALLMETHOD PlayMS_SetAudioCallBack(LONG nPort, fAudioCallBack fAudioCB, void* pUserData);

/**********************************************************************************
������		PlayMS_StartDataRecord
������		[in] LONG nPort��			ͨ����	
			[in] char *sFileName:  		¼���ļ�����
										����ļ������в����ڵ��ļ���,�ʹ������ļ���
			[in] int nDataType:  		0��ʾԭʼ��Ƶ��; 1��ʾת����AVI��ʽ;
										2��ʾת����ASF��ʽ; 3�ֶα����ļ�
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		��ʼ������¼�񣬸ú�������PlayMS_Play֮����ã�ֻ����ʵʱ����ʱ���ò���Ч
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_StartDataRecord(LONG nPort, char *sFileName, int nDataType);

/**********************************************************************************
������		PlayMS_WriteData
������		[in] LONG nPort��			ͨ����
			[in] PBYTE pBuf:      		��������
			[in] DWORD nSize:   		������С	
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		����ԭʼ��������
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_WriteData(LONG nPort, PBYTE pBuf, DWORD nSize);

/**********************************************************************************
������		BOOL PlayMS_StopDataRecord(LONG nPort)
������		[in] LONG nPort��			ͨ����	
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		ֹͣ������¼��
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_StopDataRecord(LONG nPort);

/**********************************************************************************
������		PlayMS_QueryInfo
			[in] LONG nPort��				ͨ����
			[in] int nQueryType:  			ָ����ѯ���ͣ���Ҫ�������£�
				PlayMS_QueryTime  			������ʱ����Ϣ
				PlayMS_QueryFileRate  		֡����Ϣ
				PlayMS_QueryMediaInfo  		ý����Ϣ
				PlayMS_QueryRenderNum 		��ǰҪ��Ⱦ��֡�ţ���һ֡��֡��
				PlayMS_QueryRenderTime		��ǰҪ��Ⱦ��ʱ��
				PlayMS_QuerySrcTime    		��ƵԴ�е�ʱ����Ϣ
				PlayMS_QueryCurRenderNum  	��ǰ֡��
				PlayMS_QueryRenderPTS		��ǰʱ���
			[out] char* pBuffer:  			��Ų�ѯ���Ļ�������
			[in] int nBufLen:  				����Ļ�������С
			[out] int* pRetLen:  			��Ų�ѯ����Ч���ݴ�С
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		��ѯָ��ͨ����ʱ�䡢֡�ʵ���Ϣ
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_QueryInfo(LONG nPort, int nQueryType, char* pBuffer, int nBufLen, int* pRetLen);

/**********************************************************************************
������		PlayMS_CreateStream
������		[in] DWORD nBufPoolSize��		�����������ݵĻ�������С
											��Χ��[MIN_SOURCE_BUF_SIZE, MAX_SOURCE_BUF_SIZE].
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		�������ͨ���Ų�������������PlayMS_GetFreePort��PlayMS_OpenStream�ӿڵĺϼ�
**********************************************************************************/
PLAYMS_API DWORD CALLMETHOD PlayMS_CreateStream(DWORD nBufPoolSize);

/**********************************************************************************
������		PlayMS_DestroyStream
������		[in] LONG nPort:				ͨ����
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		�ر��������ͷ������ͨ����
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_DestroyStream(LONG nPort);

/**********************************************************************************
������		BOOL PlayMS_OpenFile(LONG nPort, LPSTR sFileName)
������		[in] LONG nPort:		ͨ����
			[in] LPSTR sFileName:	�ļ���
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		���ļ�������PlayMS_Play֮ǰ���á�
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_OpenFile(LONG nPort, LPSTR sFileName);

/**********************************************************************************
������		BOOL PlayMS_CloseFile(LONG nPort)
������		[in] LONG nPort:		ͨ����
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		�ر��ļ�������PlayMS_Stop֮����á�
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_CloseFile(LONG nPort);

/**********************************************************************************
������		BOOL PlayMS_Pause(LONG nPort, DWORD nPause)
������		[in] LONG nPort��			ͨ����
			[in] DWORD nPause: 		1Ϊ��ͣ��0Ϊ�ָ�����
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		��ͣ����, ���߻ָ����š�
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_Pause(LONG nPort,DWORD nPause);

/**********************************************************************************
������		PlayMS_Fast
������		[in] LONG nPort��			ͨ����
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		�������١�ÿ����һ�Σ������ٶȳ�2�������ٶȷ�ΧΪ[1/64,64]
			����PlayMS_Play��ӵ�ǰλ�ûָ������������ٶ�
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_Fast(LONG nPort);

/**********************************************************************************
������		PlayMS_Slow
������		[in] LONG nPort��			ͨ����
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		���ż��١�ÿ����һ�Σ������ٶȳ�2�������ٶȷ�ΧΪ[1/64, 64]��
			����PlayMS_Play��ӵ�ǰλ�ûָ������������ٶ�
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_Slow(LONG nPort);

/**********************************************************************************
������		PlayMS_SetPlaySpeed
������		[in] LONG nPort��			ͨ����
			[in] float fCoff��			�����ٶȣ���ΧΪ[1/64,64]
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		������Ƶ�����ٶ�
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_SetPlaySpeed(LONG nPort, float fCoff);

/**********************************************************************************
������		PlayMS_OneByOne
������		[in] LONG nPort��			ͨ����
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		��֡���ţ�ÿ����һ�β���һ֡������PlayMS_Play��ָ���������
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_OneByOne(LONG nPort);

/**********************************************************************************
������		PlayMS_SetPlayPos
������		[in] LONG nPort��			ͨ����
			[in] float fRelativePos:	�ļ����ȵİٷֱ�
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		���ò����ļ������λ��(�ٷֱ�)������PlayMS_Play֮�����
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_SetPlayPos(LONG nPort, float fRelativePos);

/**********************************************************************************
������		PlayMS_SetPlayDirection
������		[in] LONG nPort��			ͨ����
			[in] DWORD nDirection��		���ŷ���0: ��ǰ��1: ���)
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		������Ƶ�ļ��Ĳ��ŷ���
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_SetPlayDirection(LONG nPort, DWORD nDirection);

/**********************************************************************************
������		PlayMS_GetPlayPos
������		[in] LONG nPort��			ͨ����
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		��ȡ�����ļ������λ��(�ٷֱ�)������PlayMS_Play֮�����
**********************************************************************************/
PLAYMS_API float CALLMETHOD PlayMS_GetPlayPos(LONG nPort);

/**********************************************************************************
������		PlayMS_SetVolume
������		[in] LONG nPort��			ͨ����
			[in] WORD nVolum: 			����ֵ����ΧΪ[0,0xFFFF]
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		����������С���ýӿ����õ������������������������
			�������Ӧ�õ�������Ӱ��
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_SetVolume(LONG nPort, WORD nVolume);

/**********************************************************************************
������		PlayMS_GetVolume
������		[in] LONG nPort��			ͨ����
����ֵ��	�ɹ���������ֵ��ʧ�ܷ���ֵ <= 0
˵����		��ȡ�������������
**********************************************************************************/
PLAYMS_API WORD CALLMETHOD PlayMS_GetVolume(LONG nPort);

/**********************************************************************************
������		PlayMS_PlaySound
������		[in] LONG nPort��			ͨ����
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		�Զ�ռ��ʽ��������Ҳ����һ��ֻ�ܴ�һ·������
			����򿪵�ǰ�����������Զ��ر�֮ǰ�Ѿ��򿪵�������
			�����PlayMS_StopSoundƥ��ʹ��
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_PlaySound(LONG nPort);

/**********************************************************************************
������		PlayMS_StopSound
������		��
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		�ر�����
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_StopSound();

/**********************************************************************************
������		PlayMS_GetFileTime
������		[in] LONG nPort��			ͨ����
����ֵ��	����������ļ�ʱ���ĳ���ֵ
˵����		��ȡ�ļ�����ʱ������λΪ�롣����PlayMS_Play֮�����
**********************************************************************************/
PLAYMS_API DWORD CALLMETHOD PlayMS_GetFileTime(LONG nPort);

/**********************************************************************************
������		PlayMS_GetPlayedTime
������		[in] LONG nPort��			ͨ����
����ֵ��	�ɹ�ʱ�����ļ��Ѳ���ʱ�䣬ʧ��ʱ����0
˵����		��ȡ�ļ��Ѳ��ŵ�ʱ�䣬��λΪ�롣����PlayMS_Play֮�����
**********************************************************************************/
PLAYMS_API DWORD CALLMETHOD PlayMS_GetPlayedTime(LONG nPort);

/**********************************************************************************
������		PlayMS_GetPlayedTimeEx
������		[in] LONG nPort��			ͨ����
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		��ȡ�ļ���ǰ���ŵ�ʱ�䣬��λΪ���롣����PlayMS_Play֮�����
**********************************************************************************/
PLAYMS_API DWORD CALLMETHOD PlayMS_GetPlayedTimeEx(LONG nPort);

/**********************************************************************************
������		PlayMS_GetPlayedFrames
������		[in] LONG nPort��			ͨ����
����ֵ��	�ļ��Ѿ������֡��
˵����		��ȡ�ļ��Ѿ������֡��
**********************************************************************************/
PLAYMS_API DWORD CALLMETHOD PlayMS_GetPlayedFrames(LONG nPort);

/**********************************************************************************
������		PlayMS_GetFileTotalFrames
������		[in] LONG nPort��			ͨ����
����ֵ��	�ļ���֡��
˵����		��ȡ�ļ�����֡��������PlayMS_Play֮�����
**********************************************************************************/
PLAYMS_API DWORD CALLMETHOD PlayMS_GetFileTotalFrames(LONG nPort);

/**********************************************************************************
������		BOOL PlayMS_SetPlayedTimeEx(LONG nPort,DWORD nTime)
������		[in] LONG nPort��			ͨ����
			[in] DWORD nTime: 			����ʱ��
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		�����ļ����ŵ�ָ��ʱ�䣬��λΪ���롣����PlayMS_Play֮�����
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_SetPlayedTimeEx(LONG nPort, DWORD nTime);

/**********************************************************************************
������		DWORD PlayMS_GetCurrentFrameNum(LONG nPort)
������		[in] LONG nPort��			ͨ����
����ֵ��	�ļ���ǰ���ŵ�֡���
˵����		��ȡ�ļ���ǰ���ŵ�֡��š�
			�����Ƶ����ʧ������ֵ�ӽ�PlayMS_GetPlayedFrames�ķ���ֵ
**********************************************************************************/
PLAYMS_API DWORD CALLMETHOD PlayMS_GetCurrentFrameNum(LONG nPort);

/**********************************************************************************
������		DWORD PlayMS_SetCurrentFrameNum(LONG nPort,DWORD nFrameNum)
������		[in] LONG nPort��			ͨ����
			[in] DWORD nFrameNum: 	֡���
����ֵ��	�ɹ�����TRUE,ʧ�ܷ���FALSE
˵����		�����ļ���ǰ���ŵ�֡���
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_SetCurrentFrameNum(LONG nPort,DWORD nFrameNum);

/**********************************************************************************
������		PlayMS_SetFileEndCallBack
������		[in] LONG nPort��						ͨ����	
			[in] fFileEndCallBack fFileEndCB: 		�ص�����ָ��
					nPort  							ͨ����
					pUserData  						�û��Զ������
			[in] void* pUserData:  					�û��Զ������
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		�����ļ������ص������ļ����Ž���ʱ�������ص�������
			����PlayMS_OpenSteam��PlayMS_OpenFile֮ǰ����
**********************************************************************************/
typedef void (CALLBACK *fFileEndCallBack)(DWORD nPort, void* pUserData);
PLAYMS_API BOOL CALLMETHOD PlayMS_SetFileEndCallBack(LONG nPort, fFileEndCallBack pFileEndCBFun, void* pUserData);

/**********************************************************************************
������		PlayMS_SetFileEndMsg
������		[in] LONG nPort��				ͨ����	
			[in] HWND hWnd:  				��Ϣ���ʹ���
			[in] UINT nMsg:  				�û��Զ����跢�͵���Ϣ����
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		�����ļ����Ž���ʱ���û��Զ��巢�͵���Ϣ
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_SetFileEndMsg(LONG nPort, HWND hWnd, UINT nMsg);

/**********************************************************************************
����:	PlayMS_SetWaterMarkCallBack
����:	����ˮӡ���ݻص���ע�⣺ˮӡУ��ص����ú󽫲�����н�����ʾ
����:	nPort			�˿ں�
		pFunc			ˮӡ��Ϣ��ȡ�ص�����, ������������:
			pBuf		ˮӡ����bufferָ��
			nKey		���ֲ�ͬˮӡ��Ϣ
			nLen		�������󳤶�
			nRealLen	�����ʵ�ʳ���
			nType		��ֵ��Χ[0,3],��������
						0  I֡֡����ˮӡ��Ϣ
						1  ֡ˮӡ
						2  ˮӡУ�� 
						3  ���ܷ���֡
			pUserData	�û��Զ������ 
		pUserData		�û��Զ������ 
����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
**********************************************************************************/
typedef int (CALLBACK* fGetWaterMarkInfoCallBack)(char* pBuf, LONG nKey, LONG nLen, LONG nRealLen, LONG nType, void* pUserData);	
PLAYMS_API BOOL CALLMETHOD PlayMS_SetWaterMarkCallBack(LONG nPort, fGetWaterMarkInfoCallBack pFunc, void* pUserData);

/**********************************************************************************
����:	PlayMS_SetWaterMarkCallBackEx
����:	����ˮӡ���ݻص�(�ɹ�����벻��ʾ)
����:	nPort				�˿ں�
		pGetWaterMarkCB		����ָ��, ������������:
			nPort			�˿ں�
			buf				ˮӡ���ݻ���
			lTimeStamp		ˮӡ��ʱ���
			lInfoType		ˮӡ��Ϣ����
			len				�������󳤶�
			reallen			�����ʵ�ʳ���
			lCheckResult	1-û�д���; 2-ˮӡ����; 3-֡���ݴ���; 4-֡�Ŵ���
			pUserData		�û��Զ������
		pUserData		�û��Զ������
����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
**********************************************************************************/
typedef int (CALLBACK* fGetWaterMarkInfoCallBackEx)(LONG nPort, char* buf, LONG lTimeStamp, LONG lInfoType, LONG len, LONG reallen, LONG lCheckResult, void* pUserData);
PLAYMS_API BOOL CALLMETHOD PlayMS_SetWaterMarkCallBackEx(LONG nPort, fGetWaterMarkInfoCallBackEx pGetWaterMarkCB, void* pUserData);

/**********************************************************************************
������		PlayMS_ImageWatermarkCheck
������		[in] const char* pImagePath��	ͼƬ����·��	
����ֵ��	�ɹ�����TRUE, ʧ�ܷ���FALSE
˵����		ͼƬˮӡУ��
**********************************************************************************/
PLAYMS_API BOOL CALLMETHOD PlayMS_ImageWatermarkCheck(const char* pImagePath);

#ifdef __cplusplus
}
#endif

#endif