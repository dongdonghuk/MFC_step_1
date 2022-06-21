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

	//if (pDoc->m_img) {
	//	g.DrawImage(pDoc->m_img, 300, 300, pDoc->m_img->GetWidth() / 5, pDoc->m_img->GetHeight() / 5);
	//}

	if (!(pDoc->m_matImg_3.empty())) {
		cvtColor(pDoc->m_matImg_3, pDoc->m_matImg_3, COLOR_BGR2BGRA);

		Bitmap bitmap((INT)pDoc->m_matImg_3.size().width, (INT)pDoc->m_matImg_3.size().height, (INT)pDoc->m_matImg_3.step,
			PixelFormat32bppARGB, pDoc->m_matImg_3.data);

		g.DrawImage(&bitmap, 0, 0, bitmap.GetWidth(), bitmap.GetHeight());

	}

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
