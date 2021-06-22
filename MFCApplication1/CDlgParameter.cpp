// CDlgParameter.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication1.h"
#include "CDlgParameter.h"
#include "afxdialogex.h"
#include "MFCApplication1Dlg.h"

// CDlgParameter dialog

IMPLEMENT_DYNAMIC(CDlgParameter, CDialog)

CDlgParameter::CDlgParameter(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CDlgParameter, pParent)
	, m_nThreshold(0)
{
	m_pParent = pParent;
}

CDlgParameter::~CDlgParameter()
{
}

void CDlgParameter::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_THR, m_nThreshold);
}


BEGIN_MESSAGE_MAP(CDlgParameter, CDialog)
END_MESSAGE_MAP()


// CDlgParameter message handlers


BOOL CDlgParameter::PreTranslateMessage(MSG* pMsg)
{
	// TODO: Add your specialized code here and/or call the base class
	
	if (pMsg->message == WM_KEYDOWN && pMsg->hwnd == GetDlgItem(IDC_EDIT_THR)->m_hWnd) {
		// Ű�� ���ȴ��� , edit���� ���ȴ��� Ȯ��
		if (pMsg->wParam == VK_RETURN) {
			// ����Ű���� Ȯ��
			UpdateData(true);
			CMFCApplication1Dlg* pDlg = (CMFCApplication1Dlg*)m_pParent;

			pDlg->nThreshold = m_nThreshold;

			pDlg->m_pDlgParameter->ShowWindow(SW_HIDE);
			pDlg->m_pDlgImage->ShowWindow(SW_SHOW);

			return TRUE;
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}
