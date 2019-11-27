#include "Stdafx.h"

// ����
void HelloWorld();


// ע�����������
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
//	@brief   : ARX��ڵ㺯��
//	@author  : MFGYF - XM
//	@input   ��AcRx::AppMsgCode msg		�����ARX������Ӧ�ó��򷢵���Ϣ
//			   void* pkt				�洢���ݰ���ֵ		   
//	@output  ��AppRetCode				����AutoCAD��״̬��
//	@date    : none
//
//			   extern "C"				֪ͨAutoCAD��acrxEntryPoint��һ���ⲿ����
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