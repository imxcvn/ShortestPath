/** @file */

/** @class Zapytanie
*	@brief Klasa definiujaca strukture przechowywujaca informacje o ktore zostal zapytany uzytkownik.
*/
class Zapytanie {
private:
	std::string zrodlo; /**< Pole prywatne oznaczajace nazwe zrodla podana przez uzytkownika. */
	std::string cel; /**< Pole prywatne oznaczajace nazwe celu podana przez uzytkownika. */
public:
	/** @brief Konstruktor bezargumentowy klasy Zapytanie.
	* 
	* Inicjalizuje nowy obiekt klasy Zapytanie.
	*/
	Zapytanie();
	/** @brief Konstruktor klasy Zapytanie.
	* 
	* Inicjalizuje nowy obiekt klasy Zapytanie z okreslonymi parametrami.
	* 
	* @param nazwa1 Nazwa zrodla.
	* @param nazwa2 Nazwa celu.
	*/
	Zapytanie(const std::string& nazwa1, const std::string& nazwa2);
	/** @brief Metoda zwracajaca nazwe zrodla.
	* 
	* Funkcja zwraca nazwe zrodla podana przez uzytkownika.
	* 
	* @return Nazwa zrodla.
	*/
	const std::string& getZrodlo() const;
	/** @brief Metoda zwracajaca nazwe celu.
	* 
	* Funkcja zwraca nazwe celu podana przez uzytkownika.
	* 
	* @return Nazwa celu.
	*/
	const std::string& getCel() const;
	/** @brief Metoda ustawiajaca wartosc pola zrodlo.
	* 
	* Funkcja ustawia wartosc prywatnego pola zrodlo na podany argument.
	* 
	* @param zrodlo Podana nazwa zrodla.
	* @return void
	*/
	void setZrodlo(const std::string& zrodlo);
	/** @brief Metoda ustawiajaca wartosc pola cel.
	* 
	* Funkcja ustawia wartosc prywatnego pola cel na podany argument.
	* 
	* @param cel Podana nazwa celu.
	* @return void
	*/
	void setCel(const std::string& cel);
};