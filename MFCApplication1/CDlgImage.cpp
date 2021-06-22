// CDlgImage.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication1.h"
#include "CDlgImage.h"
#include "afxdialogex.h"


// CDlgImage dialog

IMPLEMENT_DYNAMIC(CDlgImage, CDialog)

CDlgImage::CDlgImage(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_CDlgImage, pParent)
{
}

CDlgImage::~CDlgImage()
{
}

void CDlgImage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgImage, CDialog)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CDlgImage message handlers



void CDlgImage::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CDialog::OnPaint() for painting messages

	drawImage();

}


void CDlgImage::drawImage() {
	CStatic* staticsize = (CStatic*)GetDlgItem(IDC_STATIC_IMAGE);
	CClientDC dc(staticsize);

	CRect rect;
	staticsize->GetClientRect(rect);

	if (m_imgFile != NULL) {

		int w = m_imgFile.GetWidth();
		int h = m_imgFile.GetWidth();

		m_imgFile.BitBlt(dc.m_hDC, 0, 0, w, h, 0, 0);
	}
}