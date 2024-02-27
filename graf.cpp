/** @file */
#include "includes.h"

void Graf::dodajWierzcholek(const std::string& nazwaWierzcholka) {
	Wierzcholek* nowyWierzcholek = new Wierzcholek{ (int)wierzcholki.size(),nazwaWierzcholka }; 
	wierzcholki.push_back(nowyWierzcholek);
	mapa[nazwaWierzcholka] = nowyWierzcholek;
}

void Graf::polacz(const std::string& zrodlo, const std::string& cel, int waga) {
	if (mapa.count(zrodlo) == 0) {
		dodajWierzcholek(zrodlo);
	}
	if (mapa.count(cel) == 0) {
		dodajWierzcholek(cel);
	}

	Wierzcholek* z = mapa.at(zrodlo);
	Wierzcholek* c = mapa.at(cel);
	Luk* nowyLuk = new Luk{ z, c, waga };
	z->nastepniki.push_back(nowyLuk);
	c->poprzedniki.push_back(nowyLuk);

}

void Graf::wypisz() {
	for (int i = 0; i < wierzcholki.size(); i++) {
		Wierzcholek* w = wierzcholki[i];
		std::cout << "Indeks: " << w->getIndeks() << " Nazwa: " << w->getNazwa() << std::endl;
		for (int j = 0; j < w->nastepniki.size(); j++) {
			Luk* l = w->nastepniki[j];
			std::cout << l->getCel()->getNazwa() << " " << l->getWaga() << ", ";
		}
		std::cout << std::endl;
		for (int k = 0; k < w->poprzedniki.size(); k++) {
			Luk* l = w->poprzedniki[k];
			std::cout << l->getZrodlo()->getNazwa() << " " << l->getWaga() << ", ";
		}
		std::cout << std::endl;
		std::cout << "----------" << std::endl;
	}
}

void Graf::wczytaj(const std::string& nazwa) {
	std::ifstream plikWej{ nazwa };
	if (plikWej.is_open()) {
		std::string miasto1;
		std::string miasto2;
		int waga;
		while (true) {
			plikWej >> miasto1 >> miasto2 >> waga;
			if (!plikWej) 
				break;
			polacz(miasto1, miasto2, waga);
		}
		plikWej.close();
	}
	else
		std::cout << "Nie udalo sie otworzyc pliku." << std::endl;
}

Wynik Graf::Dijkstra(const std::string& nazwaPoczatek, const std::string& nazwaKoniec) {
	Wierzcholek* poczatek = mapa.at(nazwaPoczatek);
	Wierzcholek* koniec = mapa.at(nazwaKoniec);
	int indeksPoczatek = poczatek->getIndeks();
	int indeksKoniec = koniec->getIndeks();

	std::vector<bool> wKolejce(wierzcholki.size());
	for (int i = 0; i < wKolejce.size(); i++) {
		wKolejce[i] = true;
	}

	std::vector<int> koszty(wierzcholki.size());
	for (int i = 0; i < koszty.size(); i++) {
		koszty[i] = std::numeric_limits<int>::max();
	}

	koszty[indeksPoczatek] = 0;

	std::vector<int> poprzednicy(wierzcholki.size());

	for (int i = 0; i < poprzednicy.size(); i++) {
		poprzednicy[i] = -1;
	}

	class ElementKolejki {
	public:
		int wierzcholek;
		int koszt;        
		ElementKolejki(int wierzcholek, int koszt) {
			this->wierzcholek = wierzcholek;
			this->koszt = koszt;
		}
		bool operator<(const ElementKolejki& e) const {  
			if (this->koszt > e.koszt) {
				return true;
			}
			return false;
		}
	};

	std::priority_queue<ElementKolejki> kolejka;
	kolejka.push({ indeksPoczatek, 0 });
	

	while (kolejka.empty() == false) {
		ElementKolejki e = kolejka.top();
		kolejka.pop();
		
		if (wKolejce[e.wierzcholek] == false) { 
			
			continue;    
		}
		if (e.wierzcholek == indeksKoniec)
			break;
		wKolejce[e.wierzcholek] = false;
		Wierzcholek* w = wierzcholki[e.wierzcholek];
		for (int i = 0; i < w->nastepniki.size(); i++) {
			Luk* luk = w->nastepniki[i];
			int suma = e.koszt + luk->getWaga();
			if (suma < koszty[luk->cel->indeks]) {
				koszty[luk->cel->indeks] = suma;
				poprzednicy[luk->cel->indeks] = e.wierzcholek;
				kolejka.push({ luk->cel->indeks, suma });
			}
		}
	}

	if (koszty[indeksKoniec] == std::numeric_limits<int>::max()) {
		throw std::exception("Nie ma sciezki do wybranego miasta.");
	}

	Wynik wynik;
	int obecny = indeksKoniec;
	while (obecny >= 0) {
		wynik.sciezka.push_back(wierzcholki[obecny]);
		obecny = poprzednicy[obecny];
	}

	std::reverse(wynik.sciezka.begin(), wynik.sciezka.end());
	wynik.waga = koszty[indeksKoniec];

	return wynik;
}

Graf::~Graf() {
	for (int i = 0; i < wierzcholki.size(); i++) {
		delete wierzcholki[i];
	}
}