#include <iostream>
#include <utility>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <climits>
#include <numeric>
#include<stdio.h>
#include <queue>
#include <iomanip>
#include <float.h>
#include <set>
#include<functional>
#include <stack>
#include <time.h>
#include <climits>
#include <bitset>
#include <fstream>
#include <stdlib.h>
using namespace std;
long long modinv(long long a, long long m) {
	long long b = m, u = 1, v = 0;
	while (b) {
		long long t = a / b;
		a -= t * b; swap(a, b);
		u -= t * v; swap(u, v);
	}
	u %= m;
	if (u < 0) u += m;
	return u;
}
typedef pair<int, int> p;
vector< int64_t > divisor(int64_t n) {
	vector< int64_t > ret;
	for (int64_t i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			ret.push_back(i);
			if (i * i != n) ret.push_back(n / i);
		}
	}
	sort(begin(ret), end(ret));
	return (ret);
}
long long mod = 1e9 + 7;
string xo (string s, string t) {
	string ans = "";
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == t[i])ans += '0';
		else ans += '1';
	}
	return ans;
}
char xorr(char s, char t) {
	if (s == t)return '0';
	else return '1';
}
int num[30][500];
int main(int argc, char* argv[]) {
	srand(100);
	for (int i = 0; i < 30; i++) {
		set<int>s;
		while (s.size() < 500) {
			s.insert(rand() % 1000);
		}
		int j = 0;
		for (auto itr = s.begin(); itr != s.end(); itr++) {
			num[i][j++] = *itr;
		}
	}
	string s;
	cin >> s;
	if (s != "Charlie") {
		string ans = "";
		string tmp;
		for (int i = 0; i < 100; i++) {
			cin >> tmp;
			for (int j = 0; j < 30; j++) {
				char c = '0';
				for (int k = 0; k < 500; k++) {
					char x = tmp[num[j][k]];
					c = xorr(c, x);
				}
				ans += c;
			}
		}
		cout << ans;
	}
	else {
		map<string, p>ma;
		string a[100];
		string b[100];
		string x, y;
		cin >> x >> y;
		for (int i = 0; i < 100; i++) {
			a[i] = x.substr(i * 30, 30);
			b[i] = y.substr(i * 30, 30);
		}
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				string tmp = xo(a[i], b[j]);
				ma[tmp] = p(i + 1, j + 1);
			}
		}
		string cc;
		for (int i = 0; i < 100; i++) {
			cin >> cc;
			string str = "";
			for (int j = 0; j < 30; j++) {
				char c = '0';
				for (int k = 0; k < 500; k++) {
					char x = cc[num[j][k]];
					c = xorr(c, x);
				}
				str += c;
			}
			auto pr = ma.find(str)->second;
			cout << pr.first << " " << pr.second << "\n";
		}
	}
}

