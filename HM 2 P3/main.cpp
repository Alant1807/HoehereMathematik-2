#include <iostream>
#include "C_DGLSolver.h"

using namespace std;

CMyVektor DGLSystem(CMyVektor y, double x) {
	CMyVektor func;
	func[0] = (2.0 * y[1]) - (x * y[0]);
	func[1] = (y[0] * y[1]) - (2.0 * x * x * x);
	return func;
}

double DGLdritterOrdnung(CMyVektor y, double x) {
	double result = (2.0 * x * y[1] * y[2]) + (2.0 * y[0] * y[0] * y[1]);
	return result;
}

int main() {

	
	/*C_DGLSolver dgl(DGLSystem);
	CMyVektor y;
	y.set_dimension(2, 0); y[0] = 0; y[1] = 1;
	dgl.Euler_Verfahren(0.0, 2.0, 100, y);
	dgl.Heun_Verfahren(0.0, 2.0, 100, y);*/

	C_DGLSolver dgl2(DGLdritterOrdnung);
	CMyVektor y;
	y.set_dimension(3, 0); y[0] = 1; y[1] = -1; y[2] = 2;
	vector<double> vec_eul; vector<double> vec_heun;
	for (int schritte = 10; schritte < 100000; schritte *= 10) {
		vec_eul.push_back((dgl2.Euler_Verfahren(1, 2, schritte, y)[0]) - 0.5);
		vec_heun.push_back((dgl2.Heun_Verfahren(1, 2, schritte, y)[0]) - 0.5);
	}
	auto iter = vec_eul.begin(); auto iter2 = vec_heun.begin();
	int schritte = 10;
	while (iter != vec_eul.end() && iter2 != vec_heun.end()) {
		cout << "Abweichung bei Euler bei " << schritte << " Schritten: " << *iter << endl;
		cout << "Abweichung bei Heun bei " << schritte << " Schritten: " << *iter2 << endl;
		schritte *= 10;
		iter++;
		iter2++;
	}
	
	cout << endl;
	system("pause");
	return 0;
}