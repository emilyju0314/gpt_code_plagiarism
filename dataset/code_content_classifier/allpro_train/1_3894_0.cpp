#include "bits/stdc++.h"
using namespace std;
using ld = double;
const ld eps = 1e-9;

/*
?????????????????¨?????? FFT ???????????????
n?¬??????????g(x) = \sum_{i=0}^n a_i x^i , h(x) = \sum_{i=0}^n b_i x^i ???????????????
f(x) = (g*h)(x) = \sum_{k=0}^{2n} \sum_{i=0}^{k} a_i b_{k-i} x^k
???O(n log n)??§?±??????????

?????????:
g(x)????????°??? vector<T> g
h(x)????????°??? vector<T> h
??¨????????¨???
f = multiply(g, h);
??§f(x)????????°vector<T> f????±??????????

verified by: http://atc001.contest.atcoder.jp/tasks/fft_c
(AtCoder Typical Contest 001 C)

complex, vector, algorithm ?????????????????????????????????????????????
*/
#include<complex>
#include<vector>
#include<algorithm>
using namespace std;
const double PI = 3.141592653589793;
/*
*
 * n?¬??????????f????????????????????¨????????????
 * is_inv = false => ?????????
 * is_inv = true  => ?????????
 * ?????????????????¨??????multiply????????§n??§?????£?????????
 */
using comp = complex<ld>;
void fft(vector<comp> &f, int n, bool is_inv) {
if (n == 1) return;
vector<comp> f0(n / 2), f1(n / 2);
for (int i = 0; i < n / 2; i++) {
	f0[i] = f[2 * i];
	f1[i] = f[2 * i + 1];
	
}
fft(f0, n / 2, is_inv);
fft(f1, n / 2, is_inv);
comp zeta = comp(cos(2 * PI / n), sin(2 * PI / n));
if (is_inv) zeta = 1.0/ zeta;
comp pow_zeta = 1.0;
for (int i = 0; i < n; i++) {
	f[i] = f0[i % (n / 2)] + pow_zeta * f1[i % (n / 2)];
	pow_zeta *= zeta;
	
}

}
template<typename T>
vector<T> multiply(vector<T> g, vector<T> h) {
	int n = 1;
	int gs = g.size();
	int hs = h.size();
	int fs = gs + hs - 1;
	while (n <= fs + 1) n *= 2;
	vector<comp> gg(n), hh(n), ff(n);
	for (int i = 0; i < n; i++) {
		gg[i] = (i < gs) ? g[i] : 0;
		hh[i] = (i < hs) ? h[i] : 0;

	}
	
	fft(gg, n, false);
	fft(hh, n, false);
	for (int i = 0; i < n; i++) ff[i] = gg[i] * hh[i];
	fft(ff, n, true);
	
		vector<T> f(fs);
		for (int i = 0; i < fs; i++) {
			f[i] = (T)round(ff[i].real() / n);
		}
	
	return f;
	
}
vector<int>to_line(vector<vector<int>>&f) {
	vector<int>l(f.size()*f[0].size());
	for (int i = 0; i < f.size(); ++i) {
		for (int j = 0; j < f[0].size(); ++j) {
			l[i*f[0].size() + j] = f[i][j];
		}
	}
	return l;
}
vector<vector<int>>to_f(vector<int>&l) {
	vector<vector<int>>f(int(sqrt(l.size())),vector<int>(int(sqrt(l.size()))));
	for (int i = 0; i < f.size(); ++i) {
		for (int j = 0; j < f[0].size(); ++j) {
			f[i][j]= l[i*f[0].size() + j];
		}
	}
	return f;
}

int main() {
	int N; cin >> N;
	vector<vector<int>>field(N, vector<int>(N));
	map<int, long long int>mp;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> field[i][j];
			if (field[i][j]>1) {
				mp[0] += (field[i][j] * field[i][j] - field[i][j]);
			}
		}
	} 
	vector<vector<int>>field_a(2 * N, vector<int>(2 * N));
	vector<vector<int>>field_b(field_a);
	{
		for (int y = 0; y <  N; ++y) {
			for (int x = 0; x <  N; ++x) {
				field_a[y][x] = field[y][x];
				field_b[N - 1 - y][N - 1 - x] = field_a[y][x];
			}
		}
	}
	vector<int> line_c;
	{
		vector<int>line_a, line_b;
		line_a = to_line(field_a);
		line_b = to_line(field_b);
		line_a.resize(line_a.size() / 2);
		line_b.resize(line_b.size() / 2);
		if (N == 1024) {
			line_a.pop_back();
			line_b.pop_back();
		}
		line_c = multiply(line_a, line_b);
	}
	line_c.resize(N*N * 4);
	vector<vector<int>>field_c = to_f(line_c);
	for (int y = 0; y < 2* N; ++y) {
		for (int x = 0; x < 2 * N; ++x) {
			int dy = y - (N - 1);
			int dx = x - (N - 1);
			int d = (dy*dy + dx*dx);
			if (d&&field_c[y][x]) {
				mp[d] += field_c[y][x];
			}
		}
	}
	long double sum = 0;
	long long int num = 0;
	for (auto m : mp) {
		sum += sqrt(m.first)*m.second;
		num += m.second;
	}
	cout << setprecision(10) << fixed;
	cout << sum / num << endl;
	int rest = 10000;
	for (auto m : mp) {
		if (m.second) {
			cout << m.first << " " << m.second / 2 << endl;
			rest--;
			if (!rest)break;
		}
	}
	return 0;
}