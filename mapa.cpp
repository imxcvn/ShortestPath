/** @file */
#include <iostream>
#include "includes.h"

std::vector<Zapytanie> wczytajZapytania(const std::string& nazwa) {
	std::vector<Zapytanie> w;
	std::ifstream plikWej{ nazwa };
	if (plikWej.is_open()) {
		
		while (true) {
			std::string miasto1;
			std::string miasto2;
			plikWej >> miasto1 >> miasto2;
			if (!plikWej) {
				break;
			}
			w.push_back(Zapytanie{ miasto1, miasto2 });
		}
		plikWej.close();
		
	}
	else
		std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
	return w;
}

int main()
{
	Graf graf;

	graf.wczytaj("plikWejsciowy1.txt");

	//graf.wypisz();

	std::vector<Zapytanie> w = wczytajZapytania("plikWejsciowy2.txt");
	/*for (int i = 0; i < w.size(); i++) {
		std::cout << w[i].getZrodlo() << " " << w[i].getCel() << std::endl;
	}
	*/

	try {
		Wynik wynik;
		for (int i = 0; i < w.size(); i++) {
			wynik = graf.Dijkstra(w[i].getZrodlo(), w[i].getCel());
			std::cout << "Z " << w[i].getZrodlo() << " do " << w[i].getCel() << " -> " << wynik.waga << "." << std::endl;
			for (int j = 0; j < wynik.sciezka.size(); j++) {
				std::cout << wynik.sciezka[j]->getNazwa();

				if (j < wynik.sciezka.size() - 1) {

					std::cout << ", ";
				}
				else {

					std::cout << ".";
					std::cout << std::endl;
				}
			}
		}
	}
	catch (std::exception e) {
		std::cout << e.what() << std::endl;
	}


 }

