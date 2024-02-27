/** @file */

/** @class Wynik
*	@brief Klasa definiujaca strukture przechowywujaca informacje wyniku.
*/
class Wynik {
public:
	std::vector<Wierzcholek*> sciezka; /**< Pole publiczne okreslajace vector zawierajacy wszystkie wierzcholki wyniku. */
	int waga; /**< Pole publiczne okreslajace wage wyniku. */
};