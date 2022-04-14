
// step08View.cpp: Cstep08View 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "step08.h"
#endif

#include "step08Doc.h"
#include "step08View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cstep08View

IMPLEMENT_DYNCREATE(Cstep08View, CView)

BEGIN_MESSAGE_MAP(Cstep08View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_KEYDOWN()
	ON_WM_CREATE()
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// Cstep08View 생성/소멸

Cstep08View::Cstep08View() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cstep08View::~Cstep08View()
{
}

BOOL Cstep08View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cstep08View 그리기

void Cstep08View::OnDraw(CDC* /*pDC*/)
{
	Cstep08Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// Cstep08View 인쇄

BOOL Cstep08View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void Cstep08View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void Cstep08View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// Cstep08View 진단

#ifdef _DEBUG
void Cstep08View::AssertValid() const
{
	CView::AssertValid();
}

void Cstep08View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cstep08Doc* Cstep08View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cstep08Doc)));
	return (Cstep08Doc*)m_pDocument;
}
#endif //_DEBUG


// Cstep08View 메시지 처리기


void Cstep08View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	//m_wndChild.MoveWindow(CRect(200,200,300,240));

	CRect rect;
	CPoint pt;

	m_wndChild.SetWindowText(_T("어질어질 MFC"));

	m_wndChild.GetWindowRect(rect);
	pt = rect.TopLeft();

	AfxGetMainWnd()->SetWindowText(_T("어질어질 MFC"));

	ScreenToClient(&pt);

	switch(nChar) {
	case VK_LEFT:
		pt.x -= 10;
		break;
	case VK_RIGHT:
		pt.x += 10;
		break;
	case VK_UP:
		pt.y -= 10;
		break;
	case VK_DOWN:
		pt.y += 10;
		break;
	}
	

	m_wndChild.SetWindowPos(&CWnd::wndTop, pt.x, pt.y, 0, 0, SWP_SHOWWINDOW | SWP_NOZORDER | SWP_NOSIZE);

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


int Cstep08View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	m_wndChild.Create(_T("BUTTON"), _T("안녕~~"), WS_CHILD | WS_VISIBLE | WS_BORDER,
						CRect(100,100,220,140), this, 1);

	return 0;
}


void Cstep08View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	TRACE("마우스 좌표 : %d, %d\n", point.x, point.y);

	CClientDC dc(this);

	dc.SetPixel(point, RGB(0,0,0));

	CView::OnLButtonDown(nFlags, point);
}
