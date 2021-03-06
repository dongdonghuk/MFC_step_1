// CSplitView_2.cpp: 구현 파일
//

#include "pch.h"
#include "MFCSplitScroll.h"
#include "CSplitView_2.h"


// CSplitView_2

IMPLEMENT_DYNCREATE(CSplitView_2, CScrollView)

CSplitView_2::CSplitView_2()
{

}

CSplitView_2::~CSplitView_2()
{
}


BEGIN_MESSAGE_MAP(CSplitView_2, CScrollView)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()


// CSplitView_2 그리기

void CSplitView_2::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CSplitView_2::OnDraw(CDC* pDC)
{
	CMFCSplitScrollDoc* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.
	Graphics g(pDC->m_hDC);

	pDoc->m_vCvImg[2].DrawImage(g, this);

	CSplitView::OnDraw(pDC);

}


// CSplitView_2 진단

#ifdef _DEBUG
void CSplitView_2::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CSplitView_2::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSplitView_2 메시지 처리기


void CSplitView_2::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMFCSplitScrollDoc* pDoc = GetDocument();

	CSplitView::OnLButtonDown(nFlags, point);
	pDoc->m_nSelectedView = 2;
}


void CSplitView_2::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CSplitView::OnUpdate(pSender, lHint, pHint);

}


BOOL CSplitView_2::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CSplitView::PreCreateWindow(cs);
}


BOOL CSplitView_2::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	return CSplitView::OnMouseWheel(nFlags, zDelta, pt);
}
