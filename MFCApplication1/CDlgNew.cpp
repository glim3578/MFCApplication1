// CDlgNew.cpp : implementation file
//

#include "pch.h"
#include "MFCApplication1.h"
#include "CDlgNew.h"
#include "afxdialogex.h"


// CDlgNew dialog

IMPLEMENT_DYNAMIC(CDlgNew, CDialogEx)

CDlgNew::CDlgNew(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_NEW, pParent)
{

}

CDlgNew::~CDlgNew()
{
}

void CDlgNew::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgNew, CDialogEx)
END_MESSAGE_MAP()


// CDlgNew message handlers
