// CSplitView_3.cpp: ���� ����
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
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()


// CSplitView_3 �׸���

void CSplitView_3::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CSplitView_3::OnDraw(CDC* pDC)
{
	CMFCSplitScrollDoc* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.

	Graphics g(pDC->m_hDC);

	pDoc->m_vCvImg[3].DrawImage(g, this);

	CSplitView::OnDraw(pDC);

}


// CSplitView_3 ����

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


// CSplitView_3 �޽��� ó����


void CSplitView_3::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMFCSplitScrollDoc* pDoc = GetDocument();

	CSplitView::OnLButtonDown(nFlags, point);
	pDoc->m_nSelectedView = 3;
}


void CSplitView_3::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CSplitView::OnUpdate(pSender, lHint, pHint);

}


BOOL CSplitView_3::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return CSplitView::PreCreateWindow(cs);
}


BOOL CSplitView_3::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	return CSplitView::OnMouseWheel(nFlags, zDelta, pt);
}
