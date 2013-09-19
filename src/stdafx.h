// stdafx.h : �W���̃V�X�e�� �C���N���[�h �t�@�C���̃C���N���[�h �t�@�C���A�܂���
// �Q�Ɖ񐔂������A�����܂�ύX����Ȃ��A�v���W�F�N�g��p�̃C���N���[�h �t�@�C��
// ���L�q���܂��B

#pragma once

#ifndef WINVER
#define WINVER 0x0600		// Windows Vista
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600	// Windows Vista
#endif

#ifndef _WIN32_IE
#define _WIN32_IE 0x0600	// Internet Explorer 6.0
#endif

// Winsock2 �ƃw�b�_�������Ȃ��悤�ɂ���
#define _WINSOCKAPI_

#define _WIN32_DCOM	// for CoInitializeEx()

#include <stdio.h>
#include <process.h>
#include <windows.h>
#include <windowsx.h>
#include <tchar.h>
#include <commctrl.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <streams.h>	// DirectShow BaseClasses

#ifdef _DEBUG
#define _CRTDBG_MAP_ALLOC
#endif
#include <crtdbg.h>
#ifdef _DEBUG
#undef strdup
#define strdup strdup
#define DEBUG_NEW new(_NORMAL_BLOCK,__FILE__,__LINE__)
#endif // _DEBUG

#undef _WINSOCKAPI_

#include "Common.h"

#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_IA64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='ia64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif


// �x���̖����ݒ�
#pragma warning(disable: 4355) // warning C4355: "'this' : �x�[�X �����o���������X�g�Ŏg�p����܂����B"
#pragma warning(disable: 4995) // warning C4995: ���O��������ꂽ #pragma �Ƃ��ċL�q����Ă��܂��B
#pragma warning(disable: 4996) // warning C4996: "This function or variable may be unsafe."


// ���C�u�����̃����N
#pragma comment(lib, "Kernel32.lib")
#pragma comment(lib, "User32.lib")
#pragma comment(lib, "Gdi32.lib")
#pragma comment(lib, "AdvApi32.lib")
#pragma comment(lib, "Shell32.lib")
#pragma comment(lib, "ComCtl32.lib")
#pragma comment(lib, "ComDlg32.lib")
#pragma comment(lib, "Strmiids.lib")
#pragma comment(lib, "Ole32.lib")
#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "ShLwApi.lib")

#ifdef _DEBUG
#pragma comment(lib, "StrmBasd.lib")
#else
#pragma comment(lib, "StrmBase.lib")
#endif

// �g���[�X�o��
#ifdef _DEBUG
	#undef TRACE
	#define TRACE ::DebugTrace
	void DebugTrace(LPCTSTR szFormat, ...);
#else
	#define TRACE __noop
#endif

#ifndef _DEBUG
	#define _SECURE_SCL 0
#endif

// �R���p�C���ʐݒ�
#if _MSC_VER < 1400
	#define __restrict
#endif
#if _MSC_VER >= 1600	// VC2010
	#undef NULL
	#define NULL nullptr
	#define MOVE_SEMANTICS_SUPPORTED
#else
	#define nullptr NULL
	#ifndef _WIN64
	#define WINDOWS2000_SUPPORT	// Windows 2000 �Ή�
	#endif
#endif


// BonTsEngine �̐ݒ�
#ifdef TVH264
	#ifndef TVH264_FOR_HD
	#define BONTSENGINE_1SEG_SUPPORT	// �����Z�O�Ή�
	#define BONTSENGINE_RADIO_SUPPORT	// ���������Ή�
	#endif
	#define BONTSENGINE_H264_SUPPORT	// H.264 �Ή�
#else	// TVH264
	#define BONTSENGINE_MPEG2_SUPPORT	// MPEG-2 �Ή�
	#define BONTSENGINE_RADIO_SUPPORT	// ���������Ή�
#endif