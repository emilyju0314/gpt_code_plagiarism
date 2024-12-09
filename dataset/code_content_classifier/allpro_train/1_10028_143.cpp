#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N, M;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> M;
	cout << abs(N*M - (N+N+M+M-4)) << "\n";

}