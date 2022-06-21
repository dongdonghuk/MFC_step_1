﻿
// MFCSplitScrollView.h: CMFCSplitScrollView 클래스의 인터페이스
//

#pragma once


class CMFCSplitScrollView : public CScrollView
{
protected: // serialization에서만 만들어집니다.
	CMFCSplitScrollView() noexcept;
	DECLARE_DYNCREATE(CMFCSplitScrollView)

// 특성입니다.
public:
	CMFCSplitScrollDoc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // 생성 후 처음 호출되었습니다.
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CMFCSplitScrollView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // MFCSplitScrollView.cpp의 디버그 버전
inline CMFCSplitScrollDoc* CMFCSplitScrollView::GetDocument() const
   { return reinterpret_cast<CMFCSplitScrollDoc*>(m_pDocument); }
#endif

