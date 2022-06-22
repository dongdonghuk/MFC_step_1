// CSplitView_3.cpp: 구현 파일
//

#include "pch.h"
#include "MFCSplitScroll.h"
#include "CSplitView_3.h"


// CSplitView_3

IMPLEMENT_DYNCREATE(CSplitView_3, CScrollView)

CSplitView_3::CSplitView_3()
{

}

CSplitView_3::~CSplitView_3()
{
}


BEGIN_MESSAGE_MAP(CSplitView_3, CScrollView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CSplitView_3 그리기

void CSplitView_3::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CSplitView_3::OnDraw(CDC* pDC)
{
	CMFCSplitScrollDoc* pDoc = GetDocument();
	// TODO: 여기에 그리기 코드를 추가합니다.

	Graphics g(pDC->m_hDC);

	if (!(pDoc->m_vMatImg[3].empty())) {
		cvtColor(pDoc->m_vMatImg[3], pDoc->m_vMatImg[3], COLOR_BGR2BGRA);

		Bitmap bitmap((INT)pDoc->m_vMatImg[3].size().width, (INT)pDoc->m_vMatImg[3].size().height, (INT)pDoc->m_vMatImg[3].step,
			PixelFormat32bppARGB, pDoc->m_vMatImg[3].data);

		g.DrawImage(&bitmap, 0, 0, bitmap.GetWidth(), bitmap.GetHeight());

	}

	CSplitView::OnDraw(pDC);

}


// CSplitView_3 진단

#ifdef _DEBUG
void CSplitView_3::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CSplitView_3::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSplitView_3 메시지 처리기


void CSplitView_3::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	CMFCSplitScrollDoc* pDoc = GetDocument();

	CSplitView::OnLButtonDown(nFlags, point);
	pDoc->m_nSelectedView = 3;
}


void CSplitView_3::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CSplitView::OnUpdate(pSender, lHint, pHint);

}


BOOL CSplitView_3::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CSplitView::PreCreateWindow(cs);
}
