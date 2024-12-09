bool czyPorzadek(int iloscDanych, vector<Zadanie> wektor) {
	for (int i = 0; i < iloscDanych-1; i++)
		if (wektor[i]._r > wektor[i+1]._r)
			return false;
	return true;
}