void PrintParagraph(string text, int max_width) {
	vector<string>* spl = Split(text);
	for (int r = 0, w = 0; r < spl->size(); ++r) {
		if (w + (*spl)[r].length() >= max_width) {
			cout << endl;
			cout << (*spl)[r];
			w = (*spl)[r].length();
		}
		else {
			if (r == 0) {
				cout << (*spl)[r];
				w += (*spl)[r].length();
			}
			else {
				cout << " " << (*spl)[r];
				w += (*spl)[r].length() + 1;
			}
		}
	}
	delete spl;
}