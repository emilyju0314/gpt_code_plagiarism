void Wstaw_przed(Zadanie ZAD[1][MAX_LICZBA_MASZYN], Zadanie tab[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN], 
int l_zadan, int l_maszyn, int numer_zadania) {
	// tworzenie miejsca w tablicy na nowe zadanie przez przesuwanie dalszych w prawo, nastepnie wstawienie zadania
	for (int i = l_zadan; i > numer_zadania; i--)
		for (int j = 0; j < l_maszyn; j++) {
			tab[i][j].czas_trwania = tab[i-1][j].czas_trwania;
			tab[i][j].numer_zadania = tab[i-1][j].numer_zadania;
		}
	for (int i = 0; i < l_maszyn; i++) {
		tab[numer_zadania][i].czas_trwania = ZAD[0][i].czas_trwania;
		tab[numer_zadania][i].numer_zadania = ZAD[0][i].numer_zadania;
	}
}