// CSplitView_4.cpp: ���� ����
//

#include "pch.h"
#include "MFCSplitScroll.h"
#include "CSplitView_4.h"


// CSplitView_4

IMPLEMENT_DYNCREATE(CSplitView_4, CScrollView)

CSplitView_4::CSplitView_4()
{

}

CSplitView_4::~CSplitView_4()
{
}


BEGIN_MESSAGE_MAP(CSplitView_4, CScrollView)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


// CSplitView_4 �׸���

void CSplitView_4::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CSplitView_4::OnDraw(CDC* pDC)
{
	CMFCSplitScrollDoc* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.


	Graphics g(pDC->m_hDC);

	pDoc->m_vCvImg[4].DrawImage(g, this);

	CSplitView::OnDraw(pDC);

}


// CSplitView_4 ����

#ifdef _DEBUG
void CSplitView_4::AssertValid() const
{
	CScrollView::AssertValid();
}

#ifndef _WIN32_WCE
void CSplitView_4::Dump(CDumpContext& dc) const
{
	CScrollView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSplitView_4 �޽��� ó����


void CSplitView_4::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMFCSplitScrollDoc* pDoc = GetDocument();

	CSplitView::OnLButtonDown(nFlags, point);
	pDoc->m_nSelectedView = 4;
}


void CSplitView_4::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CSplitView::OnUpdate(pSender, lHint, pHint);

}


BOOL CSplitView_4::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return CSplitView::PreCreateWindow(cs);
}
