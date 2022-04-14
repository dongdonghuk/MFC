//#include<iostream>
#include<sdkddkver.h>
#include<afxwin.h> // iostream과 같은거라 보면 됨
//using namespace std;


//콘솔 응용프로그램
//int main(int argc, char** argv) { // MFC에서는 메인이 없음
//
//   return 0;
//}

// 윈도우 응용프로그램 -> C style
// BOOL WinMain(...){
// 
// return 0;
// }

//윈도우 어플리케이션
// 
//CWinApp : 응용프로그램을 담당하는 클래스  내가 만드는건 MFC의 확장이라서 오픈, 단 폐쇠성으로 인해 MFC에 추가 및 변경이 되는건 아님 단지 확장일 뿐
//WinMain()이 CWinApp안에 숨어있다.

//sub 시스템즈 윈도우 : WinMain()
class CMyApp : public CWinApp {
public:
    virtual BOOL InitInstance() override {
        // 진입점  : 시작 함수
        TRACE("hello world\n"); // 디버깅시 만 동작함

        //실행 : F5 // 디버깅하고 실행
        //실행 : ctrl + F5 // 디버깅 하지않고 실행

        TRACE("InitInstance() 호출됨\n");
        
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

        
        //AfxMessageBox(L"Hello world"); // 컴파일 설정마다 언어의 인코딩이 달라져 조심
        // 
        AfxMessageBox(_T("Hello world"));
        ::MessageBox(NULL, _T("내용"), _T("타이틀"), MB_OK);

        return TRUE;
    }

    virtual int ExitInstance() override {
        TRACE("ExitInstance() 호출됨\n");
        return 0;
    }
};

CMyApp theApp;