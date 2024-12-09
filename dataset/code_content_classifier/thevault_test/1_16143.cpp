void tabKopia(Zadanie tab1[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN], Zadanie tab2[MAX_LICZBA_ZADAN][MAX_LICZBA_MASZYN], 
int l_zadan, int l_maszyn) {
	for (int i = 0; i < l_zadan; i++)
		for (int j = 0; j < l_maszyn; j++) {
			tab2[i][j].numer_zadania = tab1[i][j].numer_zadania;
			tab2[i][j].czas_trwania = tab1[i][j].czas_trwania;
		}
}