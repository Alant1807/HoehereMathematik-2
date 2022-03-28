#include "CZufall.h"

int CZufall::wert(int a, int b) { 
	return rand() % (b - a + 1) + a; 
}

std::vector<int> CZufall::test(int a, int b, int N) {
	std::vector<int> zufallszahl;
	zufallszahl.assign((double(b) - a) + 1, 0);
	for (int i = 0; i < N; i++)
		zufallszahl[wert(a, b) - double(a)]++;
	return zufallszahl;
}

std::vector<int> CZufall::testfalsch(int a, int b, int N) {
	std::vector<int> zufallszahl;
	zufallszahl.assign((double(b) - a) + 1, 0);
	for (int i = 0; i < N; i++) {
		initialisiere(time(NULL));
		zufallszahl[wert(a, b) - double(a)]++;
	}
	return zufallszahl;
}
