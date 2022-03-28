#include <iostream>
#include "CMyVector.h"
using namespace std;

double function(CMyVektor x) {
	return pow(x[0], 2) * sin(x[1] * x[2]);
}

double function_f(CMyVektor x) {
	return sin(x[0] * x[1]) + sin(x[0]) + cos(x[1]);
}

double function_g(CMyVektor x) {
	return (-(2 * pow(x[0], 2) - 2 * x[0] * x[1] + pow(x[1], 2) + pow(x[2], 2) - 2 * x[0] - 4 * x[2]));
}

int main() {

	CMyVektor vec;
	vector<double> v = { 3,6,8 };
	vec(v);
	cout << "Vec: " << vec.print() << endl;
	CMyVektor vec2;
	vector<double> v2 = { 2,2,2 };
	vec2(v2);
	cout << "Vec2: " << vec2.print() << endl;
	vec2 += vec;
	cout << "Ergebnis Vec + Vec2: " << vec2.print() << endl << endl;
	CMyVektor vector2;
	vector<double> vector1 = { 2,1,3 };
	vector2(vector1);
	cout << "Numerischer Gradient von Vektor1 im Punkt (2,1,3) zu der Funktion: f(x,y,z) = x^2 *sin(y*z) betraegt : ";
	CMyVektor vector3(vector2.gradient(vector2, function));
	cout << vector3.print() << endl << endl;

	CMyVektor s;
	vector<double>punkt1 = { 0.2,-2.1 };
	vector<double>punkt2 = { 0, 0, 0 };
	s(punkt1); // f
	CMyVektor grad;
	CMyVektor s2;
	grad.gradientenVerfahren(s, function_f, 1.0);
	s2(punkt2); // g
	//grad.gradientenVerfahren(s2, function_g, 0.1);

	cout << "\n";
	system("pause");
	return 0;
}