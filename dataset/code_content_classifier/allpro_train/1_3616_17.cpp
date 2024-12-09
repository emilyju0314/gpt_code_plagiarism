#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<tuple<string,int,int>>P; 
	for (int n = 0; n < N; ++n) {
		string S;
		int p;
		cin >> S >> p;
		P.emplace_back(S,-p,n + 1);
	}	
	sort(P.begin(),P.end());
	for (int n = 0; n < N; ++n) {
		cout << get<2>(P[n]) <<endl;

	}
	return 0;
}