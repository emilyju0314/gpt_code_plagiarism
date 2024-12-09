bool wczytaj(vector<Zadanie> &wektor) {
	Zadanie noweZadanie;	// zmienna pomocnicza do wczytywania zadan
	fstream PlikDanych;	// strumien plikowy - udostepnia plik z danymi
	int r, p, q, n;	
	char nazwa[32];
	cout << endl << "Podaj nazwe pliku z danymi: ";	// pobranie nazwy pliku od uzytkownika
	scanf("%s",nazwa); 
	if (!plikIstnieje(nazwa)) {		// zabezpieczenie przed bledna nazwa pliku
		cout << "Bledna nazwa pliku." << endl;
		return false;
	}
	PlikDanych.open(nazwa,ios::in);		// otwarcie pliku z danymi w trybie do odczytu
	PlikDanych >> n;
	cout << endl << "Wczytuje " << n << " danych" << endl;
	for (int i = 0; i < n; i++) {		// wrzucanie kolejnych zadan do wektora
		PlikDanych >> r;
		PlikDanych >> p;
		PlikDanych >> q;
		wektor.push_back(Zadanie(r,p,q));
	}
	PlikDanych.close();		// zamkniecie strumienia plikowego
	return true;
}