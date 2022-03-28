#pragma once
#include "CMyVector.h"

class C_DGLSolver {
private:
	CMyVektor(*f_DGL_System)(CMyVektor y, double x);
	double (*f_DGL_nterOrdnung)(CMyVektor y, double x);
	CMyVektor ableitungen(CMyVektor y, double x);
	bool DGL_Sytem = false;
public:
	C_DGLSolver(CMyVektor(*f_DGL_System)(CMyVektor y, double x)) : f_DGL_System{ f_DGL_System }, DGL_Sytem{ true } {}
	C_DGLSolver(double (*f_DGL_nterOrdnung)(CMyVektor y, double x)) : f_DGL_nterOrdnung{ f_DGL_nterOrdnung }, DGL_Sytem{ false } {}
	CMyVektor Euler_Verfahren(double x_start, double x_end, int schritte, CMyVektor y_start);
	CMyVektor Heun_Verfahren(double x_start, double x_end, int schritte, CMyVektor y_start);
};
