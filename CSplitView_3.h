#pragma once

#include "CSplitView.h"

// CSplitView_3 ����

class CSplitView_3 : public CSplitView
{
	DECLARE_DYNCREATE(CSplitView_3)

protected:
	CSplitView_3();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CSplitView_3();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void OnDraw(CDC* pDC);      // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual void OnInitialUpdate();     // ������ �� ó���Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};


