#if !defined(AFX_BTNTEST_H__BA6490A6_0D91_45BA_8AF7_694A42FB92F9__INCLUDED_)
#define AFX_BTNTEST_H__BA6490A6_0D91_45BA_8AF7_694A42FB92F9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BtnTest.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBtnTest window

class CBtnTest : public CButton
{  
 public:
   //������ɫ�ֱ�Ϊ���֣�Button Down�ı�����ɫ��Button Up�ı�����ɫ
   COLORREF m_TextColor, m_DownColor,m_UpColor;
   CBtnTest(); //ԭ�е�
   //����Button Down�ı�����ɫ
   void SetDownColor(COLORREF color);
   //����Button Up�ı�����ɫ
   void SetUpColor(COLORREF color);
   BOOL Attach(const UINT nID, CWnd* pParent);
	virtual ~CBtnTest();

	// Generated message map functions
protected:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);   //�������صĺ���
	//{{AFX_MSG(CBtnTest)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BTNTEST_H__BA6490A6_0D91_45BA_8AF7_694A42FB92F9__INCLUDED_)
