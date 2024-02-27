/** @file */

/** @class Luk
*	@brief Klasa definiujaca luk grafu, jego pola prywatne oraz metody publiczne.
*/
class Luk {
private:
	Wierzcholek* zrodlo; /**< Pole prywatne oznaczajace zrodlo luku. */
	Wierzcholek* cel; /**< Pole prywatne oznaczajace cel luku. */
	int waga; /**< Pole prywatne oznaczajace wage luku. */
	friend class Graf;
public:
	/** @brief Konstruktor klasy Luk.
	* 
	* Inicjalzuje nowy obiek klasy Luk z okreslonymi parametrami.
	* 
	* @param zrodlo Wierzcholek grafu bedacy zrodlem luku.
	* @param cel Wierzcholek grafu bedacy celem luku.
	* @param waga Waga danego luku.
	*/
	Luk(Wierzcholek* zrodlo, Wierzcholek* cel, int waga);
	/** @brief Metoda zwracajaca zrodlo luku.
	* 
	* Funkcja zwraca wskaznik do wierzcholka grafu bedacego zrodlem danego luku.
	* 
	* @return Wskaznik do zrodla luku.
	*/
	Wierzcholek* getZrodlo() const;
	/** @brief Metoda zwracajaca cel luku.
	* 
	* Funkcja zwraca wskaznik do wierzcholka grafu bedacego celem danego luku.
	* 
	* @return Wskaznik do celu luku.
	*/
	Wierzcholek* getCel() const;
	/** @brief Metoda zwracajaca wage luku.
	* 
	* Funkcja zwraca wage danego luku.
	* 
	* @return Waga luku.
	*/
	int getWaga() const;
};