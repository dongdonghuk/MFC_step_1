// CSplitView_2.cpp: ���� ����
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
END_MESSAGE_MAP()


// CSplitView_2 �׸���

void CSplitView_2::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	CSize sizeTotal;
	// TODO: �� ���� ��ü ũ�⸦ ����մϴ�.
	sizeTotal.cx = sizeTotal.cy = 100;
	SetScrollSizes(MM_TEXT, sizeTotal);
}

void CSplitView_2::OnDraw(CDC* pDC)
{
	CMFCSplitScrollDoc* pDoc = GetDocument();
	// TODO: ���⿡ �׸��� �ڵ带 �߰��մϴ�.
	Graphics g(pDC->m_hDC);

	//if (pDoc->m_img) {
	//	g.DrawImage(pDoc->m_img, 300, 300, pDoc->m_img->GetWidth() / 5, pDoc->m_img->GetHeight() / 5);
	//}

	if (!(pDoc->m_matImg_2.empty())) {
		cvtColor(pDoc->m_matImg_2, pDoc->m_matImg_2, COLOR_BGR2BGRA);

		Bitmap bitmap((INT)pDoc->m_matImg_2.size().width, (INT)pDoc->m_matImg_2.size().height, (INT)pDoc->m_matImg_2.step,
			PixelFormat32bppARGB, pDoc->m_matImg_2.data);

		g.DrawImage(&bitmap, 0, 0, bitmap.GetWidth(), bitmap.GetHeight());

	}

	CSplitView::OnDraw(pDC);

}


// CSplitView_2 ����

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


// CSplitView_2 �޽��� ó����


void CSplitView_2::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CMFCSplitScrollDoc* pDoc = GetDocument();

	CSplitView::OnLButtonDown(nFlags, point);
	pDoc->m_nSelectedView = 2;
}


void CSplitView_2::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	CSplitView::OnUpdate(pSender, lHint, pHint);

}


BOOL CSplitView_2::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.

	return CSplitView::PreCreateWindow(cs);
}
