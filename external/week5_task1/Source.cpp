#include <iostream>

using namespace std;

extern "C" int* __fastcall task1(int*, int);



void main()
{
	int* a = new int[7];
	a[0] = 5;
	a[1] = 2;
	a[2] = 7;
	a[3] = 4;
	a[4] = 1;
	a[5] = 3;
	a[6] = 9;
	int* answer = task1(a, 7);
	cout << *answer;
	cout << endl;
	system("pause");
}

