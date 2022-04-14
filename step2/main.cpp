#include <afxwin.h>

//프레임 윈도우 생성 방법
//CFramewnd : 프레임 윈도우
//윈도우 제목
//메뉴
//안쪽에 윈도우에 자식 윈도우를 생성하고 관리 할 수 있는 책임이 있다
//도구와 상태바를 생성해서 관리 할 수 있음
// 생성방법 3가지
/*
1. CWnd::Create()
2. LoadFrame()
3. RuntimeClass 를 사용하는 방법
*/



class CMainFrame : public CFrameWnd {

};

class A {};

class CMyApp : public CWinApp {
public:
	virtual BOOL InitInstance() override {
		CMainFrame* pMainFrame = new CMainFrame();
		pMainFrame->Create(NULL, NULL);
		//화면에 윈도우 표시
		pMainFrame->ShowWindow(SW_SHOW);

		//메인 윈도우를 설정한다
		m_pMainWnd = pMainFrame;

		return TRUE;
	}
	virtual int ExitInstance() override {
		return 0;
	}
};

CMyApp theApp;