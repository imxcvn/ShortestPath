/** @file */
#include "includes.h"

Zapytanie::Zapytanie() {

}

Zapytanie::Zapytanie(const std::string& nazwa1, const std::string& nazwa2) {
	this->zrodlo = nazwa1;
	this->cel = nazwa2;
}

const std::string& Zapytanie::getZrodlo() const {
	return this->zrodlo;
}

const std::string& Zapytanie::getCel() const {
	return this->cel;
}

void Zapytanie::setZrodlo(const std::string& zrodlo) {
	this->zrodlo = zrodlo;
}

void Zapytanie::setCel(const std::string& cel) {
	this->cel = cel;
}