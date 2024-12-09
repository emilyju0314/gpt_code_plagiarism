#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
constexpr int di[] = { 0, 1, 0, -1 }, dj[] = { 1, 0, -1, 0 };
#define rep(i, n) for (int i = 0; i < n; i++)
#define repr(i, n) for (int i = n; i >= 0; i--)
#define sort(v) sort((v).begin(), (v).end())
#define sortr(v) sort((v).rbegin(), (v).rend())
#define all(v) (v).begin(), (v).end()
#define max 100005
#define nil -1

int main() {
	int  n,m=0,b=0;
	cin >> n;
	vector<int> a(n, 0);
	rep(i, n) {
		cin >> a[i];
		m += a[i];
	}
	if (m % 2 == 0) {
		cout << m / 2 << endl;
	}
	else {
		sort(a);
		rep(i, n) {
			if (a[i] % 2 != 0) {
				b = a[i];
				break;
			}
		}
		cout << (m - b) / 2 << endl;
	}
	return 0;
}
