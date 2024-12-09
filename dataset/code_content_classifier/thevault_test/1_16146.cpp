void sortowanie(vector<Zadanie> &wektor, int start, int stop, int typ) {
	if (typ == 1)
		sort(wektor.begin()+start,wektor.begin()+stop,porownajR);
	else 
		sort(wektor.begin()+start,wektor.begin()+stop,porownajQ);
}