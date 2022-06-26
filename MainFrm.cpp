
// MainFrm.cpp: CMainFrame 클래스의 구현
//

#include "pch.h"
#include "framework.h"
#include "MFCSplitScroll.h"

#include "MainFrm.h"
#include "CSplitView_1.h"
#include "CSplitView_2.h"
#include "CSplitView_3.h"
#include "CSplitView_4.h"
#include "CFixedSplitterWnd.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(IDM_SPLIT_1, &CMainFrame::OnSplit1)
	ON_COMMAND(IDM_SPLIT_2, &CMainFrame::OnSplit2)
	ON_COMMAND(IDM_SPLIT_4, &CMainFrame::OnSplit4)
	ON_WM_SIZE()
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 생성/소멸

CMainFrame::CMainFrame() noexcept
{
	// TODO: 여기에 멤버 초기화 코드를 추가합니다.
	m_bViewsExist = FALSE;
	m_nSplitType = 1;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;      // 만들지 못했습니다.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	// TODO: 도구 모음을 도킹할 수 없게 하려면 이 세 줄을 삭제하십시오.
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);


	return 0;
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT /*lpcs*/,
	CCreateContext* pContext)
{
	m_wndSplitter.CreateStatic(this, 2, 2);

	m_wndSplitter.CreateView(0, 0, RUNTIME_CLASS(CSplitView_1), CSize(0, 0), pContext);
	m_wndSplitter.CreateView(0, 1, RUNTIME_CLASS(CSplitView_2), CSize(0, 0), pContext);
	m_wndSplitter.CreateView(1, 0, RUNTIME_CLASS(CSplitView_3), CSize(0, 0), pContext);
	m_wndSplitter.CreateView(1, 1, RUNTIME_CLASS(CSplitView_4), CSize(0, 0), pContext);

	CRect rect;
	GetClientRect(&rect);

	m_wndSplitter.SetColumnInfo(0, rect.right, 50);
	m_wndSplitter.SetColumnInfo(1, rect.right, 50);

	m_wndSplitter.SetRowInfo(0, rect.bottom, 50);
	m_wndSplitter.SetRowInfo(1, rect.bottom, 50);

	m_wndSplitter.RecalcLayout();

	m_bViewsExist = TRUE;


	return TRUE;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return TRUE;
}

// CMainFrame 진단

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame 메시지 처리기



void CMainFrame::OnSplit1()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CRect rect;
	GetClientRect(&rect);


	m_wndSplitter.SetColumnInfo(0, rect.right, 50);
	m_wndSplitter.SetColumnInfo(1, rect.right, 50);

	m_wndSplitter.SetRowInfo(0, rect.bottom, 50);
	m_wndSplitter.SetRowInfo(1, rect.bottom, 50);

	m_wndSplitter.RecalcLayout();

	m_nSplitType = 1;
}


void CMainFrame::OnSplit2()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CRect rect;
	GetClientRect(&rect);

	m_wndSplitter.SetColumnInfo(0, rect.right / 2, 50);
	m_wndSplitter.SetColumnInfo(1, rect.right / 2, 50);

	m_wndSplitter.SetRowInfo(0, rect.bottom, 50);
	m_wndSplitter.SetRowInfo(1, rect.bottom, 50);

	m_wndSplitter.RecalcLayout();

	m_nSplitType = 2;
}


void CMainFrame::OnSplit4()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.

	CRect rect, tRect, sRect;
	GetClientRect(&rect);

	m_wndToolBar.GetClientRect(&tRect);
	m_wndStatusBar.GetClientRect(&sRect);

	m_wndSplitter.SetColumnInfo(0, rect.right / 2, 50);
	m_wndSplitter.SetColumnInfo(1, rect.right / 2, 50);

	m_wndSplitter.SetRowInfo(0, (rect.bottom - tRect.Height() - sRect.Height())/ 2, 50);
	m_wndSplitter.SetRowInfo(1, (rect.bottom - tRect.Height() - sRect.Height())/ 2, 50);

	m_wndSplitter.RecalcLayout();

	m_nSplitType = 4;
}




void CMainFrame::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
		// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (!m_bViewsExist) return;

	switch (m_nSplitType)
	{
	case 1:
		OnSplit1();
		break;
	case 2:
		OnSplit2();
		break;
	case 4:
		OnSplit4();
		break;

	}
}


void CMainFrame::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	lpMMI->ptMinTrackSize.x = 500;
	lpMMI->ptMinTrackSize.y = 500;

	CFrameWnd::OnGetMinMaxInfo(lpMMI);
}
