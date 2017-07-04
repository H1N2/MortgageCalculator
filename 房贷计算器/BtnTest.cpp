// BtnTest.cpp : implementation file
//

#include "stdafx.h"
#include "����������03.h"
#include "BtnTest.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBtnTest
CBtnTest::CBtnTest(void)
{
  m_DownColor = m_UpColor = RGB(0,0,0);//��ʼ����Ϊ��ɫ
}
CBtnTest::~CBtnTest(void)
{
}
BEGIN_MESSAGE_MAP(CBtnTest, CButton)
	//{{AFX_MSG_MAP(CBtnTest)
		// NOTE - the ClassWizard will add and remove mapping macros here.

	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
 
BOOL CBtnTest::Attach(const UINT nID,CWnd* pParent)
{
    if (!SubclassDlgItem(nID, pParent))
    return FALSE;
    return TRUE;
}
void CBtnTest::SetDownColor(COLORREF color)
{   
	//CMyButton��ĺ���
    m_DownColor = color;
}
void CBtnTest::SetUpColor(COLORREF color)
{
    m_UpColor = color;
}
void CBtnTest::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
   CDC dc;
   dc.Attach(lpDrawItemStruct->hDC);//�õ����Ƶ��豸����CDC
    VERIFY(lpDrawItemStruct->CtlType==ODT_BUTTON);
   //�õ�Button������,����Ĳ�����:1,�ȵõ�����Դ��༭�İ�ť������,
   //Ȼ�󽫴��������»��Ƶ���ť��,
    //ͬʱ�������ֵı���ɫ��Ϊ͸��,����,��ť�Ͻ�����ʾ����
    const int bufSize = 512;
    TCHAR buffer[bufSize];
    GetWindowText(buffer, bufSize);
   int size=strlen(buffer);//�õ�����
   DrawText(lpDrawItemStruct->hDC,buffer,size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);//��������
   SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);//͸��
   if (lpDrawItemStruct->itemState&ODS_SELECTED)//�����°�ťʱ�Ĵ���
   {////�ػ���������
         CBrush brush(m_DownColor);
          dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//���û�ˢbrush�������ο�
         //��Ϊ����������ػ�,��������ҲҪ�ػ�
         DrawText(lpDrawItemStruct->hDC,buffer,size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);
          SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);
    }
  else//����ť���������ߵ���ʱ
    {
           CBrush brush(m_UpColor);
            dc.FillRect(&(lpDrawItemStruct->rcItem),&brush);//
            DrawText(lpDrawItemStruct->hDC,buffer,size,&lpDrawItemStruct->rcItem,DT_CENTER|DT_VCENTER|DT_SINGLELINE|DT_TABSTOP);
            SetBkMode(lpDrawItemStruct->hDC,TRANSPARENT);
     }
    if ((lpDrawItemStruct->itemState&ODS_SELECTED)&&(lpDrawItemStruct->itemAction &(ODA_SELECT|ODA_DRAWENTIRE)))
     {//ѡ���˱��ؼ�,�����߿�
         COLORREF fc=RGB(255-GetRValue(m_UpColor),255-GetGValue(m_UpColor),255-GetBValue(m_UpColor));
         CBrush brush(fc);
		 dc.FrameRect(&(lpDrawItemStruct->rcItem),&brush);//�û�ˢbrush�������α߿�
      }
     if (!(lpDrawItemStruct->itemState &ODS_SELECTED) &&(lpDrawItemStruct->itemAction & ODA_SELECT))
     {
          CBrush brush(m_UpColor); //���Ƶ�ѡ��״̬����,ȥ���߿�
		  dc.FrameRect(&lpDrawItemStruct->rcItem,&brush);//
	 }
		  dc.Detach();
}
