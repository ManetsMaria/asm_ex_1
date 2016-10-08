// week4_task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int a[5][5] = { { 2, 30, 3, 11, 1 },
	                { 10, 5, 6, 1, 1 },
	                { 7, 6, 100, 9, 1 },
	                { 21, 22, 23, 24, 1 },
	                { 1, 1, 1, 1, 1 } };
	int b[9] = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int n = 5;
	__asm{
		mov esi, 0
		mov edi, n
		mov ebx, 0
	beg:
		cmp esi, 0
		je equal1
		sub edi, 1
		cmp esi, edi
		je equal2
		add edi, 1
		mov eax, edi
		imul n
		sub eax, n
		cmp eax, esi
		je equal3
		add eax, n
		sub eax, 1
		cmp eax, esi
		je equal4
		mov eax, esi
		cdq
		idiv edi
		cmp edx, 0
		je equal5
		cmp esi, edi
		jl equal6
		sub edi,1
		cmp edx, edi
		je equal7
		add edi,1
		add eax, 1
		cmp eax, edi
		je equal8
		jmp equal9
	equal1:
		mov ecx, esi
		add ecx, 1
		mov edx, a[ecx*4]
		cmp edx, a[esi*4]
		jg change_
		sub ecx, 1
		add ecx, edi
		mov edx, a[ecx*4]
		cmp edx, a[esi*4]
		jg change_
		jmp end_
	equal2:
		add edi, 1
		mov ecx, esi
		sub ecx, 1
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		add ecx, 1
		add ecx, edi
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		jmp end_
	equal3:
		mov ecx, esi
		add ecx, 1
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		sub ecx, 1
		sub ecx, edi
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		jmp end_
	equal4:
		mov ecx, esi
		sub ecx, 1
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		add ecx, 1
		sub ecx, edi
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		jmp end_
	equal5:
		mov ecx, esi
		add ecx, 1
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		sub ecx, 1
		add ecx, edi
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		sub ecx, edi
		sub ecx, edi
		mov edx, a[ecx*4]
		cmp edx, a[esi*4]
		jg change_
		jmp end_
	equal6:
		mov ecx, esi
		add ecx, 1
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		sub ecx, 1
		add ecx, edi
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		sub ecx, edi
		sub ecx, 1
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		jmp end_
	equal7:
		add edi,1
		mov ecx, esi
		sub ecx, 1
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		add ecx, 1
		add ecx, edi
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		sub ecx, edi
		sub ecx, edi
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		jmp end_
	equal8:
		mov ecx, esi
		add ecx, 1
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		sub ecx, 1
		sub ecx, edi
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		add ecx, edi
		sub ecx, 1
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		jmp end_
	equal9:
		mov ecx, esi
		add ecx, 1
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		sub ecx, 1
		add ecx, edi
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		sub ecx, edi
		sub ecx, edi
		mov edx, a[ecx * 4]
		cmp edx, a[esi * 4]
		jg change_
		add ecx, edi
		sub ecx, 1
		mov edx, a[ecx*4]
		cmp edx, a[esi*4]
		jg change_
		jmp end_
	change_:
		mov eax, n
		imul n
		sub eax, 1
		cmp esi, eax
		je end_end_
		add esi, 1
		jmp beg
	end_:
		mov edx, a[esi*4]
		mov b[ebx*4], edx
		add ebx,1
		mov eax, n
		imul n
		sub eax, 1
		cmp esi, eax
		je end_end_
		add esi, 1
		jmp beg
	end_end_:
		mov n, ebx
	}
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	system("pause");
	return 0;
}

