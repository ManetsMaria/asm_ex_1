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
			fldl2t   //загрузка двоичного логарифма десяти в вершину стека сопроцессора
			fmul
			fld     st
			frndint //округляет значение в ST к целому
			fsub    st(1), st
			fxch    st(1) // помещает значение st(1) в st(0)
			f2xm1  // вычисление степени двойки, если х<=1/2
			fld1   // +1 в st(0)
			fadd
			fscale // умножает st на 2 в степени st(1)
			fstp    ans

	}
	cout << ans;
	system("pause");
	return 0;
}

