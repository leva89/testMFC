#pragma once


// ���������� ���� CDlgProperties

class CDlgProperties : public CDialogEx
{
	DECLARE_DYNAMIC(CDlgProperties)



public:
	CDlgProperties(double A = 0,
				   double A1 = 0,
				   double A2 = 0,
				   double A3 = 0,
				   double Angle = 0,
				   CWnd* pParent = NULL);   // ����������� �����������
	virtual ~CDlgProperties();

	void SetA(double par);

// ������ ����������� ����
	enum { IDD = IDD_PROPERTIES };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // ��������� DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	double m_dA;
	double m_dA1;
	double m_dA2;
	double m_dA3;
	double m_dAngle;
	afx_msg void OnBnClickedOk();
};
