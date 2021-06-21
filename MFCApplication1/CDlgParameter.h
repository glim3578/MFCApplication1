#pragma once


// CDlgParameter dialog

class CDlgParameter : public CDialog
{
	DECLARE_DYNAMIC(CDlgParameter)

public:
	CDlgParameter(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CDlgParameter();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CDlgParameter };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
