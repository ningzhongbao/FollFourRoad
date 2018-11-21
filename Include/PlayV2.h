
/************************************************************************/
/* warning����ͷ�ļ������ڲ�ʹ�ã��������ṩ������	                                                            */
/************************************************************************/

#ifndef _AL_PLAY_V2_H
#define _AL_PLAY_V2_H

#include "PlayV1.h"

#ifdef	__cplusplus
extern "C" {
#endif

	////////////////////////////////////////////////////////////////////////////////////////////////
	#define MAX_PLAY_PORT_NUM				501					// ��󲥷Ŷ˿���Ŀ

	////////////////////////////////////////////////////////////////////////////////////////////////
	#define _DD_RAW_DATA_TYPE				0xFF				// �������ݻ��Ƶ�ԭʼ��������
	#define _DD_INTL_TYPE					0x63				// ���ݻ��Ƶ�������������
	#define _DD_MOTION_FULL					0x65				// ���ݻ��ƵĶ�����������

	////////////////////////////////////////////////////////////////////////////////////////////////
	// �ļ�֡����
	typedef enum
	{
		TYPE_PLAY_INFO_MOTION_DETECT = 1,
		TYPE_PLAY_INFO_EVENT = 2,
	}ENUM_PLAY_INFO_TYPE;

	// BMPͼ������
	typedef enum
	{
		IMAGE_TYPE_BMP32 = 0,
		IMAGE_TYPE_BMP24 = 1,
	}ENUM_BMP_IMAGE_TYPE;

	// ��Ⱦ����
	typedef enum
	{
		TYPE_RENDER_NONE = 0,
		TYPE_RENDER_GDI,
		TYPE_RENDER_D3D,
		TYPE_RENDER_DDRAW,
		TYPE_RENDER_D3D_FAST = 5,
	}ENUM_TYPE_RENDER;

	// SVAC ������
 	typedef enum 
 	{
 		TYPE_SVAC_LAYER_BASE = 0x0001,
 		TYPE_SVAC_LAYER_ENHANCE = 0x0002,
 	}ENUM_SVAC_LAYER_TYPE;

	// ˮӡ��������
	typedef enum
	{
		// ����
		TYPE_WATERMARK_DATA_TEXT = 0,
		// JPEG����BMPͼƬ
		TYPE_WATERMARK_DATA_JPEG_BMP = 1,
		// ֡����
		TYPE_WATERMARK_DATA_FRAMEDATA = 3,		
	}ENUM_TYPE_WATERMARK_DATA;

	// ֡��Ϣ�ı�����
	typedef enum
	{
		// ֡�ʸı�
		TYPE_MEDIACHANGE_FRAMERATE = 1,
		// �ֱ��ʸı�
		TYPE_MEDIACHANGE_RESOLUTION = 2,
	}ENUM_MEDIACHANGE_TYPE;	

	// ��������
	typedef enum 
	{
		TYPE_DECODE_NONE = 0,
		TYPE_DECODE_SW,
		TYPE_DECODE_HW,
		TYPE_DECODE_HW_FAST,
		TYPE_DECODE_MSDK
	}ENUM_DECODE_TYPE;

	// ����ģʽ
	typedef enum 
	{
		// ��Чģʽ
		ENUM_MODE_FISHEYE_INVALID = 0,
		// ��װ
		ENUM_MODE_FISHEYE_CEIL = 1,
		// ��װ
		ENUM_MODE_FISHEYE_WALL = 2,	
		// ��װ
		ENUM_MODE_FISHEYE_FLOOR = 3,

		ENUM_MODE_FISHEYE_NUM
	}ENUM_MODE_FISHEYE;

	// ����У׼����
	typedef enum 
	{
		// ��Чģʽ
		ENUM_FISHEYE_CALIBRATE_MODE_INVALID = 0,
		// �ر�ģʽ
		ENUM_FISHEYE_CALIBRATE_MODE_OFF = 1,
		// ԭʼģʽ
		ENUM_FISHEYE_CALIBRATE_MODE_ORIGINAL = 2,
	}ENUM_FISHEYE_CALIBRATE_MODE;

	// ������̨����
	typedef enum 
	{
		// ��Ч����
		ENUM_FISHEYE_EPTZ_CMD_INVALID = 0,	
		// �Ŵ�
		ENUM_FISHEYE_EPTZ_CMD_ZOOM_IN = 1,
		// ��С
		ENUM_FISHEYE_EPTZ_CMD_ZOOM_OUT,
		// �����ƶ�
		ENUM_FISHEYE_EPTZ_CMD_UP,
		// �����ƶ�
		ENUM_FISHEYE_EPTZ_CMD_DOWN,
		// �����ƶ�
		ENUM_FISHEYE_EPTZ_CMD_LEFT,
		// �����ƶ�
		ENUM_FISHEYE_EPTZ_CMD_RIGHT,
		// �Զ�˳ʱ����ת
		ENUM_FISHEYE_EPTZ_CMD_AUTO_ROTATE_CLOCKWISE,
		// �Զ���ʱ����ת
		ENUM_FISHEYE_EPTZ_CMD_AUTO_ROTATE_ANTICLOCKWISE,
		// ֹͣ
		ENUM_FISHEYE_EPTZ_CMD_STOP,
		// ��ѡ�Ŵ�
		ENUM_FISHEYE_EPTZ_CMD_SHOW_REGION,
		// �˳���ѡ�Ŵ�
		ENUM_FISHEYE_EPTZ_CMD_EXIT_SHOW_REGION,
		// Բ��ת
		ENUM_FISHEYE_EPTZ_CMD_ORIGIN_ROTATE,
		// �ָ�Ĭ��
		ENUM_FISHEYE_EPTZ_CMD_DEFAULT,

		ENUM_FISHEYE_EPTZ_CMD_NUM
	}ENUM_FISHEYE_EPTZ_CMD;

	// ��ʽ��ͼƬ����
	typedef enum
	{
		// BMP32����
		TYPE_IMAGE_FORMAT_BMP_32 = 0,
		// BMP24����
		TYPE_IMAGE_FORMAT_BMP_24,
		// TIFF����
		TYPE_IMAGE_FORMAT_TIFF,
		// JPEG���� 100% ����
		TYPE_IMAGE_FORMAT_JPEG_100,		
		// 80%������JPEG����
		TYPE_IMAGE_FORMAT_JPEG_80,	
		// 60%������JPEG����
		TYPE_IMAGE_FORMAT_JPEG_60,	
		// 40%������JPEG����
		TYPE_IMAGE_FORMAT_JPEG_40,	
		// 20%������JPEG����
		TYPE_IMAGE_FORMAT_JPEG_20,	
		// 10%������JPEG����
		TYPE_IMAGE_FORMAT_JPEG_10,								
	}ENUM_IMAGE_FORMAT_TYPE;

	// ǹ������
	typedef enum 
	{
		// ǹ������
		CAMERA_TYPE_200W_FD			= 0,
	}ENUM_CAMERA_TYPE;

	// ��ͷ����
	typedef enum 
	{
		// �޻��侵ͷ
		LENSTYPE_NORMAL				= 0,	
	}ENUM_LENS_TYPE;

	typedef enum 
	{
		FISHEYE_SET_PARAM,
		FISHEYE_GET_PARAM
	}ENUM_FISHEYE_OPERATE_TYPE;

	// ����Ƶͬ������
	typedef enum 
	{
		// ����ƵΪ��׼
		SYNC_VIDEO_MASTER,
		// ����ƵΪ��׼
		SYNC_AUDIO_MASTER
	}ENUM_SYNC_TYPE;

	// IVS���ӹ�������
	typedef enum 
	{
		IVS_EFUNCTYPE_DEHAZE,	    // ȥ��
		IVS_EFUNCTYPE_DENOISE,		// ȥ��
		IVS_EFUNCTYPE_WB,			// ƫɫУ��
		IVS_EFUNCTYPE_LOWLIGHT,		// ���ն���ǿ
		IVS_EFUNCTYPE_HDR,			// ��̬
		IVS_EFUNCTYPE_NUM			// ֧����ǿ�Ĺ��ܸ���
	}ENUM_IVSEFUNC_TYPE;

	typedef enum
	{
		// ����������Ⱦ
		RENDER_TYPE_INTL = 0x63,

		// ����������Ⱦ
		RENDER_TYPE_MOTION = 0x65,

	}ENUM_RENDER_TYPE;

	////////////////////////////////////////////////////////////////////////////////////////////////

	// ��Ƶ��ʾ���ο�
	typedef struct
	{
		LONG left;
		LONG top;
		LONG right;
		LONG bottom;
	}STU_DISPLAY_RECT;

	// �Զ��������Ϣ
	typedef struct
	{
		// ��Ϣ����
		unsigned char type;
		// ��Ϣ����
		unsigned char length;
		// ��Ϣָ��
		unsigned char *pbuf;
		// ����
		unsigned char reserved[2];      
	}STU_CUSTOM_DEC_INFO_EX;

	// ���븽����Ϣ
	typedef struct
	{
		// ��������
		LONG			nVideoEncodeType;
		// �������ݳ���
		LONG	        nDataLen;
		// ������Ϣ
		char*           pUserData;
		// ����λ
		LONG	        nReserved[2];
	}STU_FRAME_DEC_INFO_EX;

	// ��ý����Ϣ
	typedef struct
	{
		int			lWidth;					// �����(��λ: ����)
		int			lHeight;				// �����(��λ: ����)
		int			lFrameRate;				// ֡��
		int			lChannel;				// ��Ƶͨ����
		int			lBitPerSample;			// ��Ƶ����λ��
		int			lSamplesPerSec;			// ��Ƶ����Ƶ��
	}STU_MEDIA_INFO;

	// ������سߴ�
	typedef struct
	{
		int w;
		int h;
	}STU_FISHEYE_SIZE;

	// �������2D����
	typedef struct
	{
		short x;
		short y;
	}STU_FISHEYE_POINT2D;

	// ����������
	typedef struct
	{
		// ��ͼ��װģʽ
		ENUM_MODE_FISHEYE				subMountMode;
		// ��ͼ��У��ģʽ
		ENUM_FISHEYE_CALIBRATE_MODE		subCalibrateMode;
		// ��ͼ������ֱ���
		STU_FISHEYE_SIZE				imgOutput;
		// ��ͼ��ƫ��
		STU_FISHEYE_POINT2D				upperLeft;
		// ����λ
		int								reserved[3];	
	}STU_FISHEYE_SUBMODE;

	// ���������ʽ
	typedef struct
	{
		// ����ʾ����
		STU_FISHEYE_SIZE			mainShowSize;	
		// �������ڵ�����ʾ���ڷֱ���,
		STU_FISHEYE_SIZE			floatMainShowSize;
		// ����ǰ���ͼ��ֱ���
		STU_FISHEYE_SIZE			imgOutput;
		// ��ģʽ��Ϣ
		STU_FISHEYE_SUBMODE*		subMode;
		// ��ģʽ��
		int							subModeNum;     
		// У�����ͼ������ű�
		int							outputSizeRatio;
		// ����λ
		int							reserved[1];
	}STU_FISHEYE_OUT_FORMAT;

	// �����������
	typedef struct
	{
		int					x;
		int					y;
		int					hAngle;
		int					vAngle;
		int					available;
		int					reserved[3];
	}STU_FISHEYE_REGION_PARAM;

	// ����ģʽ��ʼ������
	typedef struct
	{
		STU_FISHEYE_REGION_PARAM	regionParam[9];
		int							circularOffset;
		int							panoramaOffset;
		int							useRegionParam;
		int							reserved[1];
	}STU_FISHEYE_MODE_INIT_PARAM;

	// MHF ��̨���ò���
	typedef struct
	{	
		/*�������*/
		int zoom_type;							// ��������ģʽ
		int hcam_wax;							// ����������Ӧ����Ƕ�x��ˮƽ��
		int hcam_way;							// ����������Ӧ����Ƕ�y����ֱ��
		int hcam_wmul;							// �����������ã���׼������
		int cfg_type;							// ���÷�ʽ1��0-ʹ���豸�������÷�ʽ, 1-ʹ�ò������÷�ʽ
						         
		//��ͷ����
		int prm_re;								// ͶӰ�뾶
		int prm_mul;							// ͶӰ����
		int prm_dx;								// x����ƫ��
		int prm_dy;								// y����ƫ��
		int prm_cw;								// CMOS��
		int prm_ch;								// CMOS��

		//������ʹ������������
		ENUM_LENS_TYPE mlen_type;				// �������ͷ����
		ENUM_CAMERA_TYPE mcam_type;				// ���������
		ENUM_CAMERA_TYPE hcam_type;				// ���������

		//�������
		int himg_width;                         // �����ͼ���
		int himg_height;                        // �����ͼ���
		int prm_fax;                            // ���ˮƽ�ӳ���

		//���������
		int mcam_fc;							// �����Ч����
		int mcam_cw;							// ��ͷ�����
		int mcam_ch;							// ��ͷ����� 
		int cam_height;                         // �������߶ȣ���
		int prm_ma;								// �������
 
		//���������
		int prm_hw;								// CMOS��
		int prm_hh;								// CMOS��
		int prm_fo;								// ��Ч����
		int prm_ca;								// ��Ұ����
		int prm_mmul;							// �����
	}STU_MHF_PTZ_CFG_PARAM;

	// ����ѡ�����
	typedef struct
	{
		// �������ߴ�
		STU_FISHEYE_SIZE				mainStreamSize;
		// Բ��X����,8192����ϵ
		int								originX;
		// Բ��Y����,8192����ϵ
		int								originY;
		// �뾶��С,8192����ϵ
		int								radius;
		// ��ת�Ƕ� 0-360*128
		int								lensDirection;
		// ����װģʽ
		ENUM_MODE_FISHEYE				mainMountMode;
		// ͼ����У��ģʽ
		ENUM_FISHEYE_CALIBRATE_MODE		mainCalibrateMode;	
		// ��ʼ���Ļ�����Ϣ
		STU_FISHEYE_MODE_INIT_PARAM		modeInitParam;
		// ���ͼ����Ϣ
		STU_FISHEYE_OUT_FORMAT			*outputFormat;    
		// �����������ò���
		STU_MHF_PTZ_CFG_PARAM			*configParam;      
		// �����Զ��Աȶ�, 0�ر�, 1����
		int								enableAutoContrast;
		// ֱ��ͼIIRǿ��0-255, Ĭ��128, Խ��Խ�ο���ǰ֡
		int								alphaHistogram;
		// �Ҷ�����ǿ��0-255, Ĭ��245, Խ��Խ�Աȶ���
		int								alphaGray;  
		// ��ǰģʽ��ץͼ�ֱ���
		STU_FISHEYE_SIZE				captureSize;
		// IN �������������� 0,1,2...
		int								mhfptzIndex;
		// ����λ
		int								reserved[1];
	}STU_FISHEYE_OPT_PARAM;

	// ���۵�����̨����
	typedef struct
	{
		ENUM_FISHEYE_EPTZ_CMD			ePtzCmd;
		int								winId;					
		int								arg1;
		int								arg2;
		int								arg3;
		int								arg4;
		int								arg5;
		int								arg6;
		int								reserved0[6];
		void*							pParam;
		void*							pResult;
		void*							pArg;   
		int								reserved1[7];
	}STU_FISHEYE_EPTZ_PARAM;

	// ������Ϣ�ص�����
	typedef void (CALLBACK* fFishEyeInfomationCallBack)( 
		LONG nPort,
		BYTE byCorrectMode,
		WORD wRadius,
		WORD wCircleX,
		WORD wCircleY,
		UINT widthRatio,
		UINT heightRatio,
		BYTE gain,
		BYTE denoiseLevel,
		BYTE installStyle,
		void* pUserData);

	////////////////////////////////////////////////////////////////////////////////////////////////

	typedef struct
	{
		int   himg_width;                       // �����ͼ���
		int   himg_height;                      // �����ͼ���
		int   *zoom_list;						// ���������
		int   zoom_list_size;					// ���������λ����
	}STU_MHF_PTZ_INIT_PARAM;

	typedef struct
	{
		int								radius;			// Ŀ������Բ�뾶��������Ϊ8192����ϵ
		int								originX;		// Ŀ������ԲԲ��X��������Ϊ8192����
		int								originY;		// Ŀ������ԲԲ��Y��������Ϊ8192����
		STU_FISHEYE_SIZE				srcSize;		// ��������Բ�Ŀ��
		STU_FISHEYE_SIZE				dstSize;		// �������ͼ�Ŀ��
		int								winId;			// Ŀ�괰�ڵ�id
		ENUM_MODE_FISHEYE				mountMode;		// ���۰�װģʽ
		ENUM_FISHEYE_CALIBRATE_MODE		calibMode;		// ����ģʽ
		STU_FISHEYE_REGION_PARAM		regionParam;	// �����������
	}STU_FISH_RECTIFY_INFO;

	// ������Ϣ
	typedef struct _STU_PLAY_DATE_TIME
	{
		unsigned int					nYear;			// ��
		unsigned int					nMonth;			// ��
		unsigned int					nDay;			// ��
		unsigned int					nHour;			// ʱ
		unsigned int					nMinute;		// ��
		unsigned int					nSecond;		// ��
		unsigned int					nMilliSecond;	// ����
	}STU_PLAY_DATE_TIME;

	typedef struct
	{
		// 1:VIDEO, 2:AUDIO, 3:DATA
		int type;		
		// I Frame, BP Frame, PCM8, MS-ADPCM etc.
		int subtype;	
		// MPEG4, H264, STDH264
		int encode;		
		// I֡�����������
		int sequence;		

		// ͼ����
		int width;
		// ͼ��߶�
		int height;

		// ֡����Ϣ
		int rate;

		// ʱ����Ϣ
		int year;
		int month;
		int day;
		int hour;
		int minute;
		int secode;
		LONG timestamp;

		int channels;
		int bitspersample;
		int samplespersecond;
	}STU_DEMUX_INFO_BASE;

	typedef struct 
	{
		char*							pHead;			// ֡����
		int								nLen;			// ֡���ݳ���
		char*							pBody;			// ������
		int								nBodyLen;		// �����ݳ���
		int								nRet;			// 0:�������� 1:������  Ĭ��Ϊ0
		char							reserved[128];	// Ԥ��λ
	}STU_DEMUX_INFO_EX;

	// �ļ���Ϣ֡
	typedef struct _STU_PLAY_FRAME_INFO
	{
		unsigned int			nFrameSubType;			// ֡�����ͣ���������֡���¼�֡��
		STU_PLAY_DATE_TIME*		pstDateTimeStart;		// ��ʼʱ��
		STU_PLAY_DATE_TIME*		pstDateTimeEnd;			// ����ʱ��
		unsigned char*			pFrameData;				// ֡����
		unsigned int			nFrameDataLen;			// ֡���ݳ���
	} STU_PLAY_FRAME_INFO;

	typedef struct _STU_PLAY_FRAME_SEARCH_INFO
	{
		unsigned int			nFileFrameType;			// ��������
		STU_PLAY_DATE_TIME		stStartDataTime;		// ��ʼʱ��
		STU_PLAY_DATE_TIME		stEndDataTime;			// ����ʱ��
		STU_DISPLAY_RECT		rtDetectedRegion;		// �������еĶ����ⷶΧ������֡ʱ��Ч���������Ϊ0ʱ��Ϊȫ��������
		STU_DISPLAY_RECT		rtTotal;				// ������, ����֡ʱ��Ч
	} STU_PLAY_FRAME_SEARCH_INFO;

	typedef struct
	{
		ENUM_IMAGE_FORMAT_TYPE	imageType;				// ͼƬ������
		unsigned char*			pPicBuf;				// ͼƬ�Ļ���ָ��
		unsigned int			nPicBufLen;				// ͼƬ�ĳ���
	} STU_IMAGE_FILE_INFO;

	typedef struct
	{
		int						x;						// ���Ͻ�x����
		int						y;						// ���Ͻ�y����
		int						width;					// ������
		int						height;					// ����߶�
	}STU_IVS_ROI;

	typedef struct
	{
		ENUM_IVSEFUNC_TYPE		eFuncType;				// ����ѡ��
		STU_IVS_ROI				cRoi;					// ROI ����
		int						nMode;					// 0-ͼƬģʽ, 1-��Ƶģʽ
		int						nProcess_param[2];		// �����������Χ[1,5]
	}STU_IVS_PARAMS;

	////////////////////////////////////////////////////////////////////////////////////////////////

	/**********************************************************************************
	����:	PlayMS_GetPictureQuality
	����:	��ȡͼ������
	����:	nPort:				�˿ں�
			bHighQuality:		TRUE ��ʾ������, FALSE ��ʾ������.
	����:	BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetPictureQuality(LONG nPort, BOOL *bHighQuality);

	/**********************************************************************************
	����: PlayMS_Version
	����: ��ȡ�汾��
	����: 
	����: DWORD
	**********************************************************************************/
	PLAYMS_API DWORD CALLMETHOD PlayMS_Version();

	/**********************************************************************************
	����:	PlayMS_ConvertToBmpFile
	����:	ͼ���ʽתΪBMP��ʽ.
	����:	pBuf			ͼ������ָ��
			nSize			ͼ�����ݴ�С
			nWidth			ͼ����
			nHeight			ͼ��߶�
			nType			��������
			sFileName		������ļ���
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_ConvertToBmpFile(char * pBuf, LONG nSize, LONG nWidth, LONG nHeight, LONG nType, char *sFileName);

	/**********************************************************************************
	����:	PlayMS_ConvertToJpegFile
	����:	ͼ���ʽתΪJPEG��ʽ.
	����:	pYUVBuf			ͼ������ָ��
			nWidth			ͼ����
			nHeight			ͼ��߶�
			YUVtype			YUV��������
			quality			ͼƬѹ������,��Χ(0, 100].
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_ConvertToJpegFile(char *pYUVBuf, LONG nWidth, LONG nHeight, int YUVtype, int quality, char *sFileName);

	/**********************************************************************************
	����:	PlayMS_SetGPSCallBack
	����:	GPS��Ϣ��ȡ����
	����:	nPort:				�˿ں�
			pFunc:				GPS��Ϣ�ص�����
			pUserData:			�û�����
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef int (CALLBACK *fGPSInfoCallBack)(char* pBuf, LONG nLen, void* pUserData);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetGPSCallBack(LONG nPort, fGPSInfoCallBack pFunc, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_InitDisk
	����:	��ʼ��Ӳ��(Windows32ƽ̨)
	����: 
	����:	�ɹ�����Ӳ������, ʧ�ܷ���0   
	**********************************************************************************/
	//PLAYMS_API UINT CALLMETHOD PlayMS_InitDisk();

	/**********************************************************************************
	����:	PlayMS_QueryFileList
	����:	�ļ���ѯ�붨λ(Windows32ƽ̨)
	����:	�ɹ������ļ�����, ʧ�ܷ���0 
	**********************************************************************************/
	//PLAYMS_API UINT CALLMETHOD PlayMS_QueryFileList(UINT nChannel, ALTIME start_time, ALTIME end_time,
	//	UINT *pmax_ret_num, pFILE_INFO pfile_info, UINT type, BYTE hint, UINT driver_type);

	/**********************************************************************************
	����:	PlayMS_SetReordPosition
	����:	����¼��
	����:	nPort				���Ŷ˿�
			nFileStartPos		�ļ���ʼλ��
			nFileEndPos			�ļ�����λ��
			pRecPosPerCB		¼���ļ��������Ȼص�
			pUserData			�û�����
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE
	**********************************************************************************/
	typedef void (CALLBACK *fRecPosPercentCallBack)(int nPercent, void* pUserData);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetReordPosition(LONG nPort, 
		LONG nFileStartPos, LONG nFileEndPos, fRecPosPercentCallBack pRecPosPerCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_SetDisplayScale
	����:	������ʾ������С
	����:	nPort			�˿ں�
			fScale			��ʾ����, Ĭ��1.0
			nRegionNum		��ʾ�������, 0~(MAX_DISPLAY_WND-1)
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_SetDisplayScale(LONG nPort, float fScale, DWORD nRegionNum);

	/**********************************************************************************
	������:	PlayMS_SetSecurityKey
	����:	����aes������Կ
	����:	nPort			����ͨ����
			szKey			��Կ��ָ��
			nKeylen			��Կ�ĳ���       
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE.
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_SetSecurityKey(LONG nPort,const char* szKey,DWORD nKeylen);

	/**********************************************************************************
	����:	PlayMS_StartFisheye
	����:	������Ƶ�����㷨����
	����:	nPort				�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_StartFisheye(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_OperateFisheyeParams
	����:	����/��ȡ���۲���
	����:	nPort				�˿ں�
			emOptType			��������
			pOptParam			���۲���
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_OptFisheyeParams(LONG nPort,
	//	TYPE_FISHEYE_OPERATE emOptType, STU_FISHEYE_OPT_PARAM* pOptParam);

	/**********************************************************************************
	����:	PlayMS_FisheyeSecondRegion
	����:	���ڸ���ģʽ�¿�����رյڶ������۴���
	����:	nPort				�˿ں�
			hDestWnd			��ʾ���ھ��
			pOptParam			�ڶ������ڶ�Ӧ�����۲���
			bEnable				�򿪻�ر���ʾ����
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_FisheyeSecondRegion(LONG nPort, 
	//	HWND hDestWnd, STU_FISHEYE_OPT_PARAM* pOptParam, BOOL bEnable);

	/**********************************************************************************
	����:	PlayMS_FisheyeEptzUpdate
	����:	����������̨,���в���
	����:	nPort				�˿ں�
			pEptzParam			���ڲ���
			bSecondRegion		�Ƿ�Ϊ����ģʽ�µĵڶ�������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_FisheyeEptzUpdate(LONG nPort, STU_FISHEYE_EPTZ_PARAM* pEptzParam, BOOL bSecondRegion);

	/**********************************************************************************
	����:	PlayMS_StopFisheye
	����:	ֹͣ��Ƶ�����㷨����
	����:	nPort				�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_StopFisheye(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_SetFishEyeInfoCallBack
	����:	���û�ȡ���ۻص�
	����:	nPort				�˿ں�
			pFishEyeInfoFun		�ص�����ָ��,����ΪNULL,�������������:
				nPort			�˿ں�
				byCorrectMode	����ģʽ
				wRadius			�뾶
				wCircleX		Բ�ĺ�����
				wCircleY		Բ��������
				widthRatio		�����
				heightRatio		�߱���
				gain			����
				denoiseLevel	����ȼ�
				InstallStyle	���۰�װ��ʽ
			pUserData,�û��Զ������.
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	// typedef void (CALLBACK* fFishEyeInfomationCallBack)( 
	// 	LONG nPort,
	// 	BYTE byCorrectMode,
	// 	WORD wRadius,
	// 	WORD wCircleX,
	// 	WORD wCircleY,
	// 	UINT widthRatio,
	// 	UINT heightRatio,
	// 	BYTE gain,
	// 	BYTE denoiseLevel,
	// 	BYTE installStyle,
	// 	void* pUserData );
	// 
	// PLAYMS_API BOOL CALLMETHOD PlayMS_SetFishEyeInfoCallBack(LONG nPort, fFishEyeInfomationCallBack pFishEyeInfoFun, void* pUserData );

	/**********************************************************************************
	����:	PlayMS_SetEngine
	����:	ָ��������
	����:	nPort				�˿ں�
			decodeType			����ģʽH264
			renderType, ��Ⱦģʽ
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE. 
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_SetEngine(LONG nPort, DecodeType decodeType, RenderType renderType);

	/**********************************************************************************
	����:	PlayMS_CheckHWDecEnv
	����:	ָ��������(Windowsƽ̨)
	����: 
	����:	֧�ַ���TRUE,��֧�ַ���FALSE.   
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_CheckHWDecEnv();

	/**********************************************************************************
	����:	PlayMS_SetVisibleDecCallBack(����ʹ��PlayMS_SetVisibleDecodeCallBack)
	����:	����ص�(��Ҫ�ڴ�����ʱ����߼�����)
	����:	nPort				�˿ں�
			DecCBFun			�ص�����ָ��,����ΪNULL,��������
				nPort			�˿ں�
				pBuf			����������Ƶ����
				nSize			���ݳ���
				pFrameInfo		֡��Ϣ,���FRAME_ATTRI_INFO�ṹ��.
				pUserData		�û��Զ������
				nReserved		����λ.
			pUserData			�û��Զ������.
	����:	BOOL,�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void (CALLBACK* fVisibleDecCallBack)(LONG nPort, char* pBuf, LONG nSize, FRAME_ATTRI_INFO* pFrameInfo, void* pUserData, LONG nReserved);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetVisibleDecCallBack(LONG nPort, fVisibleDecCallBack fVisibleDecCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_SetDecCallBack(����ʹ��PlayMS_SetDecodeCallBack)
	����:	���ý���ص���ֻ���룩
	����:	nPort				�˿ں�
			DecCBFun			����ص�����ָ��,����ΪNULL.��������:
				nPort			�˿ں�
				pBuf			����������Ƶ����
				nSize			����������Ƶ����pBuf�ĳ���
				pFrameInfo		ͼ���������Ϣ,��μ�FRAME_ATTRI_INFO�ṹ��
				nReserved		��������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void (CALLBACK* fFrameDecCallBack)(LONG nPort, char* pBuf, LONG nSize, FRAME_ATTRI_INFO* pFrameInfo, void* pUserData, LONG nReserved);
	//PLAYMS_API BOOL CALLMETHOD PlayMS_SetDecCallBack(LONG nPort, fFrameDecCallBack DecCBFun);

	/**********************************************************************************
	����:	PlayMS_SetDecCallBackEx(����ʹ��PlayMS_SetDecodeCallBack)
	����:	���ý���ص�
	����:	nPort				�˿ں�
			DecCBFun			����ص�����ָ��,����ΪNULL.�κ�������:
				nPort			�˿ں�
				pBuf			����������Ƶ����
				nSize			����������Ƶ����pBuf�ĳ���
				pFrameInfo		ͼ���������Ϣ,��μ�FRAME_ATTRI_INFO�ṹ��
				nReserved		��������
			pUserData			�û��Զ������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_SetDecCallBackEx(LONG nPort, fFrameDecCallBack DecCBFun, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_SetRotateAngle
	����:	ͼ��ת
	����:	nRotateType			��ת����,��Χ[0,3]. 
								0����ת; 1��ת90��; 2��ת180��; 3��ת270��.
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetRotateAngle(LONG nPort , int nRotateType);

	/**********************************************************************************
	����:	PlayMS_SetDelayTime
	����:	�����ӳ�ʱ��
	����:	nDelay				�ӳ�ʱ��(ms)
								�������ʱ�俪ʼ���ţ�����С�ڴ�ֵ��ʼ��΢����
			nThreshold			��ֵʱ��(ms)
								���﷧ֵ��ʼ��΢���
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetDelayTime(LONG nPort, int nDelay, int nThreshold);

	/**********************************************************************************
	����:	PlayMS_SetAudioRecScaling
	����:	������Ƶ�ɼ��������ű���
	����:	fRatio				���ű���.
								����0С��1Ϊ��Ƶ��С; 1Ϊԭʼ��Ƶ; ����1Ϊ��Ƶ�Ŵ�.
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetAudioRecScaling(float fRatio);

	/**********************************************************************************
	����:	PlayMS_GetAudioRecScaling
	����:	��ȡ��Ƶ�ɼ��������ű���
	����:	pfRatio				���ű���.
								����0С��1Ϊ��Ƶ��С; 1Ϊԭʼ��Ƶ; ����1Ϊ��Ƶ�Ŵ�.
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetAudioRecScaling(float* pfRatio);

	/**********************************************************************************
	����:	PlayMS_SetAudioRenderScaling
	����:	������Ƶ�������ű���
	����:	nPort				�˿ں�
			fRatio				���ű���.
								����0С��1Ϊ��Ƶ��С; 1Ϊԭʼ��Ƶ; ����1Ϊ��Ƶ�Ŵ�.
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetAudioRenderScaling(LONG nPort, float fRatio);

	/**********************************************************************************
	����:	PlayMS_GetAudioRenderScaling
	����:	��ȡ��Ƶ�������ű���
	����:	nPort				�˿ں�
			pfRatio				���ű���.
								����0С��1Ϊ��Ƶ��С; 1Ϊԭʼ��Ƶ; ����1Ϊ��Ƶ�Ŵ�.
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetAudioRenderScaling(LONG nPort, float* pfRatio);

	/**********************************************************************************
	����:	PlayMS_SetFileRefCallBackEx
	����:	���ý��������ص�,�Է��������������.���ļ���ʱ�����ļ�����.��ʱ�ϳ�
	����:	nPort				�˿ں�
			pFileRefDoneEx		�ص�����ָ��,������������:
				nPort			�˿ں�
				bIndexCreated	����������־,TRUE���������ɹ�;FALSEʧ��.
				pUserData		�û��Զ������
			pUserData,�û��Զ������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void (CALLBACK *fFileRefDoneCallBackEx)(DWORD nPort, BOOL bIndexCreated, void* pUserData);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetFileRefCallBackEx(LONG nPort, fFileRefDoneCallBackEx pFileRefDoneCBFunEx, void* pUserData);

	/**********************************************************************************
	����:	Play_OneByOneBack
	����:	��֡���ˣ��������ļ���������֮����ܵ���.ÿ����һ�ε���һ֡
	����:	nPort				�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_OneByOneBack(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_StartAVIConvert
	����:	��ʼAVIת��������AVIת��״̬�ص�.
	����:	nPort					�˿ں�
				pAVIConvertCB		�ص�����,������������:
				nPort				�˿ں�
				lMediaChangeType	TYPE_MEDIACHANGE_FRAMERATE��ʾ֡�ʸı�;
									TYPE_MEDIACHANGE_RESOLUTION��ʾ�ֱ��ʸı�
				pUserData			�û��Զ������
				pIsNewFile			TRUE��ֶ�ת��;FALSE���ֶΣ�Ĭ�ϲ��ֶ�
				sNewFileName		����ֶ�ת��,�µ�¼���ļ���
			pUserData				�û��Զ������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void (CALLBACK* fAVIConvertCallBack)(LONG nPort, LONG lMediaChangeType, void* pUserData, BOOL *pIsNewFile, char *sNewFileName);
	PLAYMS_API BOOL CALLMETHOD PlayMS_StartAVIConvert(LONG nPort, char *sFileName, fAVIConvertCallBack pAVIConvertCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_StopAVIConvert
	����:	ֹͣAVIת��.
	����:	nPort					�˿ں�
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StopAVIConvert(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_SetEncChangeMsg
	����:	���÷ֱ��ʸı�֪ͨ��Ϣ
	����:	nPort				�˿ں�
			hWnd				��Ϣ���͵Ĵ���
			nMsg				�û��������Ϣ
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetEncChangeMsg(LONG nPort, HWND hWnd, UINT nMsg);

	/**********************************************************************************
	����:	PlayMS_CatchResizePic
	����:	ץͼ
	����:	nPort				�˿ں�
			sFileName			�ļ�����
			lTargetWidth		ָ����ͼ����
			lTargetHeight		ָ����ͼ��߶�
			eImageFormat		ͼƬ��ʽ
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_CatchResizePic(LONG nPort, char* sFileName, 
		LONG lTargetWidth, LONG lTargetHeight, ENUM_IMAGE_FORMAT_TYPE eImageFormat);

	/**********************************************************************************
	����:	PlayMS_GetPicBMP
	����:	ץȡBMPͼ��
	����:	nPort				�˿ں�
			pBmpBuf				���BMPͼ�����ݵĻ����ַ
								���û�����,����С��bmp ͼ���С,
								�Ƽ���С:sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + 4 * w * h
								����w��h�ֱ�Ϊͼ����.
			dwBufSize			��������С
			pBmpSize			ʵ��BMPͼ���С
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetPicBMP(LONG nPort, PBYTE pBmpBuf, DWORD dwBufSize, DWORD* pBmpSize);

	/**********************************************************************************
	����:	PlayMS_GetPicBMPEx
	����:	ץȡBMPͼ��
	����:	nPort			�˿ں�
			pBmpBuf			���BMPͼ�����ݵĻ����ַ
							���û�����,����С��bmp ͼ���С,
							�Ƽ���С:sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + 4 * w * h
							����w��h�ֱ�Ϊͼ����.
			dwBufSize		��������С
			pBmpSize		ʵ��BMPͼ���С
			nWidth			ָ����bmp�Ŀ�
			nHeight			ָ����bmp�ĸ�
			nRgbType		ָ��RGB��ʽ 0-RGB32; 1-RGB24;
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetPicBMPEx(LONG nPort, PBYTE pBmpBuf,
		DWORD dwBufSize, DWORD* pBmpSize, LONG nWidth, LONG nHeight, int nRgbType);

	/**********************************************************************************
	����:	PlayMS_GetPicJPEG
	����:	ץȡJPEGͼ��.
	����:	nPort			�˿ں�
			pJpegBuf		���JPEGͼ�����ݵĻ����ַ
							���û�����,����С��JPEGͼ���С,
							�Ƽ���С: w *h * 3 / 2
							����w��h�ֱ�Ϊͼ����.
			dwBufSize		��������С.
			pJpegSize		��ȡ����ʵ��JPEGͼ���С.
			quality			JPEGͼ���ѹ������, ȡֵ��ΧΪ(0,100].
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetPicJPEG(LONG nPort, PBYTE pJpegBuf, DWORD dwBufSize, DWORD* pJpegSize, int quality);

	/**********************************************************************************
	����:	PlayMS_GetPicTIFF
	����:	ץȡTIFFͼ��
	����:	nPort			�˿ں�
			pTiffBuf		���TIFFͼ�����ݵĻ����ַ
							���û�����,����С��tiffͼ���С,
							�Ƽ���С: w * h * 3 + 1024,
							����w��h�ֱ�Ϊͼ����.
			dwBufSize		��������С
			pTiffSize		��ȡ����ʵ��TIFFͼ���С
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetPicTIFF(LONG nPort, PBYTE pTiffBuf, DWORD dwBufSize, DWORD* pTiffSize);

	/**********************************************************************************
	����:	PlayMS_VerticalSyncEnable
	����:	��ֱͬ����ʾ���أ�PlayMS_Play ����á�
	����:	nPort			�˿ں�
			bEnable			TRUE�򿪴�ֱͬ��, FALSE�رմ�ֱͬ��.
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_VerticalSyncEnable(LONG nPort, BOOL bEnable);

	/**********************************************************************************
	����:	PlayMS_OpenAudioRecord
	����:	����Ƶ�ɼ�����.
	����:	pOpenAudioRecCB			��Ƶ�ɼ����ݻص�ָ��,������������:
				pBuf				�ص�����ָ��
				nLen				�ص����ݳ���
				pUserData			�û�����
			nBitsPerSample			��ʾÿ����������Ҫ��λ��
			nSamplesPerSec			������
			nLength					���ݻ���ĳ���
			nReserved				��������
			pUserData				�û��Զ�������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void (CALLBACK *fOpenAudioRecCallBack)(LPBYTE pBuf, DWORD nLen, void* pUserData);
	PLAYMS_API BOOL CALLMETHOD PlayMS_OpenAudioRecord(fOpenAudioRecCallBack pOpenAudioRecCB, LONG nBitsPerSample, LONG nSamplesPerSec, LONG nLength, LONG nReserved, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_CloseAudioRecord
	����:	�ر���Ƶ�ɼ�����
	����: 
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_CloseAudioRecord();

	/**********************************************************************************
	����:	PlayMS_CatchPicEx
	����:	PlayMS_CatchPic����չ�ӿ�,�÷������PlayMS_CatchPic.��ָ��ͼƬ��ʽ
	����:	nPort				�˿ں�
			sFileName			�ļ�����
			emImagefomat		ͼƬ��ʽ	
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_CatchPicEx(LONG nPort, char* sFileName, ENUM_IMAGE_FORMAT_TYPE emImagefomat);

	/**********************************************************************************
	����:	PlayMS_SetEncTypeChangeCallBack
	����:	����ͼ��ֱ��ʸı�֪ͨ�ص�
	����:	nPort				�˿ں�
			pEncChangeCB		�ص�����
				nPort			�˿ں�
				pUserData		�û��Զ�������
			pUserData,�û��Զ������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void(CALLBACK *fEncChangeCallBack)(LONG nPort, void* pUserData);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetEncTypeChangeCallBack(LONG nPort, fEncChangeCallBack pEncChangeCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_SetEncTypeChangeCallBackEx
	����:	����ͼ��ֱ��ʸı�֪ͨ�ص�
	����:	nPort			�˿ں�
			pEncChangeCB	�ص�����
				nPort		�˿ں�
				pUserData	�û��Զ�������
			 pUserData		�û��Զ������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void(CALLBACK *fEncChangeCallBackEx)(LONG nPort, void* pUserData,LONG nWidth, LONG nHeight);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetEncTypeChangeCallBackEx(LONG nPort, fEncChangeCallBackEx pEncChangeCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_ResetBuffer
	����:	��ջ�������ʣ������
	����:	nPort			�˿ں�
			nBufType
				TYPE_MEDIA_VIDEO_SRC_BUF	1 ��ƵԴ����
				TYPE_MEDIA_AUDIO_SRC_BUF	2 ��ƵԴ����
				TYPE_MEDIA_VIDEO_RENDER_BUF 3 �������Ƶ���ݻ���
				TYPE_MEDIA_AUDIO_RENDER_BUF 4 �������Ƶ���ݻ���
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_ResetBuffer(LONG nPort, DWORD nBufType);

	/**********************************************************************************
	����:	PlayMS_GetBufferValue
	����:	��ȡָ���������Ĵ�С
	����:	nPort			�˿ں�
			nBufType
				TYPE_MEDIA_VIDEO_SRC_BUF 1 ��ƵԴ����
				TYPE_MEDIA_AUDIO_SRC_BUF 2 ��ƵԴ����
				TYPE_MEDIA_VIDEO_RENDER_BUF 3 �������Ƶ���ݻ���
				TYPE_MEDIA_AUDIO_RENDER_BUF 4 �������Ƶ���ݻ���
	����:	���ݻ��������ͷ��ز�ͬ�Ļ�����ֵ
	**********************************************************************************/
	PLAYMS_API DWORD CALLMETHOD PlayMS_GetBufferValue(LONG nPort, DWORD nBufType);

	/**********************************************************************************
	����:	PlayMS_GetRefValue
	����:	��ȡ�ļ�����,�Ա��´δ�ͬһ���ļ�ʱֱ��ʹ�������Ϣ.�������������ɺ���ܻ����Ϣ.
	����:	nPort			�˿ں�
			pBuffer			������Ϣ
			pSize			����pBuffer�Ĵ�С
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetRefValue(LONG nPort, BYTE *pBuffer, DWORD *pSize);

	/**********************************************************************************
	����:	PlayMS_SetRefValue
	����:	�����ļ�����,������Ϣ����׼ȷ.
	����:	nPort,�˿ں�
			pBuffer,������Ϣ
			nSize,������Ϣ�ĳ���
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetRefValue(LONG nPort,BYTE *pBuffer, DWORD nSize);

	/**********************************************************************************
	����:	PlayMS_SetDisplayRegion
	����:	���û�������ʾ����
	����:	nPort			�˿ں�
			nRegionNum		��ʾ�������,0~(MAX_DISPLAY_WND-1)
							���Ϊ0,�����õ�������ʾ����������.
			pSrcRect		�ֲ���ʾ����
			hwnd			���ھ��
			bDisplay		�򿪻�ر���ʾ����
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetDisplayRegion(LONG nPort, 
		DWORD nRegionNum, STU_DISPLAY_RECT *pSrcRect, HWND hwnd, BOOL bDisplay);

	/**********************************************************************************
	����:	PlayMS_AdjustWaveAudio
	����:	����WAVE����,���Ըı������Ĵ�С.
	����:	nPort			�˿ں�
			nCoefficient	�����Ĳ���
							��Χ�� MIN_WAVE_COEF(-100) �� MAX_WAVE_COEF(100), 0 �ǲ�����
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_AdjustWaveAudio(LONG nPort, LONG nCoefficient);

	/**********************************************************************************
	����:	PlayMS_SetPicQuality
	����:	����ͼ������
	����:	nPort			�˿ں�
			bHighQuality	TRUEͼ�������, FALSE��������Ĭ��FALSE
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetPicQuality(LONG nPort, BOOL bHighQuality);

	/**********************************************************************************
	����:	PlayMS_PlaySoundShare
	����:	�Թ���ʽ��������,���ű�·��������ȥ�ر�����·������.
	����:	nPort			�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_PlaySoundShare(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_StopSoundShare
	����:	�رչ���ʽ������.��ͬһ��������,����ͨ������ʹ����ͬ�ķ�ʽ���Ż�ر�����.
	����:	nPort			�˿ں�
	����:	�ɹ����� TRUE, ʧ�ܷ��� FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StopSoundShare(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_GetSourceBufferRemain
	����:	��ȡ������ģʽ��Դ������ʣ�����ݴ�С
	����:	nPort			�˿ں�
	����:	��ǰԴ����Ĵ�С��λBYTE(�ֽ�).
	**********************************************************************************/
	PLAYMS_API DWORD CALLMETHOD PlayMS_GetSourceBufferRemain(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_GetKeyFramePos
	����:	����ָ��λ��֮ǰ�Ĺؼ�֡λ��
	����:	nPort			�˿ں�
			nValue			��ǰλ��,������ʱ���֡��,������nTypeָ��.
			nType			ָ��nValue������.���nType��TYPE_BY_FRAME_NUMBER,��nValue��ʾ֡��;
							nType��BY_FRAMTIME, ��nValue��ʾʱ��, ��λms.
			pFramePos		�ؼ�֡���ļ�λ����Ϣ�ṹָ��
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS_INFO pFramePos);

	/**********************************************************************************
	����:	PlayMS_GetNextKeyFramePos
	����:	����ָ��λ��֮��Ĺؼ�֡λ��
	����:	nPort			�˿ں�
			nValue			��ǰλ��,������ʱ���֡��,������nTypeָ��.
			nType			ָ��nValue������.���nType��TYPE_BY_FRAME_NUMBER,��nValue��ʾ֡��;
							nType��BY_FRAMTIME, ��nValue��ʾʱ��, ��λms.
			pFramePos		�ؼ�֡���ļ�λ����Ϣ�ṹָ��
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetNextKeyFramePos(LONG nPort,DWORD nValue, DWORD nType, PFRAME_POS_INFO pFramePos);

	/**********************************************************************************
	����:	PlayMS_GetColor
	����:	��ȡ��Ƶ����
	����:	nPort			�˿ں�
			nRegionNum		��ʾ����,�ο�PlayMS_SetDisplayRegion
							���ֻ��һ����ʾ����(ͨ�����)��Ϊ0.
			pBrightness		����,Ĭ��64;��Χ0-128.
			pContrast		�Աȶ�,Ĭ��64;��Χ0-128.
			pSaturation		���Ͷ�,Ĭ��64;��Χ0-128.
			pHue			ɫ��,Ĭ��64;��Χ0-128.
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetColor(LONG nPort, DWORD nRegionNum, int *pBrightness, int *pContrast, int *pSaturation, int *pHue);

	/**********************************************************************************
	����:	PlayMS_SetColor
	����:	������Ƶ����
	����:	nPort			�˿ں�
			nRegionNum		��ʾ����
							���ֻ��һ����ʾ����(ͨ�����)��Ϊ0.
			nBrightness		����,Ĭ��64;��Χ0-128.
			nContrast		�Աȶ�,Ĭ��64;��Χ0-128.
			nSaturation		���Ͷ�,Ĭ��64;��Χ0-128.
			nHue			ɫ��,Ĭ��64;��Χ0-128.
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetColor(LONG nPort, DWORD nRegionNum, int nBrightness, int nContrast, int nSaturation, int nHue);

	/**********************************************************************************
	����:	PlayMS_GetLastError
	����:	��ȡ������
	����:	nPort			�˿ں�
	����:	��õ�ǰ����Ĵ�����
	**********************************************************************************/
	PLAYMS_API DWORD CALLMETHOD PlayMS_LastError(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_RigisterDrawCallBackEx
	����:	ע���ͼ�ص�����
	����:	nPort			�˿ں�
			nReginNum		��ʾ�������,��Χ[0,(MAX_DISPLAY_WND-1)].
							���nRegionNumΪ0, �����õ�������ʾ����������.
			pRegDrawCB		��ͼ�ص�����,�������������:
				nPort		�˿ں�
				hDc			��ͼ������豸������(DC)
				pUserData	�û��Զ������
			pUserData		�û��Զ������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void (CALLBACK* fRegDrawCallBackEx)(LONG nPort,LONG nReginNum, HDC hDc, void* pUserData);
	PLAYMS_API BOOL CALLMETHOD PlayMS_RigisterDrawCallBackEx(LONG nPort, LONG nReginNum, fRegDrawCallBackEx pRegDrawCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_CreateFile
	����:	���ļ����Զ�����˿ں�
	����:	sFileName		�ļ���
	����:	�ɹ����ض˿ںţ�ʧ�ܷ���0
	**********************************************************************************/
	PLAYMS_API DWORD CALLMETHOD PlayMS_CreateFile(LPSTR sFileName);

	/**********************************************************************************
	����:	PlayMS_DestroyFile
	����:	�ر��ļ����ͷ��Զ�����Ķ˿ں�
	����:	nPort			�˿ں�
	����:	�ɹ�����TRUE��ʧ�ܷ���FALSE
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_DestroyFile(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_RefreshPlay
	����:	ˢ����ʾ
	����:	
	����:	�ɹ�����TRUE��ʧ�ܷ���FALSE
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_RefreshPlay(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_SetupPrepareTime
	����:	����Ԥ¼�Ļ���
	����:	nPort:		����ͨ����
			nTime:		Ԥ¼������
			tmpDir:		��ʱ��Ԥ¼Ŀ¼    
	����ֵ: �ɹ�����TRUE, ʧ�ܷ���FALSE
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetupPrepareTime(LONG nPort,int nTime,const char* tmpDirectory);

	/**********************************************************************************
	����:	PlayMS_StartPrepareRecord
	����:	��ʼԤ¼
	����:	nPort:		����ͨ����
			pFileName	¼��λ��     
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StartPrepareRecord(LONG nPort,const char* pFileName);

	/**********************************************************************************
	����:	PlayMS_StopPrepareRecord
	����:	ֹͣԤ¼
	����:	nPort:		����ͨ����       
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StopPrepareRecord(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_SetIVSCallBack
	����:	����IVS�ص�
	����:	nPort				����ͨ��
			pGetIVSInfoCB		���ý���ص�
				pBuf			����ָ��
				nType			��������
				nLen			���ݴ�С
				nRealLen		������ʵ��С
				pReserved		��������
				pUserData		�û��Զ�������
			pUserData			�û��Զ�������  
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE
	**********************************************************************************/
	typedef void (CALLMETHOD *fGetIVSInfoCallBack)(char* pBuf, LONG nType, LONG nLen, LONG nRealLen, void* pReserved, void* pUserData);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetIVSCallBack(LONG nPort, fGetIVSInfoCallBack pGetIVSInfoCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_GetRealFrameBitRate
	����:	��ȡ���ʴ�С
	����:	nPort				����ͨ��
			pBitRate			���ʴ�С
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetRealFrameBitRate(LONG nPort, double* pBitRate);

	/**********************************************************************************
	����:	PlayMS_StartAVIResizeConvert
	����:	�ı�ֱ��ʵ�AVIת��
	����:	nPort				����ͨ��
			sFileName			AVI��¼���ŵ��ļ���
			lWidth				AVI��¼��Ŀ�
			lHeight				AVI��¼��ĸ�        
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StartAVIResizeConvert(LONG nPort, char *sFileName, LONG lWidth, LONG lHeight);

	/**********************************************************************************
	����:	PlayMS_StopAVIResizeConvert
	����:	����AVIת��
	����:	nPort:				����ͨ����	        
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StopAVIResizeConvert(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_SetPandoraWaterMarkCallBack
	����:	/
	����:	/
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_SetPandoraWaterMarkCallBack(LONG nPort, fGetWaterMarkInfoCallBack pFunc, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_SetDigitalSignCallBack
	����:	��������ǩ���ص�.
	����:	nPort					����ͨ��
			pCheckDigitalSignCB		����ǩ���ص�
				nPort				����ͨ��
				nFrameID			֡���
				bSuccess			У���Ƿ�ͨ��
				pUserData			�û��Զ������	        
			pUserData				�û��Զ������	     
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE
	**********************************************************************************/
	typedef void (CALLBACK* fCheckDigitalSignCallBack)(LONG nPort, int nFrameID, BOOL bSuccess, void* pUserData);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetDigitalSignCallBack(LONG nPort, fCheckDigitalSignCallBack pCheckDigitalSignCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_GetTimePicture
	����:	��þ���ʱ��������ͼƬ
	����:	sFilepath				������ļ�·��
			pstTime					����ʱ��
			pDecCB					����ص�
			pUserData				�û��Զ������        
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_GetTimePicture(const char* sFilepath, struct tm* pstTime, fFrameDecCallBack pDecCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_StartFisheyeEx
	����:	��������������չ�ӿ�
	����:	nPort					�˿ں�
			nStartType				��������	
									0ֻ��������У��, 1ͬʱ����������У��, 2ֻ�������������㷨
			nFuncType				������������
									0��ʾ����������1��ʾֻ��������֡���ܣ�2��ʾֻ����ץͼ��
									3��ʾ����֡��ץͼ�������������Ĺ���Խ�࣬���ĵ��ڴ�Խ��
			pstParam				����������ʼ��ͨ��������nStartType = 0 ʱ��pstParam = NULL
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_StartFisheyeEx(LONG nPort, int nStartType, int nFuncType, STU_MHF_PTZ_INIT_PARAM* pstParam);

	/**********************************************************************************
	����:	PlayMS_StartFisheyeMPTZ
	����:	��������������չ�ӿڣ�֧��һ�����
	����:	nPort					�˿ں�
			nStartType				��������
									0ֻ��������У��, 1ͬʱ����������У��, 2ֻ�������������㷨
			nFuncType				��������
									0��ʾ����������1��ʾֻ��������֡���ܣ�2��ʾֻ����ץͼ��
									3��ʾ����֡��ץͼ�������������Ĺ���Խ�࣬���ĵ��ڴ�Խ��
			pstParam				����������ʼ��ͨ��������nStartType = 0 ʱ��pstParam = NULL
			nPtzChannelNum			����������ʼ��ͨ����  
			pstFishEyeSize			���ͼ�����ķֱ���
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_StartFisheyeMPTZ(LONG nPort, int nStartType, int nFuncType, STU_MHF_PTZ_INIT_PARAM* pstParam, int nPtzChannelNum, STU_FISHEYE_SIZE* pstFishEyeSize);

	/**********************************************************************************
	����:	PlayMS_SetFisheyeParams
	����:	�������۲���
	����:	nPort					�˿ں�
			nX						����Բ�ĺ�����
			nY						����Բ��������
			nRadius					���۰뾶
			nLensDirection			��ͷ���� 
			stMode					ͼ����ʾģʽ
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_SetFisheyeParams(LONG nPort, int nX, int nY, int nRadius, int nLensDirection, FISHSHOWMODES stMode);

	/**********************************************************************************
	����:	PlayMS_FisheyeGetPosition, ���ݾɰ汾���۽ӿ�
	����:	���Ŀ�����Ķ�Ӧ������̨�Ľ���λ��
	����:	nPort				�˿ں�
			nRow				Ŀ������������
			nCol				Ŀ������������
			pX					Ŀ����������Ӧ������̨�Ľ��������
			pY					Ŀ����������Ӧ������̨�Ľ���������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_FisheyeGetPosition(LONG nPort, int nRow, int nCol, int *pX, int *pY);

	/**********************************************************************************
	����:	PlayMS_FisheyeEptzUpdate
	����:	����������̨�����������ƶ�
	����:	nPort				�˿ں�
			pX					������̨�Ľ��������
			pY					eptz�Ľ���������
			pHangle				eptz��ˮƽ�Ƕȷ�Χ(0-3600)
			pVangle				eptz�Ĵ�ֱ�Ƕȷ�Χ(0-900)
			ops					FISHEPTZOPTS�ṹ��,
								0ʱ��ָ���������ý��㣬1��ʾ�Ŵ�2��ʾ��С��3��ʾ�����ƶ���
	                            4��ʾ�����ƶ���5��ʾ�����ƶ���6��ʾ�����ƶ���7��ʾ�Զ�˳ʱ����ת
								8��ʾ�Զ���ʱ����ת 9��ʾֹͣ��̨������10��ʾ��ȡ��ǰ��̨��������λ��
			nWndNum				Ҫ����eptz�Ĵ��ڱ�ţ����Ͻ�win_numΪ1�������ҵ���
			nZoomStep			�Ŵ���С�Ĳ���, ��Χ1-8
			nPtStep				���������ƶ��Ĳ���, ��Χ1-8
			nRotateStep			��ת�Ĳ���, ��Χ1-8
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	// PLAYMS_API BOOL CALLMETHOD PlayMS_OldFisheyeEptzUpdate(LONG nPort, int *pX, int *pY, int *pHAngle, int *pVAngle,
	// 	FISHEPTZOPTS ops, int nWndNum, int nZoomStep, int nPtStep, int nRotateStep);

	/**********************************************************************************
	����:	Fisheye_TrancForm_TrackFrame
	����:	1ģʽ�£���ivs����֡�еĵ�ǰ֡��Ŀ��켣����ת����ԭʼԲ������
	����:	handle				�����㷨ʵ�����
			pTrackFrame			����֡
			nTrackFrameSize		����֡��С
			ptrackframe			ԭʼ����Բ�����װ������֡
	����:	AL_FISHEYE_ERROR_NONE: �ɹ�; other: ʧ�ܡ�
	**********************************************************************************/ 	
	//PLAYMS_API BOOL CALLMETHOD PlayMS_FisheyeTrancFormTrackFrame(LONG nPort, void *pTrackFrame, int nTrackFrameSize);

	/**********************************************************************************
	����:	Fisheye_TrancForm_coordinate
	����:	��������ͼ�����꣬�����ԭʼ����ԲԲ������
	����:	pstParams				��������	
			pstInPt					����㣬8192����ϵ
			pstOutPt				����㣬8192����ϵ
	����:	AL_FISHEYE_ERROR_NONE: �ɹ�; other: ʧ�ܡ�
	**********************************************************************************/ 	
	// PLAYMS_API BOOL CALLMETHOD PlayMS_FisheyeTrancFormCoordinate(STU_FISH_RECTIFY_INFO *pstParams,
	//	STU_FISHEYE_POINT2D* pstInPt, STU_FISHEYE_POINT2D *pstOutPt);

	/**********************************************************************************
	����:	Fisheye_TrancForm_Curve
	����:	��������ͼ�����꣬�����ԭʼ����ԲԲ������
	����:	pstParams			��������
			pstPt1				����ͼ�ϵ�һ���㣬8192����ϵ
			pstPt2				����ͼ�ϵ�һ���㣬8192����ϵ
			nNum				�����ĵ����
			pstPt				ֵ��õ��ĵ����У����������˵㣬8192����ϵ
	����: AL_FISHEYE_ERROR_NONE: �ɹ�; other: ʧ��
	**********************************************************************************/ 	
	// PLAYMS_API BOOL CALLMETHOD PlayMS_FisheyeTrancFormCurve(STU_FISH_RECTIFY_INFO *pstParams, 
	//	STU_FISHEYE_POINT2D* pstPt1, STU_FISHEYE_POINT2D* pstPt2, int *nNum, STU_FISHEYE_POINT2D *pstPt);

	/**********************************************************************************
	����:	PlayMS_StartDeNoise
	����:	������Ƶȥ���㷨����(3d�����)
	����:	nPort			�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StartDeNoise(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_SetDeNoiseParams
	����:	������Ƶȥ�����
	����:	nPort			�˿ں�
			nTemporal		ʱ��ȥ��ǿ�� [0,32]
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetDeNoiseParams(LONG nPort, int nTemporal);

	/**********************************************************************************
	����:	PlayMS_StopDeNoise
	����:	ֹͣ��Ƶȥ���㷨����
	����:	nPort			�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StopDeNoise(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_StartDemistAlg
	����:	������Ƶȥ���㷨����
	����:	nPort			�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StartDemistAlg(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_SetDemistAlgParams
	����:	������Ƶȥ�����
	����:	nPort					�˿ں�
			nALightValue			�趨�Ĵ�����ǿ��ֵ����Χ0-255
			nAutoLightOn			Ĭ��Ϊ1, �������Զ�Ѱ�Ҵ�����ǿ��0-�ر��Զ��������ֶ�
			nAutoRun				Ĭ��Ϊ1, ����һֱ����ȥ���ܣ�0-�Զ��ж��Ƿ����첢ȥ��
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetDemistAlgParams(LONG nPort, int nALightValue, int nAutoLightOn, int nAutoRun);

	/**********************************************************************************
	����:	PlayMS_StopDemistAlg
	����:	ֹͣ��Ƶȥ���㷨����
	����:	nPort			�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StopDemistAlg(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_StartVSAlg
	����:	������Ƶ��ǿ�㷨����
	����:	nPort			�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StartVSAlg(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_SetVSAlgParams
	����:	������Ƶ��ǿ����
	����:	nPort				�˿ں�
			pIVSEParams			�ṹ�����
			bEnable				ʹ�ܿ���	
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetVSAlgParams(LONG nPort, STU_IVS_PARAMS* pIVSEParams, BOOL bEnable);

	/**********************************************************************************
	����:	PlayMS_StopVSAlg
	����:	ֹͣ��Ƶ��ǿ�㷨����
	����:	nPort			�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StopVSAlg(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_ConvertToBmpFile
	����:	ͼ���ʽתΪBMP��ʽ.
	����:	pBuf		ͼ������ָ��
			nSize		ͼ�����ݴ�С
			nWidth		ͼ����
			nHeight		ͼ��߶�
			nType		��������
			sFileName	Ҫ������ļ���.
			nBmpType	BMP����
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_ConvertToBmpFileEx(char* pBuf, LONG nSize, LONG nWidth, LONG nHeight, LONG nType, char *sFileName, int nBmpType);

	/**********************************************************************************
	����:	PlayMS_EnableLargePicAdjustment
	����:	�Ƿ����ø���ͼ���ڲ���������
	����:	nPort			�˿ں�
			bEnable			TRUE��ʾ���ã�FALSE��ʾ�ر�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_EnableLargePicAdjustment(LONG nPort, BOOL bEnable);

	/**********************************************************************************
	����:	PlayMS_OpenPlayGroup
	����:	���鲥��
	����:	��
	����:	�鲥�ſ��ƾ��
	**********************************************************************************/
	PLAYMS_API void* CALLMETHOD PlayMS_OpenPlayGroup();

	/**********************************************************************************
	����:	PlayMS_AddToPlayGroup
	����:	���һ·�Ѿ���������Ƶ��ͬ��������
	����:	hPlayGroup			ͬ�����ž��
			nPort				�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_AddToPlayGroup(void* hPlayGroup, LONG nPort);

	/**********************************************************************************
	����:	PlayMS_DelFromPlayGroup
	����:	��ͬ����������ɾ��ָ���˿ں�
	����:	hPlayGroup				ͬ�����ž��
			nPort					�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_DelFromPlayGroup(void* hPlayGroup, LONG nPort);

	/**********************************************************************************
	����:	PlayMS_SetPlayGroupDirection
	����:	������ӵ�ǰʱ������Ż򵹷�
	����:	hPlayGroup			ͬ�����ž��
			nDirection			���ŷ���0����ǰ��1�����
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetPlayGroupDirection(void* hPlayGroup, int nDirection);

	/**********************************************************************************
	����:	PlayMS_SetPlayGroupSpeed
	����:	�����鲥���ٶ�
	����:	hPlayGroup				ͬ����������
			fCoff					�����ٶ�,��Χ[1/64~64.0]
									С��1��ʾ���ţ�����1��ʾ����.
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetPlayGroupSpeed(void* hPlayGroup, float fSpeed);

	/**********************************************************************************
	����:	PlayMS_PausePlayGroup
	����:	��ͣ�����
	����:	hPlayGroup			ͬ�����ž��
			bPause				TRUE��ͣ,FLASE�ָ�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_PausePlayGroup(void* hPlayGroup, BOOL bPause);

	/**********************************************************************************
	����:	PlayMS_StepPlayGroup
	����:	��֡����
	����:	hPlayGroup			ͬ�����ž��
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StepPlayGroup(void* hPlayGroup);

	/**********************************************************************************
	����:	PlayMS_StepPlayGroup
	����:	���þ���ʱ����ж�λ
	����:	hPlayGroup			ͬ�����ž��
		    pstDateTime			����ʱ��
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SeekPlayGroup(void* hPlayGroup, STU_PLAY_DATE_TIME* pstDateTime);

	/**********************************************************************************
	����:	PlayMS_ClosePlayGroup
	����:	�ر�ͬ�����ſ���
	����:	hPlayGroup			ͬ�����ž��
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_ClosePlayGroup(void* hPlayGroup);

	/**********************************************************************************
	����:	PlayMS_SetFileRefCallBack
	����:	���ý��������ص������ļ���ʱ�����ļ����������̽ϳ���
	����:	nPort					�˿ں�
			pFileRefDoneCB			�ص�����ָ��, ������������:
				nPort				�˿ں�
				pUserData			�û��Զ������
			pUserData				�û��Զ������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void(CALLBACK *fFileRefDoneCallBack)(DWORD nPort, void* pUserData);									
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetFileRefCallBack(LONG nPort, fFileRefDoneCallBack pFileRefDoneCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_SetDemuxCallBack
	����:	Դ���ݷ���������ݻص�
	����:	nPort				�˿ں�
			pDemuxDecCB			�������ݻص�ָ��
				nPort			�˿ں�
				pBuf			����ָ��
				nSize			���ݳ���
				pMutexInfo		֡��Ϣ,ָ��STU_DEMUX_INFO_BASE�ṹ
				pMutexInfoEx	֡���ݻ������ݣ�ָ��STU_DEMUX_INFO_EX�ṹ
				pUserData		�û��Զ������
			pUserData			�û��Զ������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void (CALLBACK* fDemuxDecCallBack)(LONG nPort, char* pBuf, LONG nSize, void* pMutexInfo, void* pMutexInfoEx, void* pUserData);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetDemuxCallBack(LONG nPort, fDemuxDecCallBack pDemuxDecCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_SetFileDoneTimeCallBack
	����:	�ļ���ʼ������ʱ��ص����������ļ���ʼ�ͽ���ʱ������øûص���
	����:	nPort				�˿ں�
			pFileTimeCB			�ص�����ָ��,������������:
				nPort			�˿ں�
				nStartTime		�ļ���ʼʱ��(��1970��1��1��0��0��0�������)
				nEndTime		�ļ�����ʱ��(��1970��1��1��0��0��0�������)
				pUserData		�û��Զ������
			pUserData			�û��Զ������.
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void (CALLBACK* fFileTimeDoneCallBack)(LONG nPort, DWORD nStarTime, DWORD nEndTime, void* pUserData);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetFileTimeDoneCallBack(LONG nPort, fFileTimeDoneCallBack pFileTimeCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_GetKeyFramePosByAbsoluteTime
	����:	������ʱ�����ָ��λ��֮ǰ�Ĺؼ�֡λ��.
	����:	nPort				�˿ں�
			pstTime				����ʱ��
			pstFramePos			�ؼ�֡���ļ�λ����Ϣ�ṹָ��,���PFRAME_POS_INFO.
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetKeyFramePosByAbsTime(LONG nPort, SYSTEMTIME* pstTime, FRAME_POS_INFO* pstFramePos);

	/**********************************************************************************
	����:	PlayMS_GetNextKeyFramePosByAbsoluteTime
	����:	������ʱ�����ָ��λ��֮��Ĺؼ�֡λ��.
	����:	nPort			�˿ں�
			pstTime			����ʱ��
			pstFramePos		�ؼ�֡���ļ�λ����Ϣ�ṹָ��
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetNextKeyFramePosByAbsTime(LONG nPort, SYSTEMTIME* pstTime, FRAME_POS_INFO* pstFramePos);

	/**********************************************************************************
	����:	PlayMS_QueryGroupPlayingTime
	����:	��ѯ��ǰ�������ڲ��ŵ�ʱ��.
	����:	nPort			�˿ں�
			pstDateTime		ʱ��
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_QueryGroupPlayingTime(void* hPlayGroup, STU_PLAY_DATE_TIME *pstDateTime);

	/**********************************************************************************
	����:	PlayMS_GetAudioChannels
	����:	��ȡ��Ƶͨ������
	����:	nPort,�˿ں�
			pChannels, ���������[0-255].
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetAudioChannels(LONG nPort, DWORD* pChannels);

	/**********************************************************************************
	����:	PlayMS_ChooseAudio
	����:	ѡ����Ƶͨ��
	����:	nPort				�˿ں�
			nChannelID			��Ƶͨ����0��ʼ.
			bOpen				TRUE��,FALSE�ر�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_ChooseAudio(LONG nPort, DWORD nChannelID, BOOL bOpen);

	/**********************************************************************************
	����:	PlayMS_GetAudioChooseState
	����:	��ȡ��Ƶͨ���򿪹ر�״̬
	����:	nPort			�˿ں�
			nChannelID		��Ƶͨ��[0-255].
			bOpen			TRUE��,FALSE�ر�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetAudioChooseState(LONG nPort, DWORD nChannelID, BOOL *bOpen);

	/**********************************************************************************
	����:	PlayMS_SetPlayedAbsTime
	����:	������ʱ�����ò���ʱ��
	����:	nPort			�˿ں�
			pstDateTime		����ʱ��
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetPlayedAbsTime(LONG nPort, STU_PLAY_DATE_TIME *pstDateTime);

	/**********************************************************************************
	����:	PlayMS_SetPlayPosByFileOffset
	����:	���ļ�ƫ�����ò���λ��
	����:	nPort			�˿ں�
			nFileOffset		�ļ�ƫ��λ��
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetPlayPosByFileOffset(LONG nPort, UINT nFileOffset);

	/**********************************************************************************
	����:	PlayMS_GetCurrentFrameRateEx
	����:	��õ�ǰ֡�ʣ�С����ʽ��
	����:	nPort			�˿ں�
	����:	��ǰ֡��
	**********************************************************************************/
	PLAYMS_API float CALLMETHOD PlayMS_GetCurrentFrameRateEx(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_ChangeRate
	����:	�ı䲥������
	����:	nPort			�˿ں�
			nRate			��������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_ChangeRate(LONG nPort, int nRate);

	typedef void (CALLBACK *fCutProgressCallBack)(DWORD nPort, int nProgress, DWORD dwUser);
	/**********************************************************************************
	// ����: PlayMS_CutFileSegment
	// ����: /
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_CutFileSegment(LONG nPort, LONG lBeginTime, LONG lEndTime, fCutProgressCallBack pCutProgressCB, char *sOutFilePath, DWORD dwUser);

	/**********************************************************************************
	����:	PlayMS_InputVideoData
	����:	������Ƶ���ݲ���
	����:	nPort			�˿ں�
			pBuf			��Ƶ����
			nSize			���ݴ�С
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_InputVideoData(LONG nPort, PBYTE pBuf, DWORD nSize);

	/**********************************************************************************
	����:	PlayMS_InputAudioData
	����:	������Ƶ���ݲ���
	����:	nPort			�˿ں�
			pBuf			��Ƶ����
			nSize			���ݴ�С
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_InputAudioData(LONG nPort, PBYTE pBuf, DWORD nSize);

	typedef void (CALLBACK * fVerifyCallBack)(LONG nPort, FRAME_POS_INFO * pFilePos, DWORD bIsVideo, void* pUserData);
	/**********************************************************************************
	����:	PlayMS_SetVerifyCallBack
	����:	/
	����:	/
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_SetVerifyCallBack(LONG nPort, DWORD nBeginTime, DWORD nEndTime, fVerifyCallBack VerifyFun, void* pUserData);

	typedef void (CALLBACK * fSourceBufCallBack)(LONG nPort, DWORD nBufSize, void* pUserData, void* pReserved);
	/**********************************************************************************
	����:	PlayMS_SetSourceBufCallBack
	����:	/
	����:	/
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_SetSourceBufCallBack(LONG nPort, DWORD nThreShold, fSourceBufCallBack SourceBufCBFun, void* pUserData, void *pReserved);

	/**********************************************************************************
	����:	PlayMS_AdjustFluency
	����:	����ͼ��������
	����:	nPort			�˿ں�
			nLevel			�����ȵȼ� �ȼ�Խ��Խ������Խ��Խʵʱ
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_AdjustFluency(LONG nPort, int nLevel);

	/**********************************************************************************
	����:	PlayMS_SurfaceChange
	����:	Phone Surface������仯֪ͨ
	����:	nPort			�˿ں�
			hWnd			���ھ��
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SurfaceChange(LONG nPort, HWND hWnd);

	/**********************************************************************************
	����:	PLAYER_SetFileInfoFrameCallback
	����:	�����ļ���Ϣ֡�ص�����
	����:	nPort						�˿ں�
			pOnFileInfoFrameCB			�ص�����
				nPort					�˿ں�
				pstFileInfoImage		ͼ����Ϣ
				pstFileInfoFrame		֡��Ϣ
				pUserData				�û��Զ������
			emImageFormat				ͼƬ��ʽ
			pUserData					�û��Զ������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef int (CALLBACK* fOnFileInfoFrameCallBack)(LONG nPort,
		STU_IMAGE_FILE_INFO* pstFileInfoImage, STU_PLAY_FRAME_INFO* pstFileInfoFrame, void* pUserData);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetFileInfoFrameCallback(LONG nPort,
		fOnFileInfoFrameCallBack pOnFileInfoFrameCB, ENUM_IMAGE_FORMAT_TYPE emImageFormat, void* pUserData);

	/**********************************************************************************
	����:	PLAYER_SetAnalyzePositionCallback
	����:	�����ļ���Ϣ֡�������Ȼص�����
	����:	nPort					�˿ں�
			pAnalyzePositionCB		�ص�����
				nPort				�˿ں�
				pstDateTime			����������Ϣ
				pUserData			�û��Զ������
			pUserData				�û��Զ������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef int (CALLBACK *fOnAnalyzePosCallBack)(LONG nPort, STU_PLAY_DATE_TIME* pstDateTime, void* pUserData);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetAnalyzePositionCallback(LONG nPort, fOnAnalyzePosCallBack pAnalyzePositionCB, void* pUserData);

	/**********************************************************************************
	����:	PLAYER_StartFileFrameDetect
	����:	��Ҫ�������������֮�󣬿�ʼ�ļ���Ϣ֡��⣬������������
	����:	nPort			�˿ں�
			pstInfo			����������Ϣ
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StartFileFrameDetect(LONG nPort, STU_PLAY_FRAME_SEARCH_INFO* pstInfo);

	/**********************************************************************************
	����:	PlayMS_StopFileFrameDetect
	����:	��ֹ����
	����:	nPort			�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StopFileFrameDetect(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_StartEdgeEnhance
	����:	����ͼ���񻯴���
	����:	nPort			�˿ں�
			nLevel			����ȼ�, 0-�ر�, 6-��ǿ, Ĭ�ϵȼ�4
			nAlgMode		�㷨ģʽ,Ĭ�� 0
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StartEdgeEnhance(LONG nPort, int nLevel, int nAlgMode);

	/**********************************************************************************
	����:	PlayMS_StopEdgeEnhance
	����:	�ر�ͼ���񻯴���
	����:	nPort			�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StopEdgeEnhance(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_StartVideoStable
	����:	������Ƶ����
	����:	nPort			�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.	
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StartVideoStable(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_StopEdgeEnhance
	����:	�ر���Ƶ����
	����:	nPort			�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_StopVideoStable(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_Scale
	����:	Phone Ver.ͼ������
	����:	nPort			�˿ں�
			fScale			���ű���[1.0, 8.0]
			nRegionNum		��ʾ�������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_Scale(LONG nPort, float fScale, DWORD nRegionNum);

	/**********************************************************************************
	����:	PlayMS_Translate
	����:	Phone Ver.ͼ��ƽ��
	����:	nPort			�˿ں�
			fx				xƽ�����꣬����ֵ
			fy				yƽ�����꣬����ֵ
			nRegionNum		��ʾ�������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_Translate(LONG nPort, float fx, float fy, DWORD nRegionNum);

	/**********************************************************************************
	����:	PlayMS_SetIdentity
	����:	Phone Ver.ͼ���һ��,����ƽ��,���Ų�����
	����:	nPort			�˿ں�
			nRegionNum		��ʾ�������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetIdentity(LONG nPort, DWORD nRegionNum);

	/**********************************************************************************
	����:	PlayMS_GetScale
	����:	Phone Ver.��ȡ��ǰ����ֵ��
	����:	nPort			�˿ں�
			nRegionNum		��ʾ�������, ������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API float CALLMETHOD PlayMS_GetScale(LONG nPort, DWORD nRegionNum);

	/**********************************************************************************
	����:	PlayMS_GetTranslateX
	����:	Phone Ver.��ȡ��ǰx��ƽ������
	����:	nPort			�˿ں�
			nRegionNum		��ʾ�������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API float CALLMETHOD PlayMS_GetTranslateX(LONG nPort, DWORD nRegionNum);

	/**********************************************************************************
	����:	PlayMS_GetTranslateY
	����:	Phone Ver.��ȡ��ǰy��ƽ������
	����:	nPort			�˿ں�
			nRegionNum		��ʾ�������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API float CALLMETHOD PlayMS_GetTranslateY(LONG nPort, DWORD nRegionNum);

	/**********************************************************************************
	����:	PlayMS_CleanScreen, PlayMS_Stopǰ������Ч
	����:	/
	����:	
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_CleanScreen(LONG nPort, float red, float green, float blue, float alpha, DWORD nRegionNum);

	/**********************************************************************************
	����:	PlayMS_ViewResolutionChanged
	����:	/
	����:	
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_ViewResolutionChanged(LONG nPort, int nWidth, int nHeight, DWORD nRegionNum);

	/**********************************************************************************
	����:	PlayMS_StartDataRecordEx
	����:	��ʼ������¼��,ֻ����ģʽ����,��PlayMS_Play֮�����.
	����:	nPort				�˿ں�
			sFileName			¼���ļ���.
			nDataType			0��ʾԭʼ��Ƶ��;
								1��ʾת����AVI��ʽ;
								2��ʾת����ASF��ʽ;
								3�ֶα����ļ�
			pRecErrOccurCB		�ص�����
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void (CALLBACK* fRecErrOccurCallBack)(LONG nPort, void* pUserData);
	PLAYMS_API BOOL CALLMETHOD PlayMS_StartDataRecordEx(LONG nPort, char *sFileName, int nDataType, fRecErrOccurCallBack pRecErrOccurCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_SetMultiFrameDecCallBack
	����:	���ý�����Ϣ�ص�
	����:	nPort				�˿ں�
			pDecInfoCB			�ص�����
				nPort			�˿ں�
				nStreamID		����ID
				pData			��������
				nLen			���ݳ���
				pstFrameInfo	֡��Ϣ
				pUserData		�û��Զ������
				nReserved		��������
			pUserData			�û��Զ������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void (CALLBACK* fMultiFrameDecInfoCallBack)(LONG nPort, LONG nStreamID, char* pData, LONG nLen, FRAME_ATTRI_INFO* pstFrameInfo, void* pUserData, LONG nReserved);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetMultiFrameDecCallBack(LONG nPort, fMultiFrameDecInfoCallBack pDecInfoCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_SetMultiFrameCallBack
	����:	������֡��Ϣ�ص�
	����:	nPort				�˿ں�
			pMultiFrameCB		��֡�ص�����
				nPort			�˿ں�
				nStreamID		����ID
				pUserData		�û��Զ������
				nReserved		��������
			pUserData			�û��Զ������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void (CALLBACK* fMultiFrameInfoCallBack)(LONG nPort, LONG nStreamID, void* pUserData, LONG nReserved);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetMultiFrameCallBack(LONG nPort, fMultiFrameInfoCallBack pMultiFrameCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_SetDecInfoCallBack
	����:	���ý�����Ϣ�ص�
	����:	nPort				�˿ں�
			pDecInfoCB			������Ϣ�ص�
				nPort			�˿ں�
				pDecInfo		������Ϣ
				pUserData		�û��Զ������
				nReserved		��������
			pUserData			�û��Զ������
	����:	�ɹ����� TRUE, ʧ�ܷ��� FALSE.
	**********************************************************************************/
	typedef void (CALLBACK* fFrameDecInfoCallBack)(LONG nPort, STU_FRAME_DEC_INFO_EX* pDecInfo, void* pUserData, LONG nReserved);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetDecInfoCallBack(LONG nPort, fFrameDecInfoCallBack pDecInfoCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_ChooseFrame
	����:	ѡ����ʾSVAC����SVC�Ļ��������ǿ��
	����:	nPort			�˿ں�
			nFrameID		Ҫ��ʾ�Ĳ�(0: �����㣬1: ��ǿ��)
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_ChooseFrame(LONG nPort, LONG nFrameID);

	/**********************************************************************************
	����:	PlayMS_RenderPrivateData
	����:	��ʾ��������ͼ��
	����:	nPort			�˿ں�
			bShow			TRUE ��ʾ��FALSE ����ʾ
			nReserved		��������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_RenderPrivateData(LONG nPort, BOOL bShow, LONG nReserved);

	/**********************************************************************************
	����:	PlayMS_SetRenderShapeLineType
	����:	����ͼ�α߿���������
	����:	nPort			�˿ں�
			nRenderType		ͼ�ζ�������  
							ENUM_RENDER_TYPE
	        nLineType		��������  
							LINE_TYPE_SOLID_WHOLE = 0x00: ʵ�ߣ�LINE_TYPE_SOLID_HALF - 0x01: ����
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetRenderShapeLineType(LONG nPort, int nRenderType, int nLineType);

	/**********************************************************************************
	����:	PlayMS_SetRenderShapeLineType
	����:	������Ⱦ����ʹ��
	����:	nPort			�˿ں�
			nRenderType		��Ⱦ����  
							ENUM_RENDER_TYPE
	        bEnable			 
							LINE_TYPE_SOLID_WHOLE = 0x00: ʵ�ߣ�LINE_TYPE_SOLID_HALF - 0x01: ����
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetRenderTypeEnable(LONG nPort, int nRenderType, BOOL bEnable);

	/**********************************************************************************
	����:	PlayMS_SetFileIndexProgressCallBack
	����:	���������������Ȼص�
	����:	nPort					�˿ں�
			pIndexProgressCB		�������Ȼص�����
					nPort			�˿ں�
					fProgress		����ֵ
					pUserData		�û��Զ������
			pUserData				�û��Զ������
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void (CALLBACK* fIndexProgressCallBack)(LONG nPort, float fProgress, void* pUserData);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetFileIndexProgressCallBack(LONG nPort, fIndexProgressCallBack pIndexProgressCB, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_GetLastYUVFrame
	����:	������ȡ��һ֡��Ӧ��YUV����
	����:	nPort  �˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetLastYUVFrame(LONG nPort, FRAME_DEC_INFO* pFrameDecodeInfo);

	/**********************************************************************************
	����:	PlayMS_SetMemMinimized
	����:	�����ڴ��С�汾
	����:	nPort			�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	//PLAYMS_API BOOL CALLMETHOD PlayMS_SetMemMinimized(LONG nPort);

	/**********************************************************************************
	����:	PlayMS_SetDecodeThreadNum
	����:	���ý����߳���
	����:	nPort			�˿ں�
			nNum			�����߳���
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetDecodeThreadNum(LONG nPort, DWORD nNum);

	/**********************************************************************************
	����:	PlayMS_SetDecodeKey
	����:	���ý�����Կ��SVAC����ʹ��
	����:	nPort			�˿ں�
			sKey			��Կ
			nKeyLen			��Կ����
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetDecodeKey(LONG nPort, const unsigned char *sKey, unsigned int nKeyLen);

	/**********************************************************************************
	����:	PlayMS_GetIRefValue
	����:	��ȡI֡����
	����:	nPort			�˿ں�
			pBuffer			�������ݵ�ַ
			pSize			�������ݴ�С
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_GetIRefValue(LONG nPort, BYTE *pBuffer, DWORD *pSize);

#ifdef __native_client__

#define FISHEYE_REGION 16
	/**********************************************************************************
	����:	PlayMS_OutsideRender
	����:	nacl ui�̵߳��ô˽ӿ�
	����:	nPort			�˿ں�
			nWidth			���ڿ�
			nHeight			���ڸ�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_OutsideRender(LONG nPort, int nX, int nY, int nWidth, int nHeight, unsigned int nRegionNum = 0);

	namespace pp
	{
		class Instance;
	}

	/**********************************************************************************
	����:	PlayMS_SetNACLInstance
	����:	nacl ���̵߳��ô˽ӿ����þ����ַ
	����:	pInstance			����pp::instance��ַ
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetNACLInstance(pp::Instance * pInstance);
#endif

	/**********************************************************************************
	����:	PlayMS_SetDoubleVisibleDecCallBack
	����:	
	����:	
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	typedef void (CALLBACK* fDoubleVisibleDecCallBack)(
		LONG nPort,char * pBuf, int nSize, int nWidth, int nHeight, 
		char* pSecondBuf, int nSecondSize, int nSecondWidth, int nSecondHeight, void* pUserData);
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetDoubleVisibleDecCallBack(
		LONG nPort, fDoubleVisibleDecCallBack DataCBFun, void* pUserData);

	/**********************************************************************************
	����:	PlayMS_EnableAudioChannel
	����:	��������������Ƶ���ţ���������������Ƶ��Ч��
	����:	nPort			�˿ں�
			nChannel		����ͨ����0-��ͨ����1-��ͨ��
			bEnable			ʹ�� TRUE-���ã� FALSE-����
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_EnableAudioChannel(LONG nPort, DWORD nChannel, BOOL bEnable);

	/**********************************************************************************
	����:	PlayMS_SplitProc
	����:	yuv ƴ���㷨������4k��������ʾ
	����:	nPort			�˿ں�
	����:	nMode			ģʽ
						0��Ӧ����ģʽ��1��Ӧ1+3ģʽ��2��Ӧ1+5ģʽ, 
						3��Ӧ1+1ģʽ�����ӷŴ�4��Ӧ1P+3, 5��Ӧ1P+6
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SplitProc(LONG nPort, int nMode);

	/**********************************************************************************
	����:	PlayMS_SplitProcUpdate
	����:	yuv ƴ���㷨��������Ҫ�Ŵ�ľ���λ��
	����:	nPort			�˿ں�
			pAreaRect		���������������ʼ��ַ
							���nMode��0����ӦΪNULL
							���nMode��1���������Ĵ�СӦΪ3
							���nMode��2���������Ĵ�СӦΪ5
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SplitProcUpdate(LONG nPort, STU_DISPLAY_RECT* pAreaRect);

	/**********************************************************************************
	����:	PlayMS_SetRenderMode
	����:	ָ����Ⱦģʽ(Windowsƽ̨), PlayMS_Play֮ǰ������Ч
	����:	nPort				�˿ں�
			nMode				��Ⱦģʽ
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetRenderMode(LONG nPort, ENUM_TYPE_RENDER nMode);

	/**********************************************************************************
	����:	PlayMS_InitThirdPartyLibrary
	����:	��ʼ�����������ܿ�
	����:	nPort			�˿ں�
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_InitThirdPartyLibrary(LONG nPort, const char* kmcSvrIP,int kmcSvrPort,const char* macAddr);

	/**********************************************************************************
	����:	PlayMS_SetDecodeStrategy
	����:	���ý������,������������������
	����:	nPort			�˿ں�
			nAVSyncType		16:��ʾ����������frame����������ǰ����
							8: ��ʾ�����������������ݲ�����Э�鵱�ɽ������
							0: ��ʾ�����������������ݲ�����Э��������룬���������Ứ��
	����:	�ɹ�����TRUE,ʧ�ܷ���FALSE.
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetDecodeStrategy(LONG nPort, int nStrategyType);

	/**********************************************************************************
	����:	PlayMS_SetAVSyncType
	����:	��������Ƶ���Ų���
	����:	nPort			�˿ں�
			nAVSyncType		�������Ż�׼����
							nAVSyncType=0������ƵΪ��׼��nAVSyncType=1������ƵΪ��׼
	����:	�ɹ�����TRUE, ʧ�ܷ���FALSE
	**********************************************************************************/
	PLAYMS_API BOOL CALLMETHOD PlayMS_SetAVSyncType(LONG nPort,	ENUM_SYNC_TYPE nAVSyncType);

#ifdef	__cplusplus
}
#endif

#endif // _AL_PLAY_V2_H