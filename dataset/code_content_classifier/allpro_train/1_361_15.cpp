#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

typedef long long LL;
typedef pair<double, double> P;

const double pi = acos(-1);
const int INF = 0x3f3f3f3f;
const double eps = 1e-10;
const int MAX = 2000;
const int mod = 1e9 + 7;

int main() {
	//freopen("file.in", "r", stdin);
	//freopen("file.out", "w", stdout);
	int T; scanf("%d", &T);
	while (T--) {
		LL a, b; scanf("%lld %lld", &a, &b);
		a = a * a;
		LL k = 0;
		while (2 * k * k <= a) k += b;
		k -= b;
		if ((k + b) * (k + b) + k * k <= a) printf("Ashish\n");
		else printf("Utkarsh\n");
	}
	return 0;
}