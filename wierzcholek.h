/** @file */
class Luk;
/** @class Wierzcholek
*	@brief Klasa definiujaca wierzcholek grafu, jego pola prywatne oraz metody.
*/
class Wierzcholek {
private:
	std::string nazwa; /**< Pole prywatne okreslajace nazwe wierzcholka. */
	int indeks; /**< Pole prywatne okreslajace indeks wierzcholka. */
	std::vector<Luk*> nastepniki; /**< Pole prywatne okreslajace zbior lukow laczacych dany wierzcholek z nastepnymi. */
	std::vector<Luk*> poprzedniki; /**< Pole prywatne okreslajace zbior lukow laczacych dany wierzcholek z poprzednimi. */
	friend class Graf;
public:
	/** @brief Konstruktor klasy Wierzcholek
	* 
	* Inicjalizuje nowy obiekt klasy Wierzcholek z okreslonymi parametrami.
	* 
	* @param indeks Indeks danego wierzcholka w grafie.
	* @param nazwa Nazwa danego wierzcholka.
	*/
	Wierzcholek(int indeks, const std::string& nazwa);
	/** @brief Metoda ustawiajaca wartosc pola nazwa.
	* 
	* Funkcja ustawia wartosc prywatnego pola nazwa na podany argument.
	* 
	* @param nazwa Podana nazwa wierzcholka.
	* @return void
	*/
	void setNazwa(const std::string& nazwa);
	/** @brief Metoda zwracajaca nazwe wierzcholka.
	* 
	* Funkcja zwraca nazwe danego wierzcholka.
	* 
	* @return Nazwa wierzcholka.
	*/
	const std::string& getNazwa() const;
	/** @brief Metoda zwracajaca indeks wierzcholka.
	* 
	* Funkcja zwraca przypisany indeks wierzcholka w grafie.
	* 
	* @return Indeks wierzcholka.
	*/
	int getIndeks() const;
	/** @brief Destruktor klasy Wierzcholek.
	* 
	* Funkcja zwalnia zasoby zwiazane z obiektem klasy.
	*/
	~Wierzcholek();
};