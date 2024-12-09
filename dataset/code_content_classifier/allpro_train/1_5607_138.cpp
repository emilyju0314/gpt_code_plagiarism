//HovalHaq!
#include <bits/stdc++.h>
using namespace std;

int main() {
	string S; cin >> S;
	int r = 0;
	for(int i = 0; i * 2 < S.size(); i++) if(S[i] != S[S.size() - i - 1]) r++;
	cout << r;
}
