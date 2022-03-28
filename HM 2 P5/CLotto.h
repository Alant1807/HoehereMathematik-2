#pragma once
#include "CZufall.h"

class CLotto {
public:
	CLotto(int n, int k, int s);
	void set_tippzettel(std::vector<int> tippzettel) { this->tippzettel = tippzettel; };
	std::vector<int> get_tippzettel() const { return this->tippzettel; }
	std::vector<int> Lotto_Ziehen();
	int Lotto_durchführen();
private:
	int k, n;
	std::vector<int> tippzettel;
};
