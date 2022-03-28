#include "C_DGLSolver.h"
#include <math.h>
#include <iostream>

CMyVektor C_DGLSolver::ableitungen(CMyVektor y, double x) {
	CMyVektor result;
	if(DGL_Sytem == true) result = f_DGL_System(y, x);
	else {
		result.vektor_anlegen(y.get_dimension());
		result.set_komponente(y.get_dimension() - 1, f_DGL_nterOrdnung(y, x));
		for (int i = 0; i < y.get_dimension() - 1; i++) {
			result.set_komponente(i, y.get_komponente((double)i + 1));
		}
	}
	return result;
}

CMyVektor C_DGLSolver::Euler_Verfahren(double x_start, double x_end, int schritte, CMyVektor y_start) {
	CMyVektor y = y_start;
	CMyVektor ableitung = ableitungen(y, x_start);
	double x = x_start;
	double differenz = x_end - x_start;
	double schrittweite = differenz / double(schritte);
	std::cout << "=================\n";
	std::cout << "Euler-Verfahren\n";
	std::cout << "=================\n";
	std::cout << "h = " << schrittweite << std::endl << std::endl;
	for (int i = 0; i < schritte; i++) {
		x = x_start + (schrittweite * i);
		ableitung = ableitungen(y, x);
		std::cout << "Schritt " << i << ":\n";
		std::cout << "x = " << x << std::endl;
		std::cout << "y = "; y.print();
		std::cout << "y' = "; ableitung.print();
		std::cout << "============================\n";
		y += schrittweite * ableitungen(y, x);
		if (i + 1 == schritte) {
			x = x_start + (schrittweite * (double(i) + 1));
			std::cout << "Ende bei \n";
			std::cout << "x = " << x << std::endl;
			std::cout << "y = "; y.print(); std::cout << std::endl;
		}
	}
	return y;
}

CMyVektor C_DGLSolver::Heun_Verfahren(double x_start, double x_end, int schritte, CMyVektor y_start) {
	CMyVektor heun_s = y_start;
	CMyVektor y = y_start;
	CMyVektor steigungswert = y_start;
	CMyVektor ymittel = y_start;
	CMyVektor ableitung = ableitungen(heun_s, x_start);
	double x = x_start;
	double differenz = x_end - x_start;
	double schrittweite = differenz / double(schritte);
	std::cout << "=================\n";
	std::cout << "Heun-Verfahren\n";
	std::cout << "=================\n";
	std::cout << "h = " << schrittweite << std::endl << std::endl;
	for (int i = 0; i < schritte; i++) {
		x = x_start + (schrittweite * i);
		ableitung = ableitungen(heun_s, x);
		std::cout << "Schritt " << i << ":\n";
		std::cout << "x = " << x << std::endl;
		std::cout << "y = "; heun_s.print();
		std::cout << "y'_orig = "; ableitung.print(); std::cout << std::endl;
		y = heun_s + schrittweite * ableitungen(heun_s, x);
		steigungswert = ableitungen(y, x + schrittweite);
		ymittel = 0.5 * (ableitung + steigungswert);
		std::cout << "y_Test = "; y.print();
		std::cout << "y'_Test = "; steigungswert.print(); std::cout << std::endl;
		std::cout << "y'_mittel = "; ymittel.print();
		std::cout << "=================================\n";
		heun_s += schrittweite * ymittel;
		if (i + 1 == schritte) {
			x = x_start + (schrittweite * (double(i) + 1));
			std::cout << "Ende bei \n";
			std::cout << "x = " << x << std::endl;
			std::cout << "y = "; heun_s.print(); std::cout << std::endl;
		}
	}
	return heun_s;
}
