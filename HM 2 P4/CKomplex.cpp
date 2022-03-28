#include "CKomplex.h"

CKomplex CKomplex::operator+(CKomplex ckomplex) {
	double summe_real = this->realteil + ckomplex.realteil;
	double summe2_imag = this->imaginaerteil + ckomplex.imaginaerteil;
	CKomplex result(summe_real, summe2_imag);
	return result;
}

CKomplex CKomplex::operator-(CKomplex ckomplex) {
	double differenz_real = this->realteil - ckomplex.realteil;
	double differenz_imag = this->imaginaerteil - ckomplex.imaginaerteil;
	CKomplex result(differenz_real, differenz_imag);
	return result;
}

CKomplex CKomplex::operator*(CKomplex ckomplex) {
	double summe = this->realteil * ckomplex.realteil;
	double summe2 = this->realteil * ckomplex.imaginaerteil;
	double summe3 = this->imaginaerteil * ckomplex.realteil;
	double summe4 = -(this->imaginaerteil * ckomplex.imaginaerteil);
	CKomplex result(summe + summe4, summe2 + summe3);
	return result;
}

CKomplex CKomplex::operator*(double value) {
	double summe = this->realteil * value;
	double summe2 = this->imaginaerteil * value;
	CKomplex result(summe, summe2);
	return result;
}

double CKomplex::abs() {
	double result = sqrt((this->realteil * this->realteil) + (this->imaginaerteil * this->imaginaerteil));
	return result;
}
