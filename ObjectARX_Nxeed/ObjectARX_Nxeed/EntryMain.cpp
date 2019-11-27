#include "Stdafx.h"

// 命令
void HelloWorld();


// 注册与回收命令
void InitApp()
{
	acedRegCmds->addCommand(_T("ACRX_ARX2_COMMADN"), _T("Hello"), _T("Hello"), ACRX_CMD_MODAL, HelloWorld);
	// AdeskMyClass:rint();
	// acrxBuildClassHierarchy();
}

void UnLoadApp()
{
	acedRegCmds->removeGroup(_T("ACRX_ARX2_COMMADN"));
	//deleteAcRxClass(AdeskMyClass);
}

//**************************************************
//	@brief   : ARX入口点函数
//	@author  : MFGYF - XM
//	@input   ：AcRx::AppMsgCode msg		代表从ARX核心向应用程序发的消息
//			   void* pkt				存储数据包的值		   
//	@output  ：AppRetCode				返回AutoCAD的状态码
//	@date    : none
//
//			   extern "C"				通知AutoCAD，acrxEntryPoint是一个外部函数
//**************************************************
extern "C" AcRx::AppRetCode
acrxEntryPoint(AcRx::AppMsgCode msg, void* pkt)
{
	switch (msg)
	{
	case AcRx::kInitAppMsg:
		acrxDynamicLinker->unlockApplication(pkt);
		acrxRegisterAppMDIAware(pkt);
		InitApp();
		break;
	case AcRx::kUnloadAppMsg:
		UnLoadApp();
		break;
	default:
		break;
	}

	return AcRx::kRetOK;
}

void HelloWorld()
{
	acedPrompt(_T("Hello-World!"));
}