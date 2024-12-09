#include <iostream>
#include <cstdio>
using namespace std;

int k, n, s;
string a;

int C(int p, int q) {
	int i, re = 1;
	if (p < q || q < 0) return 0;
	for (i = p; i > p - q; i--) re *= i;
	for (i = q; i > 1; i--) re /= i;
	return re;
}

int pow(int p) {
	int re = 1;
	while (p > 0) re *= 9, p--;
	return re;
}

int main()
{
	int i;
	cin >> a >> k;
	n = a.size();
	for (i = 0; i < n && k >= 0; i++) {
		if (a[i] > '0') {
			s += C(n - i - 1, k) * pow(k) + (a[i] - '1') * C(n - i - 1, k - 1) * pow(k - 1);
			k--;
		}
	}
	if (k == 0) s++;
    cout << s << endl;
    return 0;
}