/** @file */
#include "includes.h"

Wierzcholek::Wierzcholek(int indeks, const std::string& nazwa) {
	this->indeks = indeks;
	this->nazwa = nazwa;
}

void Wierzcholek::setNazwa(const std::string& nazwa) {
	this->nazwa = nazwa;
}

const std::string& Wierzcholek::getNazwa() const {
	return this->nazwa;
}

int Wierzcholek::getIndeks() const {
	return this->indeks;
}

Wierzcholek::~Wierzcholek() {
	for (int i = 0; i < nastepniki.size(); i++) {
		delete nastepniki[i];                   
	}
}