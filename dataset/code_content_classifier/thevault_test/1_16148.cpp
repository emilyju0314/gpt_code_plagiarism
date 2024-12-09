int schrage(vector<Zadanie> &wektor) {
	int czas, start, stop;			// zmienne przechowujace obecny czas oraz pomocnicze indeksy do zakresu sortowania
	sortowanie(wektor,0,wektor.size(),1);		// sortowanie zadan wg R
	for (int i = 1; i < wektor.size(); i++) {		
		int j = i;
		while (wektor[i-1]._r == wektor[i]._r)	// wyznaczanie zakresow wg R, przeznaczonych do sortowania wg Q
			i++;
		sortowanie(wektor,j,i,2);		// sortowanie wg Q
	}
	wektor[0]._k = wektor[0]._s + wektor[0]._p;	// wykonanie pierwszego zadania z posortowanej listy
	czas = wektor[0]._k;				// ustawienie czasu na koniec pierwszego zadania
	wektor[0]._done = true;
	wektor[0]._ready = true;
	wektor[0]._f = wektor[0]._k + wektor[0]._q;
	start = 1; 					// indeks pomocniczy uzywany do przechodzenia po kolejnych zadaniach
	while (!czyWszystkie(wektor)) {			// petle wykonujemy dopoki wszystkie zadania nie zostana wykonane
		stop = -1;				// indeks pomocniczy do sortowan
		for (int i = start; i < wektor.size(); i++)
			if (wektor[i]._r <= czas) {
				wektor[i]._ready = true;
				stop = i+1;		// wyznaczanie indeksu ostatniego gotowego zadania
			}
		if (wektor[start]._ready) {			// jesli najblizsze zadanie jest juz gotowe to je wykonujemy
			sortowanie(wektor,start,stop,2);	// sortowanie obecnie dostepnych zadan
			if (wektor[start]._r > wektor[start-1]._k)	// wykonanie najswiezszego (po sortowaniu - indeks bez zmian) zadania
				wektor[start]._s = wektor[start]._r;
			else
				wektor[start]._s = wektor[start-1]._k;
			wektor[start]._k = wektor[start]._s + wektor[start]._p;
			wektor[start]._done = true;
			wektor[start]._f = wektor[start]._k + wektor[start]._q;	// wyznaczenie faktycznego czasu dostarczenia zadania
		}	
		if (!wektor[start]._ready)		// jesli najblizsze zadanie nie jest jeszcze gotowe to czas rosnie o jeden
			czas++;
		else {
			czas = wektor[start]._k;	// jesli zadanie zostalo wykonane, to obecny czas = koniec zadania i zwiekszamy indeks
			start++;
		}
	}
	int wynik = czas;		// koncowy czas pierwszej czesci algorytmu - czas zakonczenia ostatniego z zadan
	for (int i = 0; i < wektor.size(); i++)	// szukamy czasu dostarczenia ktory moglby wydluzyc koncowy czas
		if (wektor[i]._f > wynik)
			wynik = wektor[i]._f;
	return wynik;		// zwracamy finalny czas
}