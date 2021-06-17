#pragma once


// CDlgNew dialog

class CDlgNew : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgNew)

public:
	CDlgNew(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgNew();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_NEW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
