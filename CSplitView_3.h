#pragma once

#include "CSplitView.h"

// CSplitView_3 보기

class CSplitView_3 : public CSplitView
{
	DECLARE_DYNCREATE(CSplitView_3)

protected:
	CSplitView_3();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CSplitView_3();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void OnDraw(CDC* pDC);      // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual void OnInitialUpdate();     // 생성된 후 처음입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};


