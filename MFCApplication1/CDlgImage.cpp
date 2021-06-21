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
END_MESSAGE_MAP()


// CDlgImage message handlers
