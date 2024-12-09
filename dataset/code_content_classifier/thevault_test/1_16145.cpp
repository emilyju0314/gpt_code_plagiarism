bool czyWszystkie(vector<Zadanie> wektor) {
	for (int i = 0; i < wektor.size(); i++)
		if (!wektor[i]._done)
			return false;
	return true;
}