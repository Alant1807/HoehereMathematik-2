#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <vector>
#include <string>

class CKomplex {
private: double realteil = 0.0; double imaginaerteil = 0.0;
public: 
	CKomplex() : realteil{ 0.0 }, imaginaerteil{ 0.0 } {}
	CKomplex(double realteil, double imaginaerteil) : realteil{realteil}, imaginaerteil{imaginaerteil} {}
	CKomplex(double phi) : realteil{ cos(phi) }, imaginaerteil{ sin(phi) } {}
	void setrealteil(double realteil) { this->realteil = realteil; }
	double getrealteil() const { return this->realteil; }
	void setimaginaerteil(double imaginaerteil) { this->imaginaerteil = imaginaerteil; }
	double getimaginaerteil()const { return this->imaginaerteil; }
	CKomplex operator+(CKomplex ckomplex);
	CKomplex operator-(CKomplex ckomplex);
	CKomplex operator*(CKomplex ckomplex);
	CKomplex operator* (double value);
	double abs();
};
