void printInputPlot2(vector<double>& x, vector<double>& y, int cols,
		int crepeat, int rows) {
	vector<double> empty;
	printInputPlot(x, empty, cols, crepeat, rows);
	printInputPlot(empty, y, cols, crepeat, rows);
}