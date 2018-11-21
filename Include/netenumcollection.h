#ifndef _AL_NET_ENUM_COLLECTION_H
#define _AL_NET_ENUM_COLLECTION_H

/*****************************************************************************************
 *							netmanager library ö�ٶ���									 *
 *****************************************************************************************/

// ��������
typedef enum
{
	LANGUAGE_CHINESE_SIMPLIFIED,		// ��������    
	LANGUAGE_CHINESE_TRADITIONAL,		// ��������   
	LANGUAGE_ENGLISH,					// Ӣ��       
	LANGUAGE_JAPANESE,					// ���İ�    
	LANGUAGE_RUSSIAN,					// ���İ�        
	LANGUAGE_FRENCH,					// ���İ�        
	LANGUAGE_GERMAN,					// ���İ�  
	LANGUAGE_FARSI,						// ��˹��     
}EM_SP_LANGUAGE_TYPE;

// ����״̬
typedef enum
{
	EM_LINK_STATUS_UNKNOWN,                  // δ֪
	EM_LINK_STATUS_CONNECTED,                // ������
	EM_LINK_STATUS_NOT_CONNECTED,            // δ����
	EM_LINK_STATUS_CONNECT_FAILED,           // ����ʧ��
	EM_LINK_STATUS_AUTHENTICATION_FAILED,    // ��֤ʧ��
	EM_LINK_STATUS_CONNECT_TIMEOUT,          // ���ӳ�ʱ
	EM_LINK_STATUS_NOT_EXIST,                // �豸������
}EM_LINK_STATUS;

// ��¼Э������
typedef enum
{
	EM_LOGIN_PROTOCAL_TYPE_INVALID      = 0x00,		// ��Ч�ĵ�½��ʽ
	EM_LOGIN_PROTOCAL_TYPE_TCP          = 0x01,		// TCP��½
	EM_LOGIN_PROTOCAL_TYPE_UDP          = 0x02,		// UDP��½
	EM_LOGIN_PROTOCAL_TYPE_MULTICAST    = 0x03,		// �鲥��½

	EM_LOGIN_PROTOCAL_TYPE_CLOUD        = 0x04,		// �Ƶ�½��ʽ
	EM_LOGIN_PROTOCAL_TYPE_SERVER		= 0x05,		// ��������ʽ����
}EM_LOGIN_PROTOCAL_TYPE;

// ץͼ����
typedef enum
{
	// BMP32����
	SNAPSHOT_FORMAT_TYPE_BMP32 = 0,
	// BMP24����
	SNAPSHOT_FORMAT_TYPE_BMP24,
	// TIFF����
	SNAPSHOT_FORMAT_TYPE_TIFF,
	// JPEG���� 100% ����
	SNAPSHOT_FORMAT_TYPE_JPEG_100,		
	// 80%������JPEG����
	SNAPSHOT_FORMAT_TYPE_JPEG_80,	
	// 60%������JPEG����
	SNAPSHOT_FORMAT_TYPE_JPEG_60,	
	// 40%������JPEG����
	SNAPSHOT_FORMAT_TYPE_JPEG_40,	
	// 20%������JPEG����
	SNAPSHOT_FORMAT_TYPE_JPEG_20,	
	// 10%������JPEG����
	SNAPSHOT_FORMAT_TYPE_JPEG_10,	
}EM_SNAPSHOT_FORMAT_TYPE;

// ����ӿ�����
typedef enum
{
	VINTERFACE_TYPE_UNKNOWN = -1,			// δ֪����ӿ�
    VINTERFACE_TYPE_REALPLAY,				// ʵʱ���ӽӿ�
    VINTERFACE_TYPE_MULTI_PREVIEW,			// �໭��Ԥ���ӿ�
    VINTERFACE_TYPE_PLAYBACK,				// �طŽӿ�
	VINTERFACE_TYPE_REALLOAD,				// ��������ͼƬ�ӿ�
    VINTERFACE_TYPE_DOWNLOAD,				// ���ؽӿ�
	VINTERFACE_TYPE_UPLOAD,					// �ϴ��ӿ� 
} EM_VIRTUAL_INTERFACE_TYPE;

// ������ͨ�ö���
typedef enum
{		
	CODE_RETURN_TYPE_UNKNONW = -1,						// δ֪
	CODE_RETURN_TYPE_NORMAL = 0,						// ����
	CODE_RETURN_TYPE_NOAUTH = 1,						// ��Ȩ�޴���
	CODE_RETURN_TYPE_NOSUPPORT = 2,						// ��֧�ִ���
	CODE_RETURN_TYPE_RESLIMIT = 3,						// ��Դ���޷�����
	CODE_RETURN_TYPE_DATA_NOORDER = 4,					// ���ݴ��ҷ�����
	CODE_RETURN_TYPE_DATA_END = 5,						// ���ݽ���������

	CODE_RETURN_TYPE_VIDEO_STREAM_DISCONNECT = 0x8000,	// ��Ƶ���Ͽ����󷵻���
}EM_CODE_RETURN_TYPE;

// H264 ����ȼ�
typedef enum
{
	// �ṩI/P֡����֧��progressiv��CAVLC
    EM_H264_ENCODE_LEVEL_BASELINE = 1,   
	// �ṩI/P/B֡��֧��progressiv��interlaced���ṩCAVLC��CABAC
    EM_H264_ENCODE_LEVEL_MAIN,
	// �ṩI/P/B/SP/SI֡����֧��progressive(����ɨ��)��CAVLC
    EM_H264_ENCODE_LEVEL_EXTEND,
	// FRExt��Main_Profile������������8x8 intra prediction(8x8 ֡��Ԥ��)
    EM_H264_ENCODE_LEVEL_HIGH,
}EM_H264_ENCODE_LEVEL;

/////////////////////////////////�������/////////////////////////////////

// Ԥ������
typedef enum
{
    REALPLAY_STREAM_TYPE_REAL = 0,             // ʵʱԤ��
    REALPLAY_STREAM_TYPE_MULTI,                // �໭��Ԥ��
    REALPLAY_STREAM_TYPE_REAL_MASTER,          // ʵʱ����-������
    REALPLAY_STREAM_TYPE_REAL_SLAVE_1,         // ʵʱ����-������1
    REALPLAY_STREAM_TYPE_REAL_SLAVE_2,         // ʵʱ����-������2
    REALPLAY_STREAM_TYPE_REAL_SLAVE_3,         // ʵʱ����-������3    
} EM_REALPLAY_STREAM_TYPE;


// ��Ƶ����
typedef enum
{
	REALAUDIO_STREAM_TYPE_REAL_MASTER,          // ʵʱ����-������
	REALAUDIO_STREAM_TYPE_REAL_SLAVE_1,         // ʵʱ����-������1
	REALAUDIO_STREAM_TYPE_REAL_SLAVE_2,         // ʵʱ����-������2
	REALAUDIO_STREAM_TYPE_REAL_SLAVE_3,         // ʵʱ����-������3    
} EM_REALAUDIO_STREAM_TYPE;

// �����ļ�����
typedef enum
{
	DEVICE_CONFIG_ALL = 0,						// ȫ�������ļ�
	DEVICE_CONFIG_LOCAL,						// ���������ļ�
	DEVICE_CONFIG_NETWORK,						// ���������ļ�
	DEVICE_CONFIG_USER,							// �û������ļ�
} EM_DEVICE_CONFIG_TYPE;

// �豸Э������
typedef enum
{
	DEVICE_PROTOCOL_TYPE_GB28181 = 0x0000,	// GB28181
	DEVICE_PROTOCOL_TYPE_ONVIF,				// Onvif  
	DEVICE_PROTOCOL_TYPE_TS,                // ��׼TS
	DEVICE_PROTOCOL_TYPE_VNC,               // ������������

	DEVICE_PROTOCOL_TYPE_SELF = 0x0080,		// ��˾Э��

	DEVICE_PROTOCOL_TYPE_UNKNOWN = 0xFFFF,	// ���û��Զ���   
} EM_DEVICE_PROTOCOL_TYPE;

// ��Ƶ����װ��ʽ
typedef enum
{
	VIDEO_PACK_FORMAT_RYMS,             // RYMS
	VIDEO_PACK_FORMAT_PS,               // PS
	VIDEO_PACK_FORMAT_ASF,              // ASF
	VIDEO_PACK_FORMAT_MP4,              // MP4
	VIDEO_PACK_FORMAT_TS,               // TS
} EM_VIDEO_PACK_FORMAT_TYPE;

// ��Ƶ��������
typedef enum
{
	VIDEO_STREAM_ERROR,                    // ����
	VIDEO_STREAM_MASTER,                   // ������
	VIDEO_STREAM_SLAVE_1,                  // ������1
	VIDEO_STREAM_SLAVE_2,                  // ������2
	VIDEO_STREAM_SLAVE_3,                  // ������3
}EM_VIDEO_STREAM_TYPE;

/////////////////////////////////////////////////////////////////////////////////

// ��������
typedef enum
{
	// ����Ƶ��������
	DEVICE_CAPS_TYPE_ENCODE,

	// ¼��������
	DEVICE_CAPS_TYPE_RECORD,

	///////////////////////////////////////

	// ��Ƶ����������-ȫ������
	DEVICE_CAPS_VIDEOIN,	

	// ��Ƶ����������-��ȷ���ù�Ȧ����
	DEVICE_CAPS_VIDEOIN_IRIS,

	// ��Ƶ����������-����������
	DEVICE_CAPS_VIDEOIN_HALOCUT,

	// ��Ƶ����������-����������
	DEVICE_CAPS_VIDEOIN_METERING,

	// ��Ƶ����������-ͼ�������������
	DEVICE_CAPS_VIDEOIN_IMAGE_CTRL,

	// ��Ƶ����������-�ع���������
	DEVICE_CAPS_VIDEOIN_EXPOSURE,

	// ��Ƶ����������-��ҹ��������
	DEVICE_CAPS_VIDEOIN_DAY_NIGHT,

	// ��Ƶ����������-��ƽ����������
	DEVICE_CAPS_VIDEOIN_WHITE_BALANCE,

	// ��Ƶ����������-��������
	DEVICE_CAPS_VIDEOIN_IR,

	// ��Ƶ����������-��������
	DEVICE_CAPS_VIDEOIN_DENOISE,

	// ��Ƶ����������-͸������
	DEVICE_CAPS_VIDEOIN_DEFOG,	

	// ��Ƶ��������
	DEVICE_CAPS_VIDEO_ENCODE,

	// �ַ���������
	DEVICE_CAPS_OSD,

	// ��Ƶ�������
	DEVICE_CAPS_VIDEO_DETECT,
		
	// ��Ƶ��������
	DEVICE_CAPS_AUDIOIN,

	// ��Ƶ�������
	DEVICE_CAPS_AUDIOOUT,	

	///////////////////////////////////////
	// ֧�ֵ�ƽ̨����
	DEVICE_CAPS_INTER_PROTOCOL,

	///////////////////////////////////////
	// ����ʶ������
	DEVICE_CAPS_TYPE_FACE_RECOGNIZE,

	///////////////////////////////////////

	// ��������
	DEVICE_CAPS_COUNT,
}EM_DEVICE_CAPS_TYPE;

//��������
typedef enum
{
	// �豸ϵͳ����
	DEVICE_CFG_SYS = 0x0000,
	// ��������
	DEVICE_CFG_NET,
	// ʱ������
	DEVICE_CFG_SYS_TIME,
	// ����ʱ����
	DEVICE_CFG_TIME_DST,
	// NTP����
	DEVICE_CFG_NTP,
	// ͨ������
	DEVICE_CFG_CHANNEL,
	// ¼������
	DEVICE_CFG_RECORD,
	// ��������
	DEVICE_CFG_SERIAL_PORT,
	// �Խ�����
	DEVICE_CFG_TALK,
	// �Զ�ά������
	DEVICE_CFG_AUTO_MAINTAIN,
	// ����ʶ���������
	DEVICE_CFG_FACE_RECOGNIZE_RULES,
	// ץ��ģʽ����
	DEVICE_CFG_CAPTURE_MODE,
	// ץ����������
	DEVICE_CFG_SNAP_TIMES,

	// Web HTTP/HTTPS ����
	DEVICE_CFG_WEB,
	// RTSP ����
	DEVICE_CFG_RTSP,
	// NetService ����
	DEVICE_CFG_NET_SERVICE,
	// �˿�����
	DEVICE_CFG_NET_PORT,
	// WIFIʹ������ ���û��߻�ȡwifiʹ������
	DEVICE_CFG_WIFI_ENALE,
	// WIFI��������,����ɨ��,����,�Ͽ�����
	DEVICE_CFG_WIFI_OPERATE,

	// ˮӡ����
	DEVICE_CFG_WATERMARK,
	// ����ͷ��������
	DEVICE_CFG_CAMERA,

	// ��ƵOSD��������
	DEVICE_CFG_VIDEO_OSD,

	// �洢����
	DEVICE_CFG_STORAGE,
	// ����洢��������
	DEVICE_CFG_NET_STORAGE_TRANS,

	// Telnet����
	DEVICE_CFG_TELNET,

	// ��־����
	DEVICE_CFG_LOGSEARCH,
	// �ڰ�����
	DEVICE_CFG_NETWHITEBLACK,

	// �û�����
	DEVICE_CFG_USER,
	// ��ȡ�����û�
	DEVICE_CFG_USER_ONLINE,

	// ��ͼ����
	DEVICE_CFG_SNAP_CUTOUT,
	// ������ץͼ����
	DEVICE_CFG_OVERLAP_PIC,
	// ����������ܳ�������
	DEVICE_CFG_INTELLI_SCENE_FACE_DETECT,
	// ��������������
	DEVICE_CFG_INTELLI_RULE_FACE_DETECT,
	// �������ͳ������
	DEVICE_CFG_INTELLI_RULE_FACE_DETECT_STAT,
	// ��������
	DEVICE_CFG_ALARM_PARAM,
	// ��������
	DEVICE_CFG_ENCODE_PARAM,

	// GB28181��������
	DEVICE_CFG_GB28181_PARAM,
	// ONVIF ����
	DEVICE_CFG_ONVIF,
	// �Ʒ�������
	DEVICE_CFG_CLOUD_SERVICE,

	// CFG ���ø���
	DEVICE_CFG_COUNT,
}EM_DEVICE_CFG_TYPE;        

// ��������
typedef enum 
{
	// �豸��������(�¼�)
	DEVICE_ALARM_TYPE_REBOOT,
	// ������ϱ���(�¼�)
	DEVICE_ALARM_TYPE_NET_BROKEN,
	// IP��ͻ����(�¼�)
	DEVICE_ALARM_TYPE_IP_CONFLICT,
	// MAC��ͻ����(�¼�)
	DEVICE_ALARM_TYPE_MAC_CONFLICT,
	// ��Դ���ϱ���(�¼�)
	DEVICE_ALARM_TYPE_POWER_BROKEN,
	// ��½ʧ�ܱ���(�¼�)
	DEVICE_ALARM_TYPE_LOGIN_FAIL,
	// ����ע���豸���µ�½(�¼�)
	DEVICE_ALARM_TYPE_REGISTER_RELOGIN,
	// �޸����÷��ر���(�¼�)
	DEVICE_ALARM_TYPE_CONFIG_RETURN,
	// �豸�������뿪ʼ�����Խ�(�¼�)
	DEVICE_ALARM_TYPE_AUTO_START_TALK,
	// �豸����ֹͣ�����Խ�(�¼�)
	DEVICE_ALARM_TYPE_AUTO_STOP_TALK,
	// IP����(�¼�)
	DEVICE_ALARM_TYPE_IP_SEARCH,
	// �Զ�����ʧ��(�¼�)
	DEVICE_ALARM_TYPE_RECONNECT_FAIL,
	// ����ʧ��(�¼�)
	DEVICE_ALARM_TYPE_REALPLAY_FAIL,
	// �ط�ʧ��(�¼�)
	DEVICE_ALARM_TYPE_PLAYBACK_FAIL,
	// ���������Խ�ʧ��(�¼�)
	DEVICE_ALARM_TYPE_TALK_FAIL,
}EM_DEVICE_ALARM_TYPE;

// ��ƽ������
typedef enum
{
	WHITEBALANCE_DISABLE,		// "Disable"(��ֹ)
	WHITEBALANCE_AUTO,			// "Auto"(�Զ�)
	WHITEBALANCE_SUNNY,			// "Sunny"(����,6500K����)
	WHITEBALANCE_CLOUDY,		// "Cloudy"(����,7500K����)
	WHITEBALANCE_HOME,			// "Home"(���� 5000K����)
	WHITEBALANCE_OFFICE,		// "Office"(�칫 4400K����)
	WHITEBALANCE_NIGHT,			// "Night"(ҹ�� 2800K����)
	WHITEBALANCE_CT_HIGH,		// "HighColorTemperature"(��ɫ������),
	WHITEBALANCE_CT_LOW,		// "LowColorTemperature"(��ɫ������), 
	WHITEBALANCE_CT_AUTO,		// "AutoColorTemperature"(�Զ�ɫ������),
	WHITEBALANCE_CT_CUSTOM,		// "CustomColorTemperature"(�Զ���ɫ�µȼ�),
	WHITEBALANCE_PART,			// "PartWhiteBalance"(�Զ���������ƽ��),

} EM_WHITE_BALANCE;

// ץͼ��Ƶ��������
typedef enum 
{
	VS_CODE_TYPE_MPEG4 = 0,
	VS_CODE_TYPE_H264 = 1,
	VS_CODE_TYPE_H265 = 2,
	VS_CODE_TYPE_JPEG = 3,
}EM_VIDEO_STREAM_CODE_TYPE;

// ���������б�
typedef enum
{
	VIDEO_FORMA_CTRL_CBR = 0,
	VIDEO_FORMA_CTRL_VBR = 1,
	VIDEO_FORMA_CTRL_MBR = 2,
}EM_VIDEO_FORMA_CTRL_TYPE;

//�ֱ�������
typedef enum
{
	EM_VIDEO_RESOLUTION_CIF = 0,//CIF  352 * 288 
	EM_VIDEO_RESOLUTION_D1,// 704*576
	EM_VIDEO_RESOLUTION_720P,//1280*720
	EM_VIDEO_RESOLUTION_1080P,//1920*1080
	EM_VIDEO_RESOLUTION_TOTAL,

}EM_VIDEO_STREAM_RESOLUTION_TYPE;

typedef enum
{
	EM_STANDARD_PAL = 0,
	EM_STANDARD_NTSC,
	EM_STANDARD_TOTAL,
}EM_STANDARD_TYPE;

/////////////////////////////////////////////////////////////////////////////////

typedef enum
{
	// ����ͼƬ���ݿ�
	DB_TYPE_FACE_PICTRUE = 0,
	// ��ͨ¼�����ݿ�
	DB_TYPE_RECORD = 10,
}EM_DATABASE_TYPE;

typedef enum
{
	ST_FILE_TYPE_UNKNOWN = -1,
	ST_FILE_TYPE_RECORD = 0,
	ST_FILE_TYPE_IMAGE = 1,
}EM_ST_FILE_TYPE;

// ��������
typedef enum
{
	// ����
	ORDER_TYPE_ASCENT = 0,
	// ����
	ORDER_TYPE_DESCENT,
}EM_ORDER_TYPE;

/////////////////////////////////////////////////////////////////////////////////
// ������ & ����

// �Ա�����
typedef enum
{
	SEX_TYPE_UNKNOWN = -1,		// δ֪����������
	SEX_TYPE_MALE = 0,			// ����
	SEX_TYPE_FEMALE = 1,		// Ů��
}EM_SEX_TYPE;

/////////////////////////////////////////////////////////////////////////////////

// �¼�����
typedef enum
{
	// ��������ͼƬ
	EVENT_SP_ALL = 0x00000001,

	/////////////////////////////////////////////////////////////////
	// ץȡ��������ͼ�¼�
	EVENT_SP_FACE_SNAP_WHOLE = 0x00001000,
	// ������ͼ�¼�
	EVENT_SP_FACE_SNAP_PART	= 0x00001001,

	// ����ʶ�𱳾�ͼ�¼�
	EVENT_SP_FACE_RECOGNIZE_WHOLE = 0x00001002,
	// ����ʶ���ͼ�¼�
	EVENT_SP_FACE_RECOGNIZE_CUTOUT = 0x00001003,

	/////////////////////////////////////////////////////////////////
	// ��ͨ�ֶ�ץ���¼�
	EVENT_SP_TRAFFIC_SNAP_MANUAL = 0x00004000,

	// ��ͨ�����¼�
	EVENT_SP_TRAFFIC_PASS = 0x00004001,
	// ��ͨ���ڿ�ͼ�¼�
	EVENT_SP_TRAFFIC_PASS_CUTOUT = 0x00004002,

}EM_EVENT_SP_TYPE;

typedef enum
{
	EMVIDEO_MOVING_DETECT,						// ��̬��� "VideoMovingDetect"
	EMSWITCH_IN_ALAM,							// ���ر��� "SwitchInAlarm"
	EMNETWORK,									// ����״̬ "Network"
	EMNETCONFIG_CHANGE,							// ��������޸� "NetconfigChange"
	EMSYSTEM_WORKING_STATE,						// ϵͳ����״̬ "SystemWorkingState"
	EMUPGARDE,									// ���� "Upgrade"
	EMRESET,									// ϵͳ��λ		 "Reset"							
} EM_ALARM_TYPE;

typedef enum
{
	FACE_EXTRACT_OPT_ADD = 0x01,				// �����⽨ģ����-�������
	FACE_EXTRACT_OPT_DELETE = 0x02,				// �����⽨ģ����-ɾ������
}EM_FACE_EXTRACT_OPERATE_TYPE;
/////////////////////////////////////////////////////////////////////////////////

#endif //_AL_NET_ENUM_COLLECTION_H