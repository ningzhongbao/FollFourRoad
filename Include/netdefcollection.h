#ifndef _AL_NET_DEF_COLLECTION_H
#define _AL_NET_DEF_COLLECTION_H

/*****************************************************************************************
 *							netmanager library �궨��									 *
 *****************************************************************************************/

#if defined(WIN32) || defined(WIN64)
#include <windows.h>
#ifndef INT64
	#define INT64  __int64
#endif
#endif

#ifndef LLONG
	#ifdef WIN64
		#define LLONG INT64
	#else 
		#define LLONG long
	#endif
#endif

#ifndef LDWORD
#if (defined(WIN32) || defined(WIN64))
#ifdef WIN64
#define LDWORD  __int64
#else //WIN32 
#define LDWORD  DWORD
#endif
#else    //linux
#define LDWORD	long 
#endif
#endif

#if !defined(WIN32) && !defined(WIN64)
#include "../Platform/platform.h"
#endif

////////////////////////////////////////////////////////////////////////////////////////////
// COMMON
#ifndef _COMMON_DEFINITION_
#define _COMMON_DEFINITION_
#define VALUE(value)		(value)
#define STRLEN(length)		(length)
#define COUNT(count)		(count)
#define ROW(row)			(row)
#define COL(col)			(col)
#endif

////////////////////////////////////////////////////////////////////////////////////////////
// DEVICE
#define MAX_CHANNEL_NUM							32						// ���ͨ����
#define MAX_VIDEO_CHANNEL_NUM					32						// ��Ƶ���ͨ����
#define	MAX_RECORD_CHANNEL_NUM					32						// ���¼��ͨ����
#define MAX_ALARM_OUT_CHANNEL_NUM				32						// ��󱨾����ͨ����
#define MAX_CAPTURE_CHANNEL_NUM					32						// ���ץͼͨ����

#define MAX_NETCARD_NUM							8						// �����������ֵ
#define MAX_LOG_AMOUNT							16						// һ�β�ѯ�������־����

#define	WEEK_SECTION							7
#define	TIME_SECTION							6

#define MAX_VIDEO_OSD_CUSTOM_NUM				6						// ����Զ�����Ƶ OSD ����
#define MAX_IRIS_TYPE_NUM						6						// ����Ȧ���͸���
#define MAX_CAPS_PICTURE_OSD_NUM				3						// ͼƬ OSD ����������

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ���Լ�д��󳤶�
#define MAX_LANGUAGE_LENGTH					20

// ֧�ֵ������������
#define MAX_LANGUAGE_NUM					32

// IPv4 �� IPv6���ڰ�������Ŀ
#define MAX_NET_WB_ITEM_NUM					50

// ����洢���������Ŀ
#define MAX_NET_STORAGE_ITEM_NUM			4

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �����¼�

// ����ʶ����Ϣ�����Ŀ
#define MAX_FACE_REC_INFO_NUM				5

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ������ & ����

// �����������Ŀ
#define MAX_FACE_GROUP_NUM					3

// ��Ա���������Ŀ
#define MAX_PERSON_FACE_NUM					3

// һ�β�ѯ����Ա�����Ŀ
#define MAX_ONCE_QUERY_PERSON_NUM			64

// һ�β�ѯ������ʶ��ȶԼ�¼�����Ŀ
#define MAX_ONCE_QUERY_FACE_REC_REC_NUM		128

// �������ʶ���¼���
#define MAX_FACE_REC_RESULT_NUM				8

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// ��������ش�����
#define _FACE_ERR_CODE(x)						(0x00090000|x)
#define FACE_ERR_UNKNOWN						_FACE_ERR_CODE(1)		// δ֪����
#define FACE_ERR_GROUP_NAME_CONFLICT			_FACE_ERR_CODE(2)		// �����׿�������ͻ
#define FACE_ERR_GROUP_ALIAS_CONFLICT			_FACE_ERR_CODE(3)		// �����׿��������ͻ
#define FACE_ERR_GROUP_GUID_CONFLICT			_FACE_ERR_CODE(4)		// �����׿���GUID��ͻ
#define FACE_ERR_GROUP_NUM						_FACE_ERR_CODE(5)		// �����׿������Ѵ�����
#define FACE_ERR_PERSON_NAME_CONFLICT			_FACE_ERR_CODE(6)		// �����������Ա���ֳ�ͻ
#define FACE_ERR_PERSON_CERTID_CONFLICT			_FACE_ERR_CODE(7)		// �����������Ա֤����֤���ų�ͻ
#define FACE_ERR_FACETOKEN_CONFLICT				_FACE_ERR_CODE(8)		// ��������ͼƬ Token ��ͻ
#define FACE_ERR_FACEIMAGE_BIND					_FACE_ERR_CODE(9)		// ����ͼƬ�ظ���
#define FACE_ERR_FACEIMAGE_NUM					_FACE_ERR_CODE(0x0a)	// ����������Ѵ�����
#define FACE_ERR_PERSON_FACEIMAGE_NUM			_FACE_ERR_CODE(0x0b)	// ���˴�����������Ѵ�����
#define FACE_ERR_PERSON_FACEIMAGE_OVERFLOW		_FACE_ERR_CODE(0x0c)	// ���˴������������������
#define FACE_ERR_FACEIMAGE_EMPTY				_FACE_ERR_CODE(0x0d)	// ����ͼƬ���ݿ�
#define FACE_ERR_PERSON_NOT_EXIST				_FACE_ERR_CODE(0x0e)	// ��Ա������
#define FACE_ERR_FACEIMAGE_NOT_EXIST			_FACE_ERR_CODE(0x0f)	// ����������
#define FACE_ERR_FACEIMAGE_ALREADY_EXIST		_FACE_ERR_CODE(0x10)	// ����ͼƬ�����
#define FACE_ERR_FACEIMAGE_NO_FACE				_FACE_ERR_CODE(0x11)	// ����ͼƬ������
#define FACE_ERR_FACEIMAGE_LOW_QUALITY			_FACE_ERR_CODE(0x12)	// �����׿��鲻����
#define FACE_ERR_GROUP_NOT_EXIST				_FACE_ERR_CODE(0x13)	// ����ͼƬ��������
#define	FACE_ERR_FACEIMAGE_TOO_LARGE			_FACE_ERR_CODE(0x14)	// ����ͼƬ���ݹ���
#define FACE_ERR_SYSTEM_BUSY					_FACE_ERR_CODE(0x15)	// ϵͳæ

// �������ʹ��ţ���Ӧ Net_LastError �ӿڵķ���ֵ
#define _ERR_CODE(x)                            (0xEC000000|x)
#define NET_NOERR								0						// û�д���
#define NET_ERR_UNKNOWN							-1						// δ֪����
#define NET_ERR_INVALID_HANDLE                  _ERR_CODE(1)            // �����Ч����
#define NET_ERR_SYS								_ERR_CODE(2)            // ϵͳ����
#define NET_ERR_NETWORK							_ERR_CODE(3)            // �������
#define NET_ERR_PROTOCOL						_ERR_CODE(4)            // Э�����
#define NET_ERR_INIT							_ERR_CODE(5)            // ��ʼ������
#define NET_ERR_UNINIT							_ERR_CODE(6)            // �������
#define NET_ERR_NO_INIT                         _ERR_CODE(7)			// δ����ʼ������
#define NET_ERR_NOT_AUTHORIZED                  _ERR_CODE(8)            // �޲���Ȩ�޴���
#define NET_ERR_ILLEGAL_PARAM                   _ERR_CODE(9)            // �û��������Ϸ�����
#define NET_ERR_RENDER_OPEN						_ERR_CODE(10)			// ����render��Դ����
#define NET_ERR_OPEN_CHANNEL					_ERR_CODE(11)           // ��ͨ��ʧ�ܴ���
#define NET_ERR_CLOSE_CHANNEL					_ERR_CODE(12)           // �ر�ͨ��ʧ�ܴ���
#define NET_ERR_NO_CHANNEL						_ERR_CODE(13)           // ͨ����Ϊ0����
#define NET_ERR_DEC_OPEN						_ERR_CODE(14)           // �򿪽�������
#define NET_ERR_DEC_CLOSE						_ERR_CODE(15)           // �رս�������
#define NET_ERR_REAL_DATA_ALREADY_SAVED         _ERR_CODE(16)           // ʵʱ�����ѱ���Ĵ���
#define NET_ERR_REAL_DATA_NOT_SAVED             _ERR_CODE(17)           // ʵʱ����δ����Ĵ���
#define NET_ERR_OPEN_FILE						_ERR_CODE(18)           // ���ļ�����
#define NET_ERR_RETURN_VERIFY                   _ERR_CODE(19)           // ��������У�����
#define NET_ERR_BUFFER_NOT_ENOUGH               _ERR_CODE(20)           // ���治�����
#define NET_ERR_NOT_SUPPORT                     _ERR_CODE(21)           // δ֧�ִ���
#define NET_ERR_RECORD_NOT_FOUND                _ERR_CODE(22)           // ��ѯ����¼�����
#define NET_ERR_BUSY                            _ERR_CODE(23)			// ����/�߳���æ����
#define NET_ERR_NO_TALK_CHANNEL                 _ERR_CODE(24)           // δ���ֶԽ�ͨ������
#define NET_ERR_NO_AUDIO                        _ERR_CODE(25)           // δ������Ƶ����
#define NET_ERR_DOWNLOAD_END                    _ERR_CODE(26)           // �����ѽ�������
#define NET_ERR_EMPTY_LIST                      _ERR_CODE(27)           // ��ѯ���Ϊ�մ���
#define NET_ERR_AUDIO_ENCODE_NOT_INIT           _ERR_CODE(28)           // ��Ƶ����ӿ�û�гɹ���ʼ���Ĵ���
#define NET_ERR_DATA_TOO_LONG                   _ERR_CODE(29)           // ���ݹ����Ĵ���
#define NET_ERR_OPT_NOT_SUPPORT					_ERR_CODE(30)           // �豸��֧�ָò����Ĵ���
#define NET_ERR_RESOURCE_NOT_ENOUGH             _ERR_CODE(31)           // �豸��Դ����Ĵ���
#define NET_ERR_SERVER_STARTED					_ERR_CODE(32)           // �������Ѿ������Ĵ���
#define NET_ERR_SERVER_STOPPED                  _ERR_CODE(33)           // ��������δ�ɹ������Ĵ���
#define NET_ERR_INPUT_SERIAL					_ERR_CODE(34)           // �������к�����Ĵ���
#define NET_ERR_QUERY_DISK_INFO					_ERR_CODE(35)           // ��ȡӲ����Ϣʧ�ܵĴ���
#define NET_ERR_USER_PWD_TRYTIME				_ERR_CODE(36)           // ����������󳬹����ƴ����Ĵ���
#define NET_ERR_NOT_SUPPORT_SUB_PARTITION       _ERR_CODE(37)			// ��֧������Ӳ�̷����Ĵ���
#define NET_ERR_GET_AUTO_REG_SERVER             _ERR_CODE(38)			// ��ȡ�豸������ע���������Ϣʧ�ܵĴ���
#define NET_ERR_CONTROL_AUTO_REGISTER			_ERR_CODE(39)			// ����ע���ض���ע�����Ĵ���
#define NET_ERR_DISCONNECT_AUTO_REGISTER		_ERR_CODE(40)			// �Ͽ�����ע�����������Ĵ���
#define NET_ERR_CONNECT_FAIL					_ERR_CODE(41)			// ����������ʧ�ܵĴ���
#define NET_ERR_QUERY_SERIAL_PORT               _ERR_CODE(42)			// ��ѯ���ڲ���ʧ�ܵĴ���
#define NET_ERR_LOGOUT							_ERR_CODE(43)			// �ǳ��豸�Ĵ���
#define NET_ERR_GET_REQUEST_DATA				_ERR_CODE(44)			// �豸�޷���ȡ��ǰ��������
#define NET_ERR_MAC_VALIDATE					_ERR_CODE(45)			// MAC��ַ��֤ʧ�� 
#define NET_ERR_GET_SERVER_INSTANCE             _ERR_CODE(46)			// ��ȡ������ʵ��ʧ��
#define NET_ERR_JSON_REQUEST					_ERR_CODE(47)			// ���ɵ�json�ַ�������
#define NET_ERR_JSON_RESPONSE					_ERR_CODE(48)			// ��Ӧ��json�ַ�������
#define NET_ERR_VERSION_HIGHER					_ERR_CODE(49)			// Э��汾���ڵ�ǰʹ�õİ汾
#define NET_ERR_SPARE_NO_CAPACITY               _ERR_CODE(50)			// �ȱ�����ʧ��, ��������
#define NET_ERR_DISPLAY_SOURCE_OCCUPPIED        _ERR_CODE(51)			// ��ʾԴ���������ռ��
#define NET_ERR_REAVE							_ERR_CODE(52)			// �߼��û���ռ�ͼ��û���Դ
#define NET_ERR_NET_FORBID						_ERR_CODE(53)			// ��ֹ���� 
#define NET_ERR_OPERATE_OVERTIME				_ERR_CODE(54)			// ��ǰ������ʱ 
#define NET_ERR_SENIOR_VALIDATE_FAIL			_ERR_CODE(55)			// �߼�У��ʧ�� 
#define NET_ERR_DEVICE_ID_NOT_EXIST				_ERR_CODE(56)			// �豸ID������
#define NET_ERR_PROXY_DLL_LOAD					_ERR_CODE(57)			// ��������ʧ��
#define NET_ERR_PROXY_ILLEGAL_PARAM				_ERR_CODE(58)			// �����û��������Ϸ�
#define NET_ERR_PROXY_INVALID_HANDLE			_ERR_CODE(59)			// ��������Ч
#define NET_ERR_PROXY_LOGIN_DEVICE				_ERR_CODE(60)			// �������ǰ���豸ʧ��
#define NET_ERR_PROXY_START_SERVER				_ERR_CODE(61)			// �����������ʧ��
#define NET_ERR_SPEAK_FAIL						_ERR_CODE(62)			// ���󺰻�ʧ��
#define NET_ERR_CD_NOT_READY                    _ERR_CODE(63)			// ����δ����
#define NET_ERR_DIR_NOT_EXIST					_ERR_CODE(64)			// Ŀ¼������
#define NET_ERR_SPLIT_MODE_NOT_SUPPORT			_ERR_CODE(65)			// �豸��֧�ֵķָ�ģʽ
#define NET_ERR_OPEN_WND_PARAM					_ERR_CODE(66)			// �򿪴��ڲ������Ϸ�
#define NET_ERR_LIMITED_WND_COUNT				_ERR_CODE(67)			// �򿪴���������������
#define NET_ERR_REQUEST_NOT_MATCH				_ERR_CODE(68)			// ���������뵱ǰģʽ��ƥ��
#define NET_ERR_UPGRADE_FAIL					_ERR_CODE(69)			// �豸����ʧ��
#define NET_ERR_NO_TARGET_DEVICE				_ERR_CODE(70)			// �Ҳ���Ŀ���豸
#define NET_ERR_NO_VERIFY_DEVICE				_ERR_CODE(71)			// �Ҳ�����֤�豸
#define NET_ERR_CASCADE_NO_AUTHORIZED           _ERR_CODE(72)			// �޼���Ȩ��
#define NET_ERR_LOW_PRIORITY					_ERR_CODE(73)			// �����ȼ�
#define NET_ERR_REMOTE_REQUEST_TIMEOUT			_ERR_CODE(74)			// Զ���豸����ʱ
#define NET_ERR_LIMITED_INPUT_SOURCE			_ERR_CODE(75)			// ����Դ�������·������
#define NET_ERR_SET_LOG_PRINT					_ERR_CODE(76)			// ������־��ӡʧ��
#define NET_ERR_PARAM_SIZE						_ERR_CODE(77)			// ��ε�dwsize�ֶγ���
#define NET_ERR_LIMITED_MONITOR_WALL_COUNT		_ERR_CODE(78)			// ����ǽ������������
#define NET_ERR_ACCESS_FILE						_ERR_CODE(79)			// �����ļ�ʧ��
#define NET_ERR_DEVICE_STATUS_BUSY				_ERR_CODE(80)			// �豸��æ
#define NET_ERR_CTRL_DECODER_TOUR				_ERR_CODE(81)			// ���ƽ�����������Ѳʧ��
#define NET_ERR_GROUP_SUPPORT_NUM_EXCEED        _ERR_CODE(82)			// �����豸֧������û�����Ŀ
#define NET_ERR_USER_SUPPORT_NUM_EXCEED         _ERR_CODE(83)			// �����豸֧������û���Ŀ
#define NET_ERR_FILE_NOT_FOUND					_ERR_CODE(84)           // ��ѯ�����ļ�����

#define NET_ERR_MEMORY							_ERR_CODE(100)			// �ڴ����

#define NET_ERR_LOCAL_FILE_NOT_EXIST			_ERR_CODE(120)			// �����ļ�������
#define NET_ERR_LOCAL_FILE_ACCESS				_ERR_CODE(121)			// �����ļ����ʴ���
#define NET_ERR_LOCAL_FILE_SAVE					_ERR_CODE(122)			// �����ļ��������

#define NET_ERR_FACE_GROUP_CREATE				_ERR_CODE(125)			// ����������ʧ��
#define NET_ERR_FACE_GROUP_DELETE				_ERR_CODE(126)			// ɾ��������ʧ��
#define NET_ERR_FACE_GROUP_EDIT					_ERR_CODE(127)			// �༭������ʧ��
#define NET_ERR_FACE_GROUPS_GET					_ERR_CODE(128)			// ��ȡ������������Ϣʧ��
#define NET_ERR_PERSON_INFO_UPDATE				_ERR_CODE(129)			// ��Ա��Ϣ����ʧ��
#define NET_ERR_PERSON_INFO_DELETE				_ERR_CODE(130)			// ɾ����Ա��Ϣ
#define NET_ERR_PERSON_INFO_ADD					_ERR_CODE(131)			// ���������Ϣ������ͼƬʧ��
#define NET_ERR_FACE_IMAGE_ADD					_ERR_CODE(132)			// �������ͼƬʧ��
#define NET_ERR_FACE_IMAGE_DELETE				_ERR_CODE(133)			// ɾ������ͼƬʧ��
#define NET_ERR_FACE_IMAGE_UPDATE				_ERR_CODE(134)			// ��������ͼƬʧ��
#define NET_ERR_FACE_BIND						_ERR_CODE(135)			// ��������������ʧ��
#define NET_ERR_FACE_UNBIND						_ERR_CODE(136)			// ��������������ʧ��
#define NET_ERR_FI_UPDATE_INSTANCE_CREATE		_ERR_CODE(137)			// ������Ϣ���¾������ʧ��
#define NET_ERR_FI_UPDATE_INSTANCE_DELETE		_ERR_CODE(138)			// ������Ϣ���¾������ʧ��
#define NET_ERR_FACE_FEATRUE_EXTRACT			_ERR_CODE(139)			// ��ȡ��������ʧ��				
#define NET_ERR_FACE_FIND_HANDLE_CREATE			_ERR_CODE(140)			// �������Ҿ������ʧ��
#define NET_ERR_FACE_FIND_HANDLE_CLOSE			_ERR_CODE(141)			// �������Ҿ���ر�ʧ��
#define NET_ERR_FACE_FIND_HANDLE_DESTROY		_ERR_CODE(142)			// �������Ҿ������ʧ��
#define NET_ERR_FACE_PRE_FIND					_ERR_CODE(143)			// Ԥ����������Ϣʧ��
#define NET_ERR_FACE_QUERY_NO_RESULT			_ERR_CODE(144)			// ��ѯ������Ϣ�޽��
#define NET_ERR_PERSON_COUNT_QUERY				_ERR_CODE(145)			// ��ȡ��ѯ��������Ա��ʧ��
#define NET_ERR_FACE_COUNT_QUERY				_ERR_CODE(146)			// ��ȡ��ѯ������������Ŀʧ��				
#define NET_ERR_PERSON_INFO_QUERY				_ERR_CODE(147)			// ��ѯ��Ա��Ϣʧ��
#define NET_ERR_FACE_IMAGE_INFO_QUERY			_ERR_CODE(148)			// ��ѯ����ͼ����Ϣʧ��
#define NET_ERR_FACE_IMAGE_GET					_ERR_CODE(149)			// ��ȡ����ͼ��ʧ��
#define NET_ERR_PERSON_NAME_CHECK				_ERR_CODE(150)			// �������ʧ��
#define NET_ERR_FACE_REC_REC_FIND_HANDLE_CREATE	_ERR_CODE(151)			// �����ȶԼ�¼���Ҿ������ʧ��
#define NET_ERR_FACE_REC_REC_FIND_HANDLE_CLOSE	_ERR_CODE(152)			// �����ȶԼ�¼���Ҿ���ر�ʧ��
#define NET_ERR_FACE_REC_REC_FIND_HANDLE_DESTROY	_ERR_CODE(153)		// �����ȶԼ�¼���Ҿ������ʧ��
#define NET_ERR_FACE_REC_REC_PRE_FIND			_ERR_CODE(154)			// Ԥ��ѯ�����ȶԽ��ʧ��
#define NET_ERR_FACE_REC_REC_QUERY_NO_RESULT	_ERR_CODE(155)			// ��ѯ�����ȶԽ��ʧ��
#define NET_ERR_FACE_REC_REC_COUNT_QUERY		_ERR_CODE(156)			// ��ѯ��ȡ�����ȶԽ����Ŀʧ��

#define NET_ERR_TALK_REJECT						_ERR_CODE(160)          // �ܾ��Խ�
#define NET_ERR_TALK_ALREADY_OPEN               _ERR_CODE(161)          // �Խ��������ͻ��˴�
#define NET_ERR_TALK_RESOURCE_CONFLICIT			_ERR_CODE(162)          // ��Դ��ͻ
#define NET_ERR_TALK_ENCODE_NOT_SUPPORTED       _ERR_CODE(163)          // ��֧�ֵ����������ʽ
#define NET_ERR_TALK_NO_AUTHORIZED              _ERR_CODE(164)          // ��Ȩ��
#define NET_ERR_TALK_FAIL						_ERR_CODE(165)          // ����Խ�ʧ��

#define NET_ERR_LOGIN_PWD						_ERR_CODE(201)          // ���벻��ȷ�Ĵ���
#define NET_ERR_LOGIN_USER						_ERR_CODE(202)          // �ʻ������ڵĴ���
#define NET_ERR_LOGIN_TIMEOUT					_ERR_CODE(203)          // �ȴ���¼���س�ʱ�Ĵ���
#define NET_ERR_LOGIN_RELOGIN					_ERR_CODE(204)          // �ʺ��ѵ�¼�Ĵ���
#define NET_ERR_LOGIN_LOCKED					_ERR_CODE(205)          // �ʺ��ѱ������Ĵ���
#define NET_ERR_LOGIN_BLACKLIST					_ERR_CODE(206)          // �ʺ��ѱ���Ϊ�������Ĵ���
#define NET_ERR_LOGIN_BUSY						_ERR_CODE(207)          // ��Դ���㣬ϵͳæ�Ĵ���
#define NET_ERR_LOGIN_CONNECT					_ERR_CODE(208)          // ��¼�豸��ʱ�Ĵ���
#define NET_ERR_LOGIN_NETWORK					_ERR_CODE(209)          // ��������ʧ��
#define NET_ERR_LOGIN_SUB_CONNECT				_ERR_CODE(210)          // �����ӣ�����Ƶ�������ӣ�ʧ�ܵĴ���
#define NET_ERR_LOGIN_MAX_CONNECT				_ERR_CODE(211)          // ��������������Ĵ���
#define NET_ERR_LOGIN_NO_AUTHORIZED				_ERR_CODE(212)          // �ͻ���IP��ַû�е�¼Ȩ�޵Ĵ��� 
#define NET_ERR_LOGIN_USER_PWD					_ERR_CODE(213)			// ��¼�û������������
#define NET_ERR_LOGIN_PEER_BLOCKED				_ERR_CODE(214)			// �û���¼������

#define NET_ERR_RENDER_AUDIO_ON					_ERR_CODE(240)          // Render�����Ƶ����Ĵ���
#define NET_ERR_RENDER_AUDIO_OFF				_ERR_CODE(241)          // Render��ر���Ƶ����Ĵ���
#define NET_ERR_RENDER_SET_VOLUME				_ERR_CODE(242)          // Render�������������Ĵ���
#define NET_ERR_RENDER_ADJUST					_ERR_CODE(243)          // Render�����û����������Ĵ���
#define NET_ERR_RENDER_PAUSE					_ERR_CODE(245)          // Render����ͣ���ų���Ĵ���
#define NET_ERR_RENDER_SNAP						_ERR_CODE(246)          // Render��ץͼ����Ĵ���
#define NET_ERR_RENDER_STEP						_ERR_CODE(247)          // Render�ⲽ������Ĵ���
#define NET_ERR_RENDER_FRAMERATE				_ERR_CODE(248)          // Render������֡�ʳ���Ĵ���
#define NET_ERR_RENDER_DISPLAY_REGION			_ERR_CODE(249)          // Render��������ʾ�������Ĵ���
#define NET_ERR_RENDER_HPIC_ADJUST_ENABLE		_ERR_CODE(250)			// Render�����ͼ���������ʹ�ܴ���
#define NET_ERR_RENDER_PRIVATE_DATA				_ERR_CODE(251)			// Render��ʹ�ܻ����������ݴ���

#define NET_ERR_GROUP_EXIST                     _ERR_CODE(280)          // �����Ѵ��ڵĴ���
#define NET_ERR_GROUP_NOT_EXIST                 _ERR_CODE(281)          // ���������ڵĴ���
#define NET_ERR_GROUP_RIGHT_OVER				_ERR_CODE(282)          // ���Ȩ�޳���Ȩ���б�Χ�Ĵ���
#define NET_ERR_GROUP_USER_EXIST                _ERR_CODE(283)          // �������û�������ɾ���Ĵ���
#define NET_ERR_GROUP_RIGHT_NOT_RELEASE         _ERR_CODE(284)          // ���ĳ��Ȩ�ޱ��û�ռ�ã�����ɾ���Ĵ���
#define NET_ERR_GROUP_SAME_NAME					_ERR_CODE(285)          // ������ͬ���������ظ��Ĵ���

#define NET_ERR_USER_EXIST						_ERR_CODE(300)          // �û��Ѵ��ڵĴ���
#define NET_ERR_USER_NOEXIST                    _ERR_CODE(301)          // �û������ڵĴ���
#define NET_ERR_USER_RIGHT_EXCEED               _ERR_CODE(302)          // �û�Ȩ�޳�����Ȩ�޵Ĵ���
#define NET_ERR_USER_PWD                        _ERR_CODE(303)          // �����ʺţ��������޸�����Ĵ���
#define NET_ERR_USER_WRONG_PWD                  _ERR_CODE(304)          // ���벻��ȷ�Ĵ���
#define NET_ERR_USER_PWD_NOT_MATCH              _ERR_CODE(305)          // ���벻ƥ��Ĵ���
#define NET_ERR_USER_WORKING                    _ERR_CODE(306)          // �˺�����ʹ���еĴ���

#define NET_ERR_CFG_DATA_ILLEGAL                _ERR_CODE(360)          // �������ݲ��Ϸ��Ĵ���
#define NET_ERR_CFG_BUSY						_ERR_CODE(361)          // ��ʱ�޷����õĴ���

#define NET_ERR_GET_SYS_ATTRI_CFG               _ERR_CODE(370)          // ��ȡϵͳ��������ʧ�ܵĴ���
#define NET_ERR_GET_SERIAL_NUMBER               _ERR_CODE(371)          // ��ȡ���к�ʧ�ܵĴ���
#define NET_ERR_GET_GENERAL_CFG					_ERR_CODE(371)          // ��ȡ��������ʧ�ܵĴ���
#define NET_ERR_GET_DSP_CAP_CFG                 _ERR_CODE(373)          // ��ȡDSP��������ʧ�ܵĴ���
#define NET_ERR_GET_NET_CFG						_ERR_CODE(374)          // ��ȡ��������ʧ�ܵĴ���
#define NET_ERR_GET_CHANNEL_NAME_CFG            _ERR_CODE(375)          // ��ȡͨ������ʧ�ܵĴ���
#define NET_ERR_GET_VIDEO_CFG					_ERR_CODE(376)          // ��ȡ��Ƶ����ʧ�ܵĴ���
#define NET_ERR_GET_RECORD_CFG					_ERR_CODE(377)			// ��ȡ¼������ʧ�ܵĴ���
#define NET_ERR_GET_DEC_PROTOCOL_NAME_CFG       _ERR_CODE(378)          // ��ȡ������Э������ʧ�ܵĴ���
#define NET_ERR_GET_232_FUNC_NAME_CFG           _ERR_CODE(379)          // ��ȡ232���ڹ�������ʧ�ܵĴ���
#define NET_ERR_GET_485_DECODER_CFG             _ERR_CODE(380)          // ��ȡ����������ʧ�ܵĴ���
#define NET_ERR_GET_232_CFG						_ERR_CODE(381)          // ��ȡ232��������ʧ�ܵĴ���
#define NET_ERR_GET_ALARM_IN_CFG                _ERR_CODE(382)          // ��ȡ�ⲿ������������ʧ�ܵĴ���
#define NET_ERR_GET_ALARM_DETECT_CFG            _ERR_CODE(383)          // ��ȡ��̬��ⱨ��ʧ�ܵĴ���
#define NET_ERR_GET_SYSTIME_CFG					_ERR_CODE(384)          // ��ȡ�豸ʱ��ʧ�ܵĴ���
#define NET_ERR_GET_PREVIEW_CFG					_ERR_CODE(385)          // ��ȡԤ������ʧ�ܵĴ���
#define NET_ERR_GET_AUTO_MAINTAIN_CFG           _ERR_CODE(386)          // ��ȡ�Զ�ά������ʧ�ܵĴ���
#define NET_ERR_GET_VIDEO_MTRIX_CFG             _ERR_CODE(387)          // ��ȡ��Ƶ��������ʧ�ܵĴ���
#define NET_ERR_GET_COVER_CFG					_ERR_CODE(388)          // ��ȡ�����ڵ�����ʧ�ܵĴ���
#define NET_ERR_GET_WATERMARK_CFG				_ERR_CODE(389)          // ��ȡͼ��ˮӡ����ʧ�ܵĴ���
#define NET_ERR_GET_MULTICAST_CFG				_ERR_CODE(390)          // ��ȡ�鲥�˿ڰ�ͨ������ʧ�ܵĴ���
#define NET_ERR_GET_SESSION_CFG					_ERR_CODE(391)          // ��ȡ����Session��Ϣ�Ĵ���
#define NET_ERR_GET_ETHERNET_CFG				_ERR_CODE(392)          // ��ȡ��������ʧ�ܵĴ���
#define NET_ERR_GET_WLAN_CFG					_ERR_CODE(393)          // ��ȡ����������Ϣʧ�ܵĴ���
#define NET_ERR_GET_WLAN_DEVICE_CFG             _ERR_CODE(394)          // ��ȡ���������豸ʧ�ܵĴ���
#define NET_ERR_GET_REGISTER_CFG				_ERR_CODE(395)          // ��ȡ����ע�����ʧ�ܵĴ���
#define NET_ERR_GET_CAMERA_CFG					_ERR_CODE(396)          // ��ȡ����ͷ����ʧ�ܵĴ���
#define NET_ERR_GET_INFRARED_CFG				_ERR_CODE(397)          // ��ȡ���ⱨ������ʧ�ܵĴ���
#define NET_ERR_GET_AUDIO_ALARM_CFG             _ERR_CODE(398)          // ��ȡ��Ƶ��������ʧ�ܵĴ���
#define NET_ERR_GET_STORAGE_CFG					_ERR_CODE(399)          // ��ȡ�洢λ������ʧ�ܵĴ���
#define NET_ERR_GET_MAIL_CFG					_ERR_CODE(400)          // ��ȡ�ʼ�����ʧ�ܵĴ���
#define NET_ERR_GET_TIME_DST_CFG                _ERR_CODE(401)          // ��ȡ����ʱ����ʧ�ܵĴ���
#define NET_ERR_GET_VIDEO_OSD_CFG				_ERR_CODE(402)          // ��ȡ��ƵOSD��������ʧ�ܵĴ���
#define NET_ERR_GET_GPRS_CDMA_CFG               _ERR_CODE(403)          // ��ȡCDMA\GPRS��������ʧ�ܵĴ���
#define NET_ERR_GET_IP_FILTER_CFG               _ERR_CODE(404)          // ��ȡIP��������ʧ�ܵĴ���
#define NET_ERR_GET_TALK_ENCODE_CFG             _ERR_CODE(405)          // ��ȡ�����Խ���������ʧ�ܵĴ���
#define NET_ERR_GET_RECORD_LENGTH_CFG           _ERR_CODE(406)          // ��ȡ¼������������ʧ�ܵĴ���
#define NET_ERR_GET_VIDEO_OUT_CFG               _ERR_CODE(407)          // ��ѯ��Ƶ�����������ʧ�ܵĴ���
#define NET_ERR_GET_OSD_ENABLE_CFG              _ERR_CODE(408)          // ��ȡosd����ʹ������ʧ�ܵĴ���
#define NET_ERR_GET_TV_ADJUST_CFG               _ERR_CODE(409)          // ��ȡTV��������ʧ�ܵĴ���
#define NET_ERR_GET_SNIFFER_CFG					_ERR_CODE(410)          // ��ȡץ��������Ϣʧ�ܵĴ���
#define NET_ERR_GET_DOWNLOAD_RATE_CFG           _ERR_CODE(411)          // ��ѯ����������Ϣʧ�ܵĴ���
#define NET_ERR_GET_POINT_CFG					_ERR_CODE(412)          // ��ȡԤ�Ƶ���Ϣ����Ĵ���
#define NET_ERR_GET_VEHICLE_CFG					_ERR_CODE(413)          // ��ȡ��������ʧ�ܵĴ���
#define NET_ERR_GET_DECODER_TOUR_CFG			_ERR_CODE(414)          // ��ȡ������������Ѳ����ʧ��
#define NET_ERR_GET_SIP_CFG						_ERR_CODE(415)          // ��ȡSIP����ʧ��
#define NET_ERR_GET_SIP_CAPS					_ERR_CODE(416)          // ��ȡSIP����ʧ��
#define NET_ERR_GET_WIFI_AP_CFG					_ERR_CODE(417)          // ��ȡWIFI ap����ʧ��
#define NET_ERR_GET_DECODE_STRATEGY_CFG         _ERR_CODE(418)          // ��ȡ�����������ʧ��
#define NET_ERR_GET_MACHINE_CFG					_ERR_CODE(419)          // ��ȡ�����������ʧ��
#define NET_ERR_GET_MAC_FILTER_CFG              _ERR_CODE(420)          // ��ȡMAC��������ʧ��
#define NET_ERR_GET_IP_MAC_FILTER_CFG           _ERR_CODE(421)          // ��ȡIP/MAC��������ʧ��

#define NET_ERR_SET_GENERAL_CFG					_ERR_CODE(480)          // �޸ĳ�������ʧ�ܵĴ���
#define NET_ERR_SET_NET_CFG						_ERR_CODE(481)          // �޸���������ʧ�ܵĴ���
#define NET_ERR_SET_CHANNEL_NAME_CFG            _ERR_CODE(482)          // �޸�ͨ������ʧ�ܵĴ���
#define NET_ERR_SET_VIDEO_CFG					_ERR_CODE(483)          // �޸���Ƶ����ʧ�ܵĴ���
#define NET_ERR_SET_RECORD_CFG					_ERR_CODE(484)          // �޸�¼������ʧ�ܵĴ���
#define NET_ERR_SET_485_DECODER_CFG             _ERR_CODE(485)          // �޸Ľ���������ʧ�ܵĴ���
#define NET_ERR_SET_232_CFG						_ERR_CODE(486)          // �޸�232��������ʧ�ܵĴ���
#define NET_ERR_SET_ALARM_IN_CFG                _ERR_CODE(487)          // �޸��ⲿ���뱨������ʧ�ܵĴ���
#define NET_ERR_SET_ALARM_DETECT_CFG            _ERR_CODE(488)          // �޸Ķ�̬��ⱨ������ʧ�ܵĴ���
#define NET_ERR_SET_SYSTIME_CFG					_ERR_CODE(489)          // �޸��豸ʱ��ʧ�ܵĴ���
#define NET_ERR_SET_PREVIEW_CFG					_ERR_CODE(490)          // �޸�Ԥ������ʧ�ܵĴ���
#define NET_ERR_SET_AUTO_MAINTAIN_CFG           _ERR_CODE(491)          // �޸��Զ�ά������ʧ�ܵĴ���
#define NET_ERR_SET_VIDEO_MTRIX_CFG             _ERR_CODE(492)          // �޸���Ƶ��������ʧ�ܵĴ���
#define NET_ERR_SET_COVER_CFG					_ERR_CODE(493)          // �޸������ڵ�����ʧ�ܵĴ���
#define NET_ERR_SET_WATERMARK_CFG				_ERR_CODE(494)			// �޸�ͼ��ˮӡ����ʧ�ܵĴ���
#define NET_ERR_SET_WLAN_CFG					_ERR_CODE(495)          // �޸�����������Ϣʧ�ܵĴ���
#define NET_ERR_SET_WLAN_DEVICE_CFG             _ERR_CODE(496)          // ѡ�����������豸ʧ�ܵĴ���
#define NET_ERR_SET_REGISTER_CFG				_ERR_CODE(497)          // �޸�����ע���������ʧ�ܵĴ���
#define NET_ERR_SET_CAMERA_CFG					_ERR_CODE(498)          // �޸�����ͷ��������ʧ�ܵĴ���
#define NET_ERR_SET_INFRARED_CFG				_ERR_CODE(499)          // �޸ĺ��ⱨ������ʧ�ܵĴ���
#define NET_ERR_SET_AUDIO_ALARM_CFG             _ERR_CODE(500)          // �޸���Ƶ��������ʧ�ܵĴ���
#define NET_ERR_SET_STORAGE_CFG					_ERR_CODE(501)          // �޸Ĵ洢λ������ʧ�ܵĴ���
#define NET_ERR_SET_TIME_DST_CFG                _ERR_CODE(502)          // ��������ʱ����ʧ�ܵĴ���
#define NET_ERR_SET_VIDEO_OSD_CFG				_ERR_CODE(503)          // ������ƵOSD��������ʧ�ܵĴ���
#define NET_ERR_SET_GPRS_CDMA_CFG               _ERR_CODE(504)          // ����CDMA\GPRS��������ʧ�ܵĴ���
#define NET_ERR_SET_IP_FILTER_CFG               _ERR_CODE(505)          // ����IP��������ʧ�ܵĴ���
#define NET_ERR_SET_TALK_ENCODE_CFG             _ERR_CODE(506)          // ���������Խ���������ʧ�ܵĴ���
#define NET_ERR_SET_RECORD_LENGTH_CFG           _ERR_CODE(507)          // ����¼������������ʧ�ܵĴ���
#define NET_ERR_SET_VIDEO_OUT_CFG               _ERR_CODE(508)          // ������Ƶ�����������ʧ�ܵĴ���
#define NET_ERR_SET_OSD_ENABLE_CFG              _ERR_CODE(509)          // ����osd����ʹ������ʧ�ܵĴ���
#define NET_ERR_SET_ENCODER_INFO_CFG            _ERR_CODE(510)          // ��������ͨ��ǰ�˱����������ʧ�ܵĴ���
#define NET_ERR_SET_IP_MAC_FILTER_CFG           _ERR_CODE(511)          // ����IP/MAC��������ʧ��
#define NET_ERR_SET_TV_ADJUST_CFG               _ERR_CODE(512)          // ����TV��������ʧ�ܵĴ���
#define NET_ERR_SET_BURN_FILE_CFG               _ERR_CODE(513)          // �����¼�ļ��ϴ�ʧ�ܵĴ���
#define NET_ERR_SET_SNIFFER_CFG					_ERR_CODE(514)          // ����ץ��������Ϣʧ�ܵĴ���
#define NET_ERR_SET_DOWNLOAD_RATE_CFG           _ERR_CODE(515)          // ��������������Ϣʧ�ܵĴ���
#define NET_ERR_SET_POINT_CFG					_ERR_CODE(516)          // ����Ԥ�Ƶ���Ϣ����Ĵ���
#define NET_ERR_SET_VEHICLE_CFG					_ERR_CODE(517)          // ���ó�������ʧ�ܵĴ���
#define NET_ERR_SET_ATM_OVERLAY_CFG				_ERR_CODE(518)          // ����atm��������ʧ�ܵĴ���
#define NET_ERR_SET_DECODER_TOUR_CFG			_ERR_CODE(519)          // ���ý�����������Ѳ����ʧ��
#define NET_ERR_SET_SIP_CFG						_ERR_CODE(520)          // ����SIP����ʧ��
#define NET_ERR_SET_WIFI_AP_CFG					_ERR_CODE(521)          // ����WIFI ap����ʧ��
#define NET_ERR_SET_DECODE_STRATEGY_CFG         _ERR_CODE(522)          // ���ý����������ʧ��
#define NET_ERR_SET_MACHINE_CFG					_ERR_CODE(523)          // ���û����������ʧ��
#define NET_ERR_SET_MAC_FILTER_CFG              _ERR_CODE(524)          // ����MAC��������ʧ��

#endif // _AL_NET_DEF_COLLECTION_H