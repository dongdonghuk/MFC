//#include<iostream>
#include<sdkddkver.h>
#include<afxwin.h> // iostream�� �����Ŷ� ���� ��
//using namespace std;


//�ܼ� �������α׷�
//int main(int argc, char** argv) { // MFC������ ������ ����
//
//   return 0;
//}

// ������ �������α׷� -> C style
// BOOL WinMain(...){
// 
// return 0;
// }

//������ ���ø����̼�
// 
//CWinApp : �������α׷��� ����ϴ� Ŭ����  ���� ����°� MFC�� Ȯ���̶� ����, �� ��輺���� ���� MFC�� �߰� �� ������ �Ǵ°� �ƴ� ���� Ȯ���� ��
//WinMain()�� CWinApp�ȿ� �����ִ�.

//sub �ý����� ������ : WinMain()
class CMyApp : public CWinApp {
public:
    virtual BOOL InitInstance() override {
        // ������  : ���� �Լ�
        TRACE("hello world\n"); // ������ �� ������

        //���� : F5 // ������ϰ� ����
        //���� : ctrl + F5 // ����� �����ʰ� ����

        TRACE("InitInstance() ȣ���\n");
        
    #ifdef _UNICODE
        #define TCHAR wchar_t
        #define _T(str) L(str)
    #else
        #define TCHAR char
        #define _T(str) str
    #endif
        
        /*
              char p1[] = "Hello World";
              wchar_t p2[] = "Hello World";
        */

        
        //AfxMessageBox(L"Hello world"); // ������ �������� ����� ���ڵ��� �޶��� ����
        // 
        AfxMessageBox(_T("Hello world"));
        ::MessageBox(NULL, _T("����"), _T("Ÿ��Ʋ"), MB_OK);

        return TRUE;
    }

    virtual int ExitInstance() override {
        TRACE("ExitInstance() ȣ���\n");
        return 0;
    }
};

CMyApp theApp;