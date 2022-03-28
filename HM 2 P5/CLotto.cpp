#include "CLotto.h"
#include <iostream>

CLotto::CLotto(int n, int k, int s) {
	CZufall random;
	this->n = n;
	this->k = k;
	if (s < 0)
		random.initialisiere(time(NULL));
	else
		random.initialisiere(s);
}

std::vector<int> CLotto::Lotto_Ziehen() {
	std::vector<int> res;
	int i = 0;
	while (i < k) {                                      // k mal Ziehungen 
		int randomnumber = CZufall::wert(1, this->n);    
		auto it = res.begin();
		while (it != res.end()) {          // gehe Tippzettel durch
			if (*it == randomnumber)       // wenn Duplikat gefunden break
				break;
			it++;
		}
		if (it == res.end()) {             // kein Duplikat gefunden pushe wert in vektor rein
			res.push_back(randomnumber);
			i++;
		}
	}
	return res;
}

int CLotto::Lotto_durchführen() {
	std::vector<int> vec = this->Lotto_Ziehen();
	int counter = 0;
	for (auto it = tippzettel.begin(); it != tippzettel.end(); it++) {
		auto find = vec.begin();
		while (find != vec.end()) {
			if (*find == *it)
				counter++;
			find++;
		}
	}
	return counter;
}
