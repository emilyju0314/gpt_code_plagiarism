#include"bits/stdc++.h"
using namespace std;

int main() {
	int A, B, C;
	cin >> A >> B >> C;
	cout << (min(A, B) <= C && C <= max(A, B) ? "Yes" : "No") << endl;
	return 0;
}