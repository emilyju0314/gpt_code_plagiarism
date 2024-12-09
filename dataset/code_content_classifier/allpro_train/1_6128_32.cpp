#include <bits/stdc++.h>
// ------------ Modulo Class ------------ //
template<unsigned mod>
class modulo {
private:
	unsigned x;
public:
	modulo() : x(0) {};
	modulo(unsigned x_) : x(x_) {};
	operator unsigned() { return x; }
	modulo operator==(const modulo& m) const { return x == m.x; }
	modulo operator!=(const modulo& m) const { return x != m.x; }
	modulo& operator+=(const modulo& m) { x = (x + m.x >= mod ? x + m.x - mod : x + m.x); return *this; }
	modulo& operator-=(const modulo& m) { x = (x < m.x ? x - m.x + mod : x - m.x); return *this; }
	modulo& operator*=(const modulo& m) { x = 1ULL * x * m.x % mod; return *this; }
	modulo operator+(const modulo& m) const { return modulo(*this) += m; }
	modulo operator-(const modulo& m) const { return modulo(*this) -= m; }
	modulo operator*(const modulo& m) const { return modulo(*this) *= m; }
};
 
// ------------ Matrix Functions ------------ //
typedef std::vector<modulo<998244353> > matrix_base;
typedef std::vector<matrix_base> matrix;
matrix mul(const matrix& a, const matrix& b) {
	assert(a[0].size() == b.size());
	matrix ret(a.size(), matrix_base(b[0].size(), 0));
	for (int i = 0; i < a.size(); i++) {
		for (int j = 0; j < b[0].size(); j++) {
			for (int k = 0; k < b.size(); k++) ret[i][j] += a[i][k] * b[k][j];
		}
	}
	return ret;
}
matrix unit(int n) {
	matrix ret(n, matrix_base(n, 0));
	for (int i = 0; i < n; i++) ret[i][i] = 1;
	return ret;
}
matrix power(const matrix& a, long long b) {
	assert(a.size() == a[0].size());
	matrix f = a, ret = unit(a.size());
	while (b) {
		if (b & 1) ret = mul(ret, f);
		f = mul(f, f);
		b >>= 1;
	}
	return ret;
}
 
// ------------ Modpower Algorithm ------------ //
inline int modpow(int a, int b, int m) {
	int ret = 1;
	while (b) {
		if (b & 1) ret = 1LL * ret * a % m;
		a = 1LL * a * a % m;
		b >>= 1;
	}
	return ret;
}
 
// ------------ Number Theoretic Transform ------------ //
inline static std::vector<int> FastModuloTransform(std::vector<int> v, int base, int root) {
	int n = v.size();
	for (int i = 0, j = 1; j < n - 1; j++) {
		for (int k = n >> 1; k >(i ^= k); k >>= 1);
		if (i < j) std::swap(v[i], v[j]);
	}
	for (int b = 1; b <= n / 2; b *= 2) {
		int x = modpow(root, (base - 1) / (b << 1), base);
		for (int i = 0; i < n; i += (b << 1)) {
			int p = 1;
			for (int j = i; j < i + b; j++) {
				int t1 = v[j], t2 = 1LL * v[j + b] * p % base;
				v[j] = t1 + t2; v[j] = (v[j] < base ? v[j] : v[j] - base);
				v[j + b] = t1 - t2 + base; v[j + b] = (v[j + b] < base ? v[j + b] : v[j + b] - base);
				p = 1LL * p * x % base;
			}
		}
	}
	return v;
}
inline static std::vector<int> FastConvolutionMod(std::vector<int> v1, std::vector<int> v2, int mod, int tr) {
	int n = v1.size() * 2; // v1 and v2 must be the same size!!
	v1.resize(n);
	v2.resize(n);
	v1 = FastModuloTransform(v1, mod, tr);
	v2 = FastModuloTransform(v2, mod, tr);
	for (int i = 0; i < n; i++) v1[i] = 1LL * v1[i] * v2[i] % mod;
	v1 = FastModuloTransform(v1, mod, modpow(tr, mod - 2, mod));
	int t = modpow(n, mod - 2, mod);
	for (int i = 0; i < n; i++) v1[i] = 1LL * v1[i] * t % mod;
	return v1;
}
 
// ------------ Lagrange Interpolation ------------ //
std::vector<int> lagrange_interpolation(std::vector<int> &v, int m) {
	int n = v.size() - 1;
	std::vector<int> inv(n + 2); inv[1] = 1;
	for (int i = 2; i <= n; i++) inv[i] = 1LL * inv[m % i] * (m - m / i) % m;
	std::vector<int> ret(n + 1);
	int q = 1;
	for (int i = 1; i <= n; i++) q = 1LL * q * inv[i] % m;
	if (n % 2 == 1) q = (m - q) % m;
	for (int i = 0; i <= n; i++) {
		ret[i] = 1LL * v[i] * q % m;
		q = 1LL * q * (m - n + i) % m * inv[i + 1] % m;
	}
	return ret;
}
int lagrange_function(int x, std::vector<int> &v, int m) {
	int n = v.size() - 1;
	int mul = 1;
	for (int i = 0; i <= n; i++) mul = 1LL * mul * (x - i + m) % m;
	int ret = 0;
	for (int i = 0; i <= n; i++) ret = (ret + 1LL * v[i] * modpow(x - i + m, m - 2, m)) % m;
	return 1LL * ret * mul % m;
}
 
// ------------ Fibonacci Number ------------ //
int nth_fibonacci(long long x) {
	matrix e(2, matrix_base(2));
	e[0][0] = e[0][1] = e[1][0] = 1;
	matrix p(2, matrix_base(1));
	p[0][0] = 1; p[1][0] = 0;
	return mul(power(e, x), p)[1][0];
}
 
#include <iostream>
using namespace std;
const int mod = 998244353;
int fact[1000009], inv[1000009], factinv[1000009];
int combination(int a, int b) {
	if (a < 0 || b < 0 || a < b) return 0;
	return 1LL * fact[a] * factinv[b] % mod * factinv[a - b] % mod;
}
int n; long long m;
int main() {
	cin >> n >> m; n--; m--;
	if (n == 0) {
		cout << nth_fibonacci(m + 1) << endl;
	}
	else {
		fact[0] = 1;
		for (int i = 1; i < 2 * n; i++) fact[i] = 1LL * fact[i - 1] * i % mod;
		inv[1] = 1;
		for (int i = 2; i < 2 * n; i++) inv[i] = 1LL * inv[mod % i] * (mod - mod / i) % mod;
		factinv[0] = 1;
		for (int i = 1; i < 2 * n; i++) factinv[i] = 1LL * factinv[i - 1] * inv[i] % mod;
		vector<int> a(3 * n); a[0] = a[1] = 1;
		for (int i = 2; i < 3 * n; i++) a[i] = (a[i - 1] + a[i - 2]) % mod;
		int e = 1; while (e < n) e <<= 1;
		vector<int> b(e), bt(a.begin(), a.begin() + e);
		for (int i = 0; i < n; i++) b[i] = combination((n - 1) + i, i);
		vector<int> res = FastConvolutionMod(b, bt, mod, 3);
		if (m < n) {
			cout << res[m] << endl;
		}
		else {
			vector<int> diff(n);
			for (int i = 0; i < n; i++) diff[i] = (a[2 * n + i] - res[i] + mod) % mod;
			vector<int> poly = lagrange_interpolation(diff, mod);
			int f = nth_fibonacci(m + 2 * n + 1);
			int ret = lagrange_function(m % mod, poly, mod);
			cout << (f - ret + mod) % mod << endl;
		}
	}
	return 0;
}