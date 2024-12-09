#include <bits/stdc++.h>
using namespace std;
int C[26];

int main()
{
	int N, K, res = 0;
	string P;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> P;
		C[P[0] - 'A']++;
	}
	for (int i = 0; i < N; i++) {
		int var = 0;
		sort(C, C + 26, greater<int>());
		for (int j = 0; j < 26; j++) {
			if (C[j]) {
				C[j]--;
				var++;
				if (var == K) {
					res++;
					break;
				}
			}
		}
		if (var != K) {
			break;
		}
	}
	cout << res << endl;
	return 0;
}
