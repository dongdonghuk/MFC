#include <afxwin.h>

//������ ������ ���� ���
//CFramewnd : ������ ������
//������ ����
//�޴�
//���ʿ� �����쿡 �ڽ� �����츦 �����ϰ� ���� �� �� �ִ� å���� �ִ�
//������ ���¹ٸ� �����ؼ� ���� �� �� ����
// ������� 3����
/*
1. CWnd::Create()
2. LoadFrame()
3. RuntimeClass �� ����ϴ� ���
*/



class CMainFrame : public CFrameWnd {

};

class A {};

class CMyApp : public CWinApp {
public:
	virtual BOOL InitInstance() override {
		CMainFrame* pMainFrame = new CMainFrame();
		pMainFrame->Create(NULL, NULL);
		//ȭ�鿡 ������ ǥ��
		pMainFrame->ShowWindow(SW_SHOW);

		//���� �����츦 �����Ѵ�
		m_pMainWnd = pMainFrame;

		return TRUE;
	}
	virtual int ExitInstance() override {
		return 0;
	}
};

CMyApp theApp;