void PrintCentered(string text, int lineWidth) {
	if (text.length() > lineWidth) {
		cout << text.substr(0, lineWidth);
		return;
	}
	int offset = (lineWidth / 2) - (text.length() / 2);
	cout << generate_repitition(offset, ' ');
	cout << text;
	cout << endl;
}