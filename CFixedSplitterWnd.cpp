#include "pch.h"
#include "CFixedSplitterWnd.h"
#include "MFCSplitScroll.h"


// CFixedSplitterWnd �޽��� ó����


BEGIN_MESSAGE_MAP(CFixedSplitterWnd, CSplitterWnd)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
//	ON_WM_MBUTTONDBLCLK()
ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()


void CFixedSplitterWnd::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CWnd::OnMouseMove(nFlags, point);
}


void CFixedSplitterWnd::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CWnd::OnLButtonDown(nFlags, point);
}


void CFixedSplitterWnd::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CWnd::OnLButtonUp(nFlags, point);
}


void CFixedSplitterWnd::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CWnd::OnLButtonDblClk(nFlags, point);
}
