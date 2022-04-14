#include <afxwin.h>
#include "resource.h"


/*
resource (���� ���� �ڿ�)
1. ������ ����
2. �޴�
3. ������
	�� 3������ ����Ͽ� ������ ���� �ϴ� ���
	LoadFrame() ����ؼ� FrameWnd ����
*/


class CMainFrame : public CFrameWnd {

};

class CMyApp : public CWinApp {
public:
	virtual BOOL InitInstance() override {
		CMainFrame* pMainFrame = new CMainFrame();
		//pMainFrame->Create(NULL, NULL);
		pMainFrame->LoadFrame(IDR_MAIN_FRAME);
		pMainFrame->ShowWindow(SW_SHOW);
		m_pMainWnd = pMainFrame;

		return TRUE;
	}

	virtual int ExitInstance() override {
		return 0;
	}
};

CMyApp theApp;