int wczytaj(char *nazwa, Zadanie tab[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN]) {
	int i;
	fstream plik;
	int n = -1;
	if (!plikIstnieje(nazwa)) {
		cout << "Bledna nazwa pliku." << endl;
		return n;
	}
	plik.open(nazwa,ios::in);
	plik >> n >> l_maszyn;
	l_zadan = n;
      	for (i = 0; i < l_zadan; i++) 
		for (int j = 0; j < l_maszyn; j++) {
			tab[i][j].numer_zadania = i+1;
			plik >> tab[i][j].czas_trwania;
		}
	cout << "Wczytano " << n << " danych." << endl;
	plik.close();	
	return n;
}