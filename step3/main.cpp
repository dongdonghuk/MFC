#include <afxwin.h>
#include "resource.h"


/*
resource (재사용 가능 자원)
1. 윈도우 제목
2. 메뉴
3. 아이콘
	위 3가지를 사용하여 윈도우 생성 하는 방법
	LoadFrame() 사용해서 FrameWnd 생성
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