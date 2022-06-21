﻿// CSplitView_1.cpp: 구현 파일
//

#include "pch.h"
#include "MFCSplitScroll.h"
#include "CSplitView_1.h"


// CSplitView_1

IMPLEMENT_DYNCREATE(CSplitView_1, CScrollView)

CSplitView_1::CSplitView_1()
{

}

CSplitView_1::~CSplitView_1()
{
}


BEGIN_MESSAGE_MAP(CSplitView_1, CScrollView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CSplitView_1 그리기

void CSplitView_1::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: 이 뷰의 전체 크기를 계산합니다.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CSplitView_1::OnDraw(CDC* pDC)
{
	CMFCSplitScrollDoc* pDoc = GetDocument();

	// TODO: 여기에 그리기 코드를 추가합니다.
	CSplitView::OnDraw(pDC);

	Graphics g(pDC->m_hDC);

	if (!(pDoc->m_matImg_1.empty())) {
		cvtColor(pDoc->m_matImg_1, pDoc->m_matImg_1, COLOR_BGR2BGRA);

		Bitmap bitmap((INT)pDoc->m_matImg_1.size().width, (INT)pDoc->m_matImg_1.size().height, (INT)pDoc->m_matImg_1.step,
			PixelFormat32bppARGB, pDoc->m_matImg_1.data);

		g.DrawImage(&bitmap, 0, 0, bitmap.GetWidth(), bitmap.GetHeight());

	}

}


// CSplitView_1 진단

#ifdef _DEBUG
void CSplitView_1::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CSplitView_1::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSplitView_1 메시지 처리기


void CSplitView_1::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CSplitView::OnLButtonDown(nFlags, point);
}


void CSplitView_1::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	CSplitView::OnUpdate(pSender, lHint, pHint);

}


BOOL CSplitView_1::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CSplitView::PreCreateWindow(cs);
}