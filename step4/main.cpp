#include <afxwin.h>
#include "resource.h"
//RTTI


class A : public CObject {
	//DECLARE_DYNAMIC(A);
	//DECLARE_DYNCREATE(A);
	DECLARE_SERIAL(A);

private:
	int a;
	int b;
public:
	A() : a(100), b(100){
		TRACE("A() 생성자 호출 \n");
	}
	~A() {
		TRACE("A() 소멸자 호출 \n");
	}

	int add(const int a, const int b) {
		TRACE("A() add 함수 호출 = %d\n",this->a + this->b + a+b);
		return a + b;
	}



};

class B : public CObject {
	//DECLARE_DYNAMIC(B);
	//DECLARE_DYNCREATE(B);
	DECLARE_SERIAL(B);


public:
	B() {
		TRACE("B() 생성자 호출 \n");
	}
	~B() {
		TRACE("B() 소멸자 호출 \n");
	}

	int sub(const int a, const int b) {
		TRACE("B() sub 함수 \n");
		return a - b;
	}

};

//IMPLEMENT_DYNAMIC(A,CObject);		부모자식관계의 연결고리 만들기
//IMPLEMENT_DYNAMIC(B,CObject);
//IMPLEMENT_DYNCREATE(A, CObject);	위를 포함하며, 객체생성의 일반화 제공
//IMPLEMENT_DYNCREATE(B, CObject);
IMPLEMENT_SERIAL(A, CObject, 1);	//위를 사용하며, 읽기쓰기 기능제공
IMPLEMENT_SERIAL(B, CObject, 1);



class CMainFrame : public CFrameWnd {

};

class CMyApp : public CWinApp {
public:
	virtual BOOL InitInstance() override {
		CMainFrame* pMainFrame = new CMainFrame();
		pMainFrame->LoadFrame(IDR_MAIN_FRAME);
		pMainFrame->ShowWindow(SW_SHOW);
		m_pMainWnd = pMainFrame;

		CRuntimeClass* pClass = RUNTIME_CLASS(A);

		CObject* pObj = nullptr;

		//pObj = new A;
		pObj = pClass->CreateObject();



		if (pObj->IsKindOf(RUNTIME_CLASS(A))) {
			((A*)pObj)->add(10, 20);
		}
		else if (pObj->IsKindOf(RUNTIME_CLASS(B))) {
			((B*)pObj)->sub(10, 20);
		}
		else {
			TRACE("@@@@@@@@@@\n");
		}

		delete pObj;

		pObj = new B;
		((B*)pObj)->sub(10, 20);

		delete pObj;

		return TRUE;
	}

	virtual int ExitInstance() override {
		return 0;
	}
};

CMyApp theApp;