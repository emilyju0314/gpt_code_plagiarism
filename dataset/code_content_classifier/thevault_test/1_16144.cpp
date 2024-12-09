void ZadanieKopia(Zadanie tab[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN],Zadanie ZAD[1][MAX_LICZBA_MASZYN],int l_maszyn,int numer) {
	for (int j = 0; j < l_maszyn; j++) {
		ZAD[0][j].numer_zadania = tab[numer][j].numer_zadania;
		ZAD[0][j].czas_trwania = tab[numer][j].czas_trwania;
	}
}