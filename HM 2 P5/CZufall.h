#pragma once
#include <stdlib.h>
#include <time.h>
#include <vector>

class CZufall {
public:
	CZufall() { initialisiere(0); }
	CZufall(int s) { initialisiere(s); }
	static int wert(int a, int b);
	void initialisiere(int s) { srand(s); }
	std::vector<int> test(int a, int b, int N);
	std::vector<int> testfalsch(int a, int b, int N);
};
