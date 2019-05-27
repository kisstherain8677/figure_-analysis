#include "pch.h"
#include "global.h"
#include <iostream>
#include <math.h>
using namespace std;

void LongBeiGe(double x0,double x1, double(*ptest)(double));
double test(double x);

int main()
{
	LongBeiGe(0.000000001,1, test);
}

//测试的多项式g(x)
double test(double x) {
	return sin(x)/x;
}

//用龙贝格算式求积分 a:左端点，b：右端点 e
void LongBeiGe(double a, double b,double(*ptest)(double)) {
	double T1=0, T2=0, S1=0, S2=0, C1=0, C2=0, R1=0, R2=0, S;
	R1 = 0; R2 = R1 + 2 * ACCURACY;
	double h = b - a;//步长
    T1 = h / 2.0*(ptest(a) + ptest(b));//梯形积分
	int k = 1;//迭代次数
	
	while (abs(R1 - R2) >= ACCURACY) {
		S = 0;
		for (double x = a + h / 2.0; x < b; x += h) {
			S += ptest(x);
		}
		T2 = T1 / 2.0 + S * h / 2.0;
		if (k == 1) {
			cout << "T" << k << ": " << T1 << endl;
			cout << "T" << k + 1 << ": " << T2 << endl;
		}
		else {
			cout << "T" << k + 1 << ": " << T2 << endl;
		}
		
		S2 = T2 + (T2 - T1) / 3.0;
		if (k == 1) {
			//cout << "S" << k << ": " << S1 << endl;
			cout << "S" << k + 1 << ": " << S2 << endl;
		}
		else {
			cout << "S" << k + 1 << ": " << S2 << endl;
		}
		if (k == 1) {
			k++;
			h /= 2.0;
			T1 = T2;
			S1 = S2;
			continue;
		}
		C2 = S2 + (S2 - S1) / 15.0;
		if (k == 1) {
			cout << "C" << k << ": " << C1 << endl;
			cout << "C" << k + 1 << ": " << C2 << endl;
		}
		else {
			cout << "C" << k + 1 << ": " << C2 << endl;
		}
		if (k == 2) {
			C1 = C2;
			k++;
			h /= 2.0;
			T1 = T2;
			S1 = S2;
			continue;
		}
		R2 = C2 + (C2 - C1) / 63.0;
		if (k == 1) {
			cout << "R" << k << ": " << R1 << endl;
			cout << "R" << k + 1 << ": " << R2 << endl;
		}
		else {
			cout << "R" << k + 1 << ": " << R2 << endl;
		}
		if (k == 3) {
			R1 = R2;
			C1 = C2;
			k++;
			h /= 2.0;
			T1 = T2;
			S1 = S2;
			continue;
		}


	
	}
	cout << R2 << endl;
}

