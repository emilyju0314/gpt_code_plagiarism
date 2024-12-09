void bubbleSort(int iloscDanych, vector<Zadanie> &wektor) {
	Zadanie pom;
	while(!czyPorzadek(iloscDanych,wektor)) {
		for (int i=0; i < iloscDanych-1; i++)
			if (wektor[i]._r > wektor[i+1]._r) {
				pom = wektor[i];
				wektor[i] = wektor[i+1];
				wektor[i+1] = pom;
			}
	}
}