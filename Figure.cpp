#include "stdafx.h"
/*#include "Figure.h"


CFigure::CFigure(void)
{
}


CFigure::~CFigure(void)
{
}
*/
// #define PI

#include "StdAfx.h"
#include "Figure.h" 
#include <math.h>


 /*
CCircle::CCircle(double x, double y, double R)
{
	m_dCenterX = x;
	m_dCenterY= y;
	m_dRadius = R;
}
CCircle::~CCircle(void)
{
}

bool CCircle::IsInside(double x, double y)
	{
		return  (x - m_dCenterX)*(x - m_dCenterX) + (y - m_dCenterY)*(y - m_dCenterY) < m_dRadius*m_dRadius;
	}

void CCircle::Move(double dx, double dy)
	{
		m_dCenterX += dx;
		m_dCenterY += dy;
	}   

void CCircle::Draw(CDC &dc)
{
	
	dc.Ellipse(m_dCenterX-m_dRadius, m_dCenterY-m_dRadius, m_dCenterX+m_dRadius, m_dCenterX+m_dRadius);
}; 

#include "head.h"
 */


CMy2DPoint::CMy2DPoint() {}
CMy2DPoint::~CMy2DPoint() {}


CMy2DPoint CMy2DPoint::operator +(const CMy2DPoint& vector) {
	return CMy2DPoint(vector.m_x + m_x, vector.m_y + m_y);
}

CMy2DPoint CMy2DPoint::operator -(const CMy2DPoint& vector) {
	return CMy2DPoint(m_x - vector.m_x, m_y - vector.m_y);
}

double CMy2DPoint::operator *(const CMy2DPoint& vector) {
	return m_x*vector.m_x + m_y*vector.m_y;
}

CMy2DPoint CMy2DPoint::operator *(double v) {
	return CMy2DPoint(v*m_x, v*m_y);
}

CMy2DPoint CMy2DPoint::operator /(double v) {
	return CMy2DPoint(m_x / v, m_y / v);
}

bool CMy2DPoint::operator ==(const CMy2DPoint& vector) {
	return (m_x == vector.m_x && m_y == vector.m_y);
}

bool CMy2DPoint::operator !=(const CMy2DPoint& vector) {
	return (m_x != vector.m_x || m_y != vector.m_y);
}

CMy2DPoint& CMy2DPoint::Rotate(double alpha)
{
	double x = m_x*cos(alpha) - m_y*sin(alpha),
		   y = m_x*sin(alpha) + m_y*cos(alpha);
	m_x = x;
	m_y = y;
	return *this;
}


CMy2DPoint operator *(double v, const CMy2DPoint& vector) {
	return CMy2DPoint(v*vector.m_x, v*vector.m_y);
}

ostream& operator <<(ostream& out, const CMy2DPoint& vector) {
	out << "(" << vector.m_x << " " << vector.m_y << ")";
	return out;
}

istream& operator >>(istream& in, CMy2DPoint& vector) {
	in >> vector.m_x;
	in >> vector.m_y;
	return in;
}



CMy2DObjectA4::CMy2DObjectA4() {}
CMy2DObjectA4::CMy2DObjectA4(double a, double a1, double a2, double a3, double x, double y, double ang) : A(abs(a)), A1(abs(a1)), A2(abs(a2)), A3(abs(a3)), m_centre(x, y), m_dAngle(ang) {
	//Set();
	SetA(a);
	SetA1(a1);
	SetA2(a2);
	SetA3(a3);
	SetCentre(x, y);
	SetDAngle(ang);

}
CMy2DObjectA4::~CMy2DObjectA4() {}


double CMy2DObjectA4::GetA() { //������, ������������ �, �1, �2 � �3
	return A;
}
double CMy2DObjectA4::GetA1() {
	return A1;
}
double CMy2DObjectA4::GetA2() {
	return A2;
}
double CMy2DObjectA4::GetA3() {
	return A3;
}

CMy2DPoint CMy2DObjectA4::GetCentre() { //�����, ������������ ���������� ������
	return m_centre;
}

double CMy2DObjectA4::GetAngle() { //�����, ������������ ���� ��������
	return m_dAngle;
}

//�������� ������������ ������

void CMy2DObjectA4::Set() {

	// ��� ���� ��������
	while (m_dAngle > 2 * PI) {  
		m_dAngle -= 2 * PI;
	}
	while (m_dAngle < 0) {
		m_dAngle += 2 * PI;
	}

	while (1) {
		if (A1 > A) { //���� ���� �1 ������� �������
			cout << "������ ";
			cout << *this;
			cout << " �� ����� ���� ���������" << endl;
			cout << "�������� A1 ������" << endl;
			cout << "A1 = ";
			cin >> A1;
			cout << endl;
			continue;
		}
		if (A2 > A*(2*0.5)) {  //���� ���� �2 ������� �������
			cout << "������ ";
			cout << *this;
			cout << " �� ����� ���� ���������" << endl;
			cout << "�������� �2 ������" << endl;
			cout << "A2 = ";
			cin >> A2;
			cout << endl;
			continue;
		}
		if (A3 > A) {  //���� ������� �3 ������� �������
			cout << "������ ";
			cout << *this;
			cout << " �� ����� ���� ���������" << endl;
			cout << "�������� A3 ������" << endl;
			cout << "A3 = ";
			cin >> A3;
			cout << endl;
			continue;
		}
		if ((A1 + A2) > A) {  //����� �1 � �2 ������������
			cout << "������ ";
			cout << *this;
			cout << " ����� ���������������" << endl;
			cout << "�������� A2 ��� A1 ������" << endl;
			cout << "A1 = ";
			cin >> A1;
			cout << "A2 = ";
			cin >> A2;
			cout << endl;
			continue;
		}
		if (A1*A1 > ((A-A3)*(A-A3)) +(A1/2-A3)*(A1/2-A3)) {  //���� �1 � ������� �3 ������������
			cout << "������ ";
			cout << *this;
			cout << " ����� ���������������" << endl;
			cout << "�������� A3 ��� A1 ������" << endl;
			cout << "A1 = ";
			cin >> A1;
			cout << "A3 = ";
			cin >> A3;
			cout << endl;
			continue;
		}
		if ((A2 + A3) > A) {  //���� �2 � ������� �3 ������������
			cout << "������ ";
			cout << *this;
			cout << " ����� ����-�����������" << endl;
			cout << "�������� A3 ��� A2 ������" << endl;
			cout << "A2 = ";
			cin >> A2;
			cout << "A3 = ";
			cin >> A3;
			cout << endl;
			continue;
		}
		break;
	}
}


void CMy2DObjectA4::SetA(double a) {
	if ((A2 + A3) < A) 
	{
		if ((A1 + A3) < A)
		{
			if ((A1 + A2) < 1.25*pow(a, 2))
			{
				A = a;
			}
			else
				cout << "(A1 + A2) < 1.25*A^2 �� �����������" << endl;
		}
		else
			cout << "(A1 + A3) < A �� �����������" << endl;
	}
	else
		cout << "(A2 + A3) < A �� �����������" << endl;
}

void CMy2DObjectA4::SetA1(double a1) {

	if ((a1 + A3) < A) 
	{
		if ((a1 + A3) < A)
		{
			if ((a1 + A2) < 1.25*pow(A, 2))
			{
				A1 = a1;
			}
			else
				cout << "(A1 + A2) < 1.25*A^2 �� �����������" << endl;
		}
		else
			cout << "(A1 + A3) < A �� �����������" << endl;
	}
	else
		cout << "(A2 + A3) < A �� �����������" << endl;
}

void CMy2DObjectA4::SetA2(double a2) {

	if ((a2 + A3) < A) 
	{
		if ((A1 + A3) < A)
		{
			if ((A1 + a2) < 1.25*pow(A, 2))
			{
				A2 = a2;
			}
			else
				cout << "(A1 + A2) < 1.25*A^2 �� �����������" << endl;
		}
		else
			cout << "(A1 + A3) < A �� �����������" << endl;
	}
	else
		cout << "(A2 + A3) < A �� �����������" << endl;
}

void CMy2DObjectA4::SetA3(double a3) {

	if ((A2 + a3) < A) 
	{
		if ((A1 + a3) < A)
		{
			if ((A1 + A2) < 1.25*pow(A, 2))
			{
				A3 = a3;
			}
			else
				cout << "(A1 + A2) < 1.25*A^2 �� �����������" << endl;
		}
		else
			cout << "(A1 + A3) < A �� �����������" << endl;
	}
	else
		cout << "(A2 + A3) < A �� �����������" << endl;
}


void CMy2DObjectA4::SetCentre(const CMy2DPoint& centre)  {
	m_centre = centre;
}

void CMy2DObjectA4::SetCentre(double x, double y)  {
	m_centre.m_x = x;
	m_centre.m_y = y;
}

void CMy2DObjectA4::SetDAngle(double dAngle){
	m_dAngle = dAngle;
}

void CMy2DObjectA4::Rotate(double dAngle) { //����� �������� ������ �� ����
	m_dAngle += dAngle;
	while (m_dAngle > 2 * PI) {  
		m_dAngle -= 2 * PI;
	}
	while (m_dAngle < 0) {
		m_dAngle += 2 * PI;
	}
}

void CMy2DObjectA4::Move(double dX, double dY, double dAngle) { //2 ������ �������� ������� � ������� �����������     //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	m_centre.m_x += dX;
	m_centre.m_y += dY;
	Rotate(dAngle);
}

void CMy2DObjectA4::Move(const CMy2DPoint& delta, double dAngle) {
	Move(delta.m_x, delta.m_y, dAngle);
}

bool CMy2DObjectA4::IsInside(double x, double y) { //����� �����������, ����� �� ����� � ���������                 //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	CMy2DPoint pts[2];

	//pts[0] = CMy2DPoint(x, y);
	//pts[0] = pts[0] - m_centre;

	////�� ������� ��������
	//pts[1] = pts[0];
	//pts[1].Rotate(-m_dAngle);

	pts[1] = (CMy2DPoint(x, y) - m_centre).Rotate(2*PI-m_dAngle);

	if (abs(pts[1].m_x) > A / 2 || abs(pts[1].m_y) > A / 2) {  
		cout << "����� �� ���������� � �������� A" << endl;
		return false;
	}

	if (pts[1].m_y < ((-1)*(A / 2) + A3)) { 
		if (pts[1].m_x < ((-1)*(A / 2) + A3))  {
			cout << "����� ���������� � �������� A3" << endl;
			return false;
		}
	}                                        

	if (((pts[1].m_x - (A / 2))*(pts[1].m_x - (A / 2))) + pts[1].m_y*pts[1].m_y < A1*A1) { 
		cout << "����� ���������� � ����� A1" << endl;
		return false;
	}

	if ((((pts[1].m_x + (A / 2))*(pts[1].m_x + (A / 2))) + (pts[1].m_y - (A / 2))*(pts[1].m_y - (A / 2))) < A2*A2) {
		cout << "����� ����������� A2" << endl;
		return false;
	}
	return true;
}
//�������� ����� �� �������������� ������
//
bool CMy2DObjectA4::IsInside(const CMy2DPoint& point) {
	return IsInside(point.m_x, point.m_y);
}
//����� ���������� � ������
//
/*void Figur(CMy2DObjectA4& Obj) {
	cout << "<" << Obj.GetA() << " " << Obj.GetA1() << " " << Obj.GetA2() << " " << Obj.GetA3() << " " << Obj.GetCentre() << " " << Obj.GetAngle() << ">";
}*/



ostream& operator <<(ostream& out, const CMy2DObjectA4& vector) {
	out << "{" << vector.A << ", " << vector.A1 << ", " <<  vector.A2 << ", " << vector.A3 << ", " << vector.m_centre << ", " << vector.m_dAngle << "} ";
	return out;
}

istream& operator >>(istream& in, CMy2DObjectA4& vector) {
	in >> vector.A >> vector.A1 >> vector.A2 >> vector.A3 >> vector.m_centre >> vector.m_dAngle;
	return in;
}

void CMy2DObjectA4::Draw(CDC &dc)
{
	//double pts[0].x, pts[0].y, pts[1].x, pts[1].y;
	//double x = 350, y = 350;
	//pts[0].x = x - m_centre.m_x;
	//pts[0].y = y - m_centre.m_y;

	//�� ������� ��������
	//pts[1].x = pts[0].x*cos(m_dAngle) - pts[0].y*sin(m_dAngle); 
	//pts[1].y = pts[0].x*sin(m_dAngle) + pts[0].y*cos(m_dAngle);

	CMy2DPoint pts[11];

	pts[0].m_x = - A/2 + A3;	// x_1
	pts[0].m_y = - A/2 + A3;
	pts[1].m_x = - A/2 + A3;	//x_2
	pts[1].m_y = - A/2;
	pts[2].m_x = - A/2;			//x_3
	pts[2].m_y = - A/2 + A3;
	pts[3].m_x = - A/2;			//x_4
	pts[3].m_y = + A/2 - A2;
	pts[4].m_x = - A/2;			//x_45
	pts[4].m_y = + A/2;
	pts[5].m_x = - A/2 + A2;	//x_5
	pts[5].m_y = + A/2;
	pts[6].m_x = + A/2;			//x_6
	pts[6].m_y = + A/2;
	pts[7].m_x = + A/2;			//x_7
	pts[7].m_y = + A1;
	pts[8].m_x = + A/2;			//x_78
	pts[8].m_y = 0;
	pts[9].m_x = + A/2;			//x_8
	pts[9].m_y = - A1;
	pts[10].m_x = + A/2;		//x_9
	pts[10].m_y = - A/2;


	for (int i = 0; i < 11; i++)
	{
		pts[i].Rotate(m_dAngle);
		pts[i] = pts[i] + m_centre;
	}

	dc.MoveTo(pts[0].GetP());
	dc.LineTo(pts[1].GetP());
	dc.MoveTo(pts[0].GetP());
	dc.LineTo(pts[2].GetP());
	dc.LineTo(pts[3].GetP());
	dc.AngleArc(pts[4].m_x, pts[4].m_y, A2, 90 - m_dAngle*180/PI, -90);
	dc.LineTo(pts[5].GetP());
	dc.LineTo(pts[6].GetP());
	dc.LineTo(pts[7].GetP());
	dc.MoveTo(pts[9].GetP());
	dc.AngleArc(pts[8].m_x, pts[8].m_y, A1, 90 - m_dAngle*180/PI, 180);
	dc.MoveTo(pts[9].GetP());
	dc.LineTo(pts[10].GetP());
	dc.LineTo(pts[1].GetP());
}; 

