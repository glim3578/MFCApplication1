
// MFCApplication1Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplication1.h"
#include "MFCApplication1Dlg.h"
#include "afxdialogex.h"

#include "CDlgNew.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include <fstream>

#define COLOR_LABEL_BK RGB(100,0,0)
#define COLOR_LABEL_TEXT RGB(255,255,255)
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCApplication1Dlg dialog



CMFCApplication1Dlg::CMFCApplication1Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATION1_DIALOG, pParent)
	, m_dNum(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_NEW, m_btnNew);
	DDX_Text(pDX, IDC_EDIT1, m_dNum);
	DDX_Control(pDX, IDC_STATIC1, m_lblNum);
}

BEGIN_MESSAGE_MAP(CMFCApplication1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_NEW, &CMFCApplication1Dlg::OnBnClickedButtonNew)
	ON_BN_CLICKED(IDOK, &CMFCApplication1Dlg::OnBnClickedOk)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON_IMAGE, &CMFCApplication1Dlg::OnBnClickedButtonImage)
	ON_BN_CLICKED(IDC_BUTTON_PARAMETER, &CMFCApplication1Dlg::OnBnClickedButtonParameter)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CMFCApplication1Dlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_LOAD, &CMFCApplication1Dlg::OnBnClickedButtonLoad)
END_MESSAGE_MAP()


// CMFCApplication1Dlg message handlers

BOOL CMFCApplication1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	InitButtons(&m_btnNew);
	InitLabels(&m_lblNum);
	InitDialog();

	UpdateIni(true);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplication1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplication1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplication1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMFCApplication1Dlg::InitDialog() {

	m_pDlgImage = new CDlgImage();
	m_pDlgImage->Create(IDD_CDlgImage);
	m_pDlgImage->MoveWindow(20, 100, 600, 350);
	
	m_pDlgParameter = new CDlgParameter();
	m_pDlgParameter->Create(IDD_CDlgParameter);
	m_pDlgParameter->MoveWindow(20, 100, 600, 350);

	setDlgView(DLG_VIEW_IMAGE);
}

void CMFCApplication1Dlg::setDlgView(int nMode) {

	if (nMode & DLG_VIEW_IMAGE)
		m_pDlgImage->ShowWindow(SW_SHOW);
	else
		m_pDlgImage->ShowWindow(SW_HIDE);

	if (nMode & DLG_VIEW_PARAMETER)
		m_pDlgParameter->ShowWindow(SW_SHOW);
	else
		m_pDlgParameter->ShowWindow(SW_HIDE);
	
}

void CMFCApplication1Dlg::InitButtons(CButtonST* pButton) {

	CFont Font;
	Font.CreatePointFont(30, _T("Consolas"));

	pButton->SetFont(&Font);
	pButton->SetColor(CButtonST::BTNST_COLOR_BK_IN, COLOR_LABEL_BK);
	pButton->SetColor(CButtonST::BTNST_COLOR_BK_OUT, COLOR_LABEL_BK);
	pButton->SetColor(CButtonST::BTNST_COLOR_BK_FOCUS, COLOR_LABEL_BK);
	pButton->SetColor(CButtonST::BTNST_COLOR_FG_IN, COLOR_LABEL_TEXT);
	pButton->SetColor(CButtonST::BTNST_COLOR_FG_OUT, COLOR_LABEL_TEXT);
	pButton->SetColor(CButtonST::BTNST_COLOR_FG_FOCUS, COLOR_LABEL_TEXT);

}
void CMFCApplication1Dlg::InitLabels(CLabel* pLabel) {

	pLabel->SetFontName(_T("Consolas"));
	pLabel->SetFontSize(20);

	pLabel->SetBkColor(COLOR_LABEL_BK);
	pLabel->SetTextColor(COLOR_LABEL_TEXT);

}

void CMFCApplication1Dlg::UpdateIni(BOOL bLoad) {

	CString fileName = CString("C://Users//GLIM//source//repos//glim3578//MFCApplication1//MFCApplication1//Glim.ini");
	std::ifstream file(fileName);

	if (!file.good()) bLoad = false;

	CString str(fileName);
	CString strSection(_T("Parameters"));

	CIni ini(str, strSection);

	ini.SerGet(bLoad, m_dNum, _T("NUM"));

	UpdateData(false);
}

void CMFCApplication1Dlg::OnBnClickedButtonNew()
{
	// TODO: Add your control notification handler code here

	
	UpdateData(true);
	m_lblNum.SetText(m_dNum);

}


void CMFCApplication1Dlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	UpdateData(true);
	UpdateIni(false);

	CDialogEx::OnOK();
}


void CMFCApplication1Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: Add your message handler code here
	delete m_pDlgImage;
	delete m_pDlgParameter;

}


void CMFCApplication1Dlg::OnBnClickedButtonImage()
{
	// TODO: Add your control notification handler code here

	setDlgView(DLG_VIEW_IMAGE);

}


void CMFCApplication1Dlg::OnBnClickedButtonParameter()
{
	// TODO: Add your control notification handler code here

	setDlgView(DLG_VIEW_PARAMETER);
}


void CMFCApplication1Dlg::OnBnClickedButtonSave()
{
	// TODO: Add your control notification handler code here
	char strFilter[] = "BMP ONLY (*.BMP) | *.BMP;*.bmp | All Files(*.*)|*.*||";
	CFileDialog FileDlg(TRUE, CString(".BMP"), NULL, 0, CString(strFilter));

	if (FileDlg.DoModal() == IDOK) {
		m_pDlgImage->m_imgFile.Save(FileDlg.GetPathName());
	}
}


void CMFCApplication1Dlg::OnBnClickedButtonLoad()
{
	// TODO: Add your control notification handler code here

	char strFilter[] = "BMP ONLY (*.BMP) | *.BMP;*.bmp | All Files(*.*)|*.*||";
	CFileDialog FileDlg(TRUE, CString(".BMP"), NULL, 0, CString(strFilter));

	if (FileDlg.DoModal() == IDOK) {

		HRESULT hr = m_pDlgImage->m_imgFile.Load(FileDlg.GetPathName());

		if (SUCCEEDED(hr)) {

			//이미지 출력
			m_pDlgParameter->ShowWindow(SW_HIDE);
			m_pDlgImage->ShowWindow(SW_HIDE);
			m_pDlgImage->ShowWindow(SW_SHOW); // for repaint 

		}
	}
}
