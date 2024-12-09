void TopologicalSort (int x) {
	if ((c == 'd') && (m <= n)) {
		DFS(x);
		cout << "Topological Sort gives:" << endl;
		for (int i = 0; i < n; i++) {
			cout << Stack.back() << "\t";
			Stack.pop_back();
		}
		cout << endl;
	} else {
		if (c != 'd') {
			cout << "Topological Sort cannot be performed as it is an undirected graph." << endl;
		} else {
			cout << "Topological Sort cannot be performed as the graph has cycles." << endl;
		}
	}
}