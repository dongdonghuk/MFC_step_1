// CSplitView.cpp: 구현 파일
//

#include "pch.h"
#include "MFCSplitScroll.h"
#include "CSplitView.h"
#include "MFCSplitScrollDoc.h"



// CSplitView

IMPLEMENT_DYNCREATE(CSplitView, CScrollView)

CSplitView::CSplitView()
{

}

CSplitView::~CSplitView()
{
}


BEGIN_MESSAGE_MAP(CSplitView, CScrollView)
//	ON_WM_MBUTTONDOWN()
ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CSplitView 그리기

void CSplitView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CSplitView::OnDraw(CDC* pDC)
{
	CMFCSplitScrollDoc* pDoc = GetDocument();

	
	Graphics g(pDC->m_hDC);


	if (pDoc->m_pSelectedView == this) {

		CRect rect;
		GetClientRect(rect);
		Pen pen(Color(255, 0, 0), 5);

		g.DrawRectangle(&pen, 0, 0, rect.Width(), rect.Height());

	}

}


// CSplitView 진단

#ifdef _DEBUG
void CSplitView::AssertValid() const
{
	CScrollView::AssertValid();
}

CMFCSplitScrollDoc* CSplitView::GetDocument() const 
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCSplitScrollDoc)));
	return (CMFCSplitScrollDoc*)m_pDocument;
}


#ifndef _WIN32_WCE
void CSplitView::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSplitView 메시지 처리기


void CSplitView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CMFCSplitScrollDoc* pDoc = GetDocument();

	switch (lHint) {
	case HINT_SELECTED_VIEW:
		pDoc->m_pSelectedView = (CScrollView*)pHint;
		break;
	}
	Invalidate();
}


void CSplitView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMFCSplitScrollDoc* pDoc = GetDocument();
	pDoc->UpdateAllViews(NULL, HINT_SELECTED_VIEW, this);

	CScrollView::OnLButtonDown(nFlags, point);
}


BOOL CSplitView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	cs.lpszClass = AfxRegisterWndClass(CS_VREDRAW | CS_HREDRAW,
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)GetStockObject(BLACK_BRUSH),
		LoadIcon(NULL, IDI_APPLICATION));

	return CScrollView::PreCreateWindow(cs);
}
