
// MFCSplitScrollView.cpp: CMFCSplitScrollView 클래스의 구현
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "MFCSplitScroll.h"
#endif

#include "MFCSplitScrollDoc.h"
#include "MFCSplitScrollView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCSplitScrollView

IMPLEMENT_DYNCREATE(CMFCSplitScrollView, CScrollView)

BEGIN_MESSAGE_MAP(CMFCSplitScrollView, CScrollView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CScrollView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CScrollView::OnFilePrintPreview)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

// CMFCSplitScrollView 생성/소멸

CMFCSplitScrollView::CMFCSplitScrollView() noexcept
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CMFCSplitScrollView::~CMFCSplitScrollView()
{
}

BOOL CMFCSplitScrollView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CScrollView::PreCreateWindow(cs);
}

// CMFCSplitScrollView 그리기

void CMFCSplitScrollView::OnDraw(CDC* pDC)
{
	CMFCSplitScrollDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

}

void CMFCSplitScrollView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}


// CMFCSplitScrollView 인쇄

BOOL CMFCSplitScrollView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CMFCSplitScrollView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CMFCSplitScrollView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CMFCSplitScrollView 진단

#ifdef _DEBUG
void CMFCSplitScrollView::AssertValid() const
{
	CScrollView::AssertValid();
}

void CMFCSplitScrollView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}

CMFCSplitScrollDoc* CMFCSplitScrollView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSplitScrollDoc)));
	return (CMFCSplitScrollDoc*)m_pDocument;
}
#endif //_DEBUG


// CMFCSplitScrollView 메시지 처리기


BOOL CMFCSplitScrollView::OnEraseBkgnd(CDC* pDC)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//return CScrollView::OnEraseBkgnd(pDC);
	return TRUE;
}
