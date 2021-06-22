
// MFCApplication1Dlg.h : header file
//

#pragma once
#include "BtnST.h"
#include "Label.h"
#include "ini.h"
#include "CDlgImage.h"
#include "CDlgParameter.h"

// CMFCApplication1Dlg dialog
class CMFCApplication1Dlg : public CDialogEx
{
// Construction
public:
	CMFCApplication1Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATION1_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonNew();

	int nThreshold = 128;

	CButtonST m_btnNew;
	void InitButtons(CButtonST* pButton);
	double m_dNum;
	CLabel m_lblNum;
	void InitLabels(CLabel* pLabel);

	void UpdateIni(BOOL bLoad);
	afx_msg void OnBnClickedOk();

	CDlgImage* m_pDlgImage;
	CDlgParameter* m_pDlgParameter;

	void InitDialog();
	void setDlgView(int nMode);

	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButtonImage();
	afx_msg void OnBnClickedButtonParameter();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonLoad();
	afx_msg void OnBnClickedButtonBinary();
	afx_msg void OnBnClickedButtonCentroid();
};
