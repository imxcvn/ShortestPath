/** @file */
#include "includes.h"

Luk::Luk(Wierzcholek* zrodlo, Wierzcholek* cel, int waga) {
	this->zrodlo = zrodlo;
	this->cel = cel;
	this->waga = waga;
}

Wierzcholek* Luk::getZrodlo() const {
	return this->zrodlo;
}

Wierzcholek* Luk::getCel() const {
	return this->cel;
}

int Luk::getWaga() const {
	return this->waga;
}