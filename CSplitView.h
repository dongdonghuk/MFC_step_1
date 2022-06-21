#pragma once
#include "MFCSplitScrollDoc.h"

// CSplitView 보기

class CSplitView : public CScrollView
{
	DECLARE_DYNCREATE(CSplitView)

protected:
	CSplitView();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CSplitView();

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
	CMFCSplitScrollDoc* GetDocument() const;


	DECLARE_MESSAGE_MAP()
	virtual void OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/);
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
};


#ifndef _DEBUG  //
inline CMFCSplitScrollDoc* CSplitView::GetDocument() const
{
	return reinterpret_cast<CMFCSplitScrollDoc*>(m_pDocument);
}
#endif

