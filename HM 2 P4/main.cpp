#include "CKomplex.h"
#include <iostream>
#include <fstream>

using namespace std;

vector<CKomplex>  werte_einlesen(const char* dateiname)
{
	int i, N, idx;
	double re, im;
	vector<CKomplex> werte;
	// File oeffnen
	ifstream fp;
	fp.open(dateiname);
	// Dimension einlesen
	fp >> N;
	// Werte-Vektor anlegen
	werte.resize(N);
	CKomplex null(0, 0);
	for (i = 0; i < N; i++)
		werte[i] = null;
	// Eintraege einlesen und im Werte-Vektor ablegen
	while (!fp.eof())
	{
		fp >> idx >> re >> im;
		CKomplex a(re, im);
		werte[idx] = a;
	}
	// File schliessen
	fp.close();

	return werte;
}

void werte_ausgeben(const char* dateiname, vector<CKomplex> werte, double epsilon = -1.0)
{
	int i;
	int N = werte.size();
	// File oeffnen
	ofstream fp;
	fp.open(dateiname);
	// Dimension in das File schreiben
	fp << N << endl;
	// Eintraege in das File schreiben
	fp.precision(10);
	for (i = 0; i < N; i++)
		if (werte[i].abs() > epsilon)
			fp << i << "\t" << werte[i].getrealteil() << "\t" << werte[i].getimaginaerteil() << endl;
	// File schliessen
	fp.close();
}

vector<CKomplex> Transformation(vector<CKomplex> f, bool transformation) {
	int N = f.size();
	vector<CKomplex> cn;
	cn.resize(N);
	int n = 0;
	if (transformation) {
		if (n >= 0) {
			while (n < N) {
				CKomplex sum;
				for (int k = 0; k < N; k++) {
					CKomplex efunc(-(2 * M_PI * k * n) / N);
					sum = sum + (f[k] * efunc);
				}
				cn[n] = sum * (1 / sqrt(N));
				n++;
			}
		}
	}
	else {
		while (n < N) {
			CKomplex sum;
			for (int k = 0; k < N; k++) {
				CKomplex efunc((2 * M_PI * k * n) / N);
				sum = sum + (f[k] * efunc);
			}
			cn[n] = sum * (1 / sqrt(N));
			n++;
		}
	}
	return cn;
}

double abw(vector<CKomplex> vec, vector<CKomplex> vec2) {
	double abweichung = 0.0;
	double maxdiff = 0.0;
	for (int i = 0; i < vec.size(); i++) {
		abweichung = (vec2[i] - vec[i]).abs();
		if (abweichung > maxdiff) 
			maxdiff = abweichung;
	}
	return maxdiff;
}

int main() {

	bool hin_transformation = true;
	werte_ausgeben("hin_transformiert_-1.txt", Transformation(werte_einlesen("Daten_original.txt"), hin_transformation));
	werte_ausgeben("hin_transformiert_1.txt", Transformation(werte_einlesen("Daten_original.txt"), hin_transformation), 1.0);
	werte_ausgeben("hin_transformiert_0.1.txt", Transformation(werte_einlesen("Daten_original.txt"), hin_transformation), 0.1);
	werte_ausgeben("hin_transformiert_0.01.txt", Transformation(werte_einlesen("Daten_original.txt"), hin_transformation), 0.01);
	werte_ausgeben("hin_transformiert_0.001.txt", Transformation(werte_einlesen("Daten_original.txt"), hin_transformation), 0.001);

	bool rueck_transformation = false;
	vector<CKomplex> daten;
	daten = werte_einlesen("Daten_original.txt");
	vector<CKomplex> epsilon_default; 
	epsilon_default = Transformation(werte_einlesen("hin_transformiert_-1.txt"), rueck_transformation);
	vector<CKomplex> epsilon_1; 
	epsilon_1 = Transformation(werte_einlesen("hin_transformiert_1.txt"), rueck_transformation);
	vector<CKomplex> epsilon_01; 
	epsilon_01 = Transformation(werte_einlesen("hin_transformiert_0.1.txt"), rueck_transformation);
	vector<CKomplex> epsilon_001; 
	epsilon_001 = Transformation(werte_einlesen("hin_transformiert_0.01.txt"), rueck_transformation);
	vector<CKomplex> epsilon_0001; 
	epsilon_0001 = Transformation(werte_einlesen("hin_transformiert_0.001.txt"), rueck_transformation);

	cout << "Maximale Abweichung bei Standard-Epsilon : ca. " << abw(epsilon_default, daten) << endl;
	cout << "Maximale Abweichung bei epsilon = 0.001: " << abw(epsilon_0001, daten) << endl;
	cout << "Maximale Abweichung bei epsilon = 0.01: " << abw(epsilon_001, daten) << endl;
	cout << "Maximale Abweichung bei epsilon = 0.1: " << abw(epsilon_01, daten) << endl;
	cout << "Maximale Abweichung bei epsilon = 1: " << abw(epsilon_1, daten) << endl;

	cout << endl;
	system("pause");
	return 0;
}