#include <iostream>
#include "CZufall.h"
#include "CLotto.h"

using namespace std;

void Monte_Carlo(int r, int k, int n, int N, bool Spieler) {
	CLotto Schein(n, k, rand());                      // Schein erstellen
	vector<int> tippzettel = Schein.Lotto_Ziehen();   //tippzettel erstellen
	Schein.set_tippzettel(tippzettel);
	int anzrichtige = 0;
	int richtige = 0;
	for (int i = 1; i <= N; i++) {     //Spieler 1
		if (Spieler) {
			richtige = Schein.Lotto_durchführen();     // schein mit tippzettel vergleichen
		}
		else {
			tippzettel = Schein.Lotto_Ziehen();
			Schein.set_tippzettel(tippzettel);         // tippzettel zum Schein
			richtige = Schein.Lotto_durchführen();     // schein mit tippzettel vergleichen
		}
		if (richtige == r) {                                        
			anzrichtige++;
		}
	}
	double wahrscheinlichkeit = (double(anzrichtige) / double(N)) * 100;
	cout << "Wahrscheinlichkeit von " << wahrscheinlichkeit << " % bei " <<
		k << " aus " << n << " mit " << N << " Ziehungen bei genau " << r << " Richtige.\n";
}

int main() {

	Monte_Carlo(3, 5, 27, 10000000, true);
	Monte_Carlo(3, 5, 27, 10000000, false);

	cout << endl;
	system("pause");
	return 0;
}