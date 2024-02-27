/** @file */

/** @class Graf
*	@brief Klasa definiujaca graf, jego pola prywatne oraz metody.
*/
class Graf {
private:
	std::vector<Wierzcholek*> wierzcholki; /**< Pole prywatne oznaczajace zbior wierzcholkow tworzacych graf. */
	std::map<std::string, Wierzcholek*> mapa; /**< Pole prywatne oznaczajce mape zawierajaca wierzcholki gradu oraz odpowiadajace im nazwy. */
public:
	/** @brief Metoda dodajaca nowy wierzcholek.
	* 
	* Funkcja tworzy nowy wierzcholek o podanej nazwie, przypisuje mu indeks oraz dodaje go do kontenerow zawierajacych wierzcholki grafu: mapa oraz wierzcholki.
	* 
	* @param nazwaWierzcholka Nazwa wieracholka, ktora ma zostac dodany do grafu.
	* @return void
	*/
	void dodajWierzcholek(const std::string& nazwaWierzcholka);
	/** @brief Metoda laczaca wierzcholki grafu.
	* 
	* Funkcja na poczatku sprawdza czy podane wierzcholki naleza juz do mapy grafu, jezeli nie to wywolywana jest funkcja, ktora dodaje
	* je do tych kontenerow. Nastepnie tworzone sa wskazniki na laczone wierzcholki oraz luk, ktory je laczy. Stworzony luk jest dodawany
	* do poprzednikow wierzcholka bedacego celem oraz do nastepnikow wierzcholka bedacego zrodlem.
	* 
	* @param zrodlo Nazwa wierzcholka bedacego zrodlem.
	* @param cel Nazwa wierzcholka bedacego celem.
	* @param waga Waga luku laczacego zrodlo z celem.
	* @return void
	*/
	void polacz(const std::string& zrodlo, const std::string& cel, int waga);
	/** @brief Metoda wypisujaca graf.
	* 
	* Funkcja wypisuje wszytskie wierzcholki grafu oraz ich nastepniki i poprzedniki razem z wagami tych lukow.
	* 
	* @return void
	*/
	void wypisz();
	/** @brief Metoda wczytujaca wierzcholki grafu oraz wagi lukow, ktore je lacza.
	* 
	* Funkcja wczytuje nazwy wierzcholkow oraz wagi laczacych ich lukow. Nastepnie wywolywana jest funkcja laczaca te wierzcholki.
	* 
	* @param nazwa Nazwa pliku, z ktorego wczytywane sa informacje.
	* @return void
	*/
	void wczytaj(const std::string& nazwa);
	/** @brief Metoda wykonujaca algorytm Dijkstry w grafie
	* 
	* Metoda szuka najkrotszej sciezki pomiedzy dwoma wierzcholkami w grafie skierowanym za pomoca algorytmu Dijkstry.
	* 
	* @param poczatek Nazwa wierzcholka bedacego poczatkiem drogi.
	* @param koniec Nazwa wierzcholka bedacego koncem drogi.
	* @return Wynik algorytmu Dijkstry, zawierajacy znaleziona sciezke i jej wage.
	* @throw std:exception Jezeli nie istnieje sciezka pomiedzy podanymi wierzcholkami.
	*/
	Wynik Dijkstra(const std::string& poczatek, const std::string& koniec);
	/** @brief Destruktor klasy Graf.
	* 
	* Funkcja zwalnia zasoby zwiazane z obiektem klasy.
	*/
	~Graf();
};

