
// Experiment_MFC.h : ������� ���� ��������� ��� ���������� Experiment_MFC
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�������� stdafx.h �� ��������� ����� ����� � PCH"
#endif

#include "resource.h"       // �������� �������
#include "Experiment_MFC_i.h"


// CExperiment_MFCApp:
// � ���������� ������� ������ ��. Experiment_MFC.cpp
//

class CExperiment_MFCApp : public CWinApp
{
public:
	CExperiment_MFCApp();


// ���������������
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ����������

public:
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CExperiment_MFCApp theApp;
