// task4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	double valX = 0.5, ans;
	__asm{
		finit
		    fld     qword ptr valX
			fldl2t   //�������� ��������� ��������� ������ � ������� ����� ������������
			fmul
			fld     st
			frndint //��������� �������� � ST � ������
			fsub    st(1), st
			fxch    st(1) // �������� �������� st(1) � st(0)
			f2xm1  // ���������� ������� ������, ���� �<=1/2
			fld1   // +1 � st(0)
			fadd
			fscale // �������� st �� 2 � ������� st(1)
			fstp    ans

	}
	cout << ans;
	system("pause");
	return 0;
}

