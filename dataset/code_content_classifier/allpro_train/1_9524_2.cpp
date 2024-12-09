#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps = 1e-9;



const int mod = 1000000007;
struct Mod {
public:
	int num;
	Mod() : Mod(0) { ; }
	Mod(long long int n) : num((n % mod + mod) % mod) {
		static_assert(mod<INT_MAX / 2, "mod is too big, please make num 'long long int' from 'int'");
	}
	Mod(int n) : Mod(static_cast<long long int>(n)) { ; }
	operator int() { return num; }
};

Mod operator+(const Mod a, const Mod b) { return Mod((a.num + b.num) % mod); }
Mod operator+(const long long int a, const Mod b) { return Mod(a) + b; }
Mod operator+(const Mod a, const long long int  b) { return b + a; }
Mod operator++(Mod &a) { return a + Mod(1); }
Mod operator-(const Mod a, const Mod b) { return Mod((mod + a.num - b.num) % mod); }
Mod operator-(const long long int a, const Mod b) { return Mod(a) - b; }
Mod operator--(Mod &a) { return a - Mod(1); }
Mod operator*(const Mod a, const Mod b) { return Mod(((long long)a.num * b.num) % mod); }
Mod operator*(const long long int a, const Mod b) { return Mod(a)*b; }
Mod operator*(const Mod a, const long long int b) { return Mod(b)*a; }
Mod operator*(const Mod a, const int b) { return Mod(b)*a; }
Mod operator+=(Mod &a, const Mod b) { return a = a + b; }
Mod operator+=(long long int &a, const Mod b) { return a = a + b; }
Mod operator-=(Mod &a, const Mod b) { return a = a - b; }
Mod operator-=(long long int &a, const Mod b) { return a = a - b; }
Mod operator*=(Mod &a, const Mod b) { return a = a * b; }
Mod operator*=(long long int &a, const Mod b) { return a = a * b; }
Mod operator*=(Mod& a, const long long int &b) { return a = a * b; }
Mod operator^(const Mod a, const int n) {
	if (n == 0) return Mod(1);
	Mod res = (a * a) ^ (n / 2);
	if (n % 2) res = res * a;
	return res;
}
Mod mod_pow(const Mod a, const long long  int n) {
	if (n == 0) return Mod(1);
	Mod res = mod_pow((a * a), (n / 2));
	if (n % 2) res = res * a;
	return res;
}
Mod inv(const Mod a) { return a ^ (mod - 2); }
Mod operator/(const Mod a, const Mod b) {
	assert(b.num != 0);
	return a * inv(b);
}
Mod operator/(const long long int a, const Mod b) {
	return Mod(a) / b;
}
Mod operator/=(Mod &a, const Mod b) {
	return a = a / b;
}

#define MAX_MOD_N 1024000

Mod fact[MAX_MOD_N], factinv[MAX_MOD_N];
void init(const int amax = MAX_MOD_N) {
	fact[0] = Mod(1); factinv[0] = 1;
	for (int i = 0; i < amax - 1; ++i) {
		fact[i + 1] = fact[i] * Mod(i + 1);
		factinv[i + 1] = factinv[i] / Mod(i + 1);
	}
}
Mod comb(const int a, const int b) {
	return fact[a] * factinv[b] * factinv[a - b];
}

long long int N, Q, A, B, C, D, E, F, G;

vector<int>xs;
vector<int>revxs;
vector<int>ys;
vector<int>revys;
bool ud_swap = false;
bool lr_swap = false;
int r_num = 0;
map<pair<int, int>, long long int>mp;

//?????????
pair<int, int>rot(pair<int, int>p, const int num) {
	if (num == 0) {
		return p;
	}
	else {
		p = rot(make_pair(p.second, N - 1 - p.first), num - 1);
		return p;
	}
}
pair<int, int>udsw(pair<int, int>p) {
	return make_pair(p.first, N - 1 - p.second);
}
pair<int, int>lrsw(pair<int, int>p) {
	return make_pair(N - 1 - p.first, p.second);
}
pair<int, int>getplace(pair<int, int>p) {
	p = rot(p, 4 - r_num);
	if (lr_swap)p = lrsw(p);
	if (ud_swap)p = udsw(p);
	p = make_pair(xs[p.first], ys[p.second]);
	return p;
}
long long int  getnum(const pair<int, int>p, const bool flag = false) {
	const pair<int, int>place = getplace(p);
	long long int ans;

	if (mp.find(place) == mp.end()) {
		ans = ((1 + place.second)*A + (1 + place.first)*B) % C;
	}
	else {
		ans = mp[place];
	}
	if (flag) {
		cout << "x:" << place.first << "   y:" << place.second << "   ans:" << ans << endl;
	}
	return ans;
}
void setnum(pair<int, int>p, long long int  num) {
	const pair<int, int>place = getplace(p);
	mp[place] = num;
}
int main() {
	{
		cin >> N >> Q >> A >> B >> C >> D >> E >> F >> G;
		xs.resize(N);
		iota(xs.begin(), xs.end(), 0);
		ys = xs;
		revxs = xs;
		revys = xs;
	}
	while (Q--) {
		string st; cin >> st;
		if (st == "WR") {
			int y, x; cin >> y >> x;
			y--; x--;
			int r; cin >> r;
			setnum(make_pair(x, y), r);
		}
		else if (st == "CP") {
			int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
			y1--; x1--; y2--; x2--;
			long long int r = getnum(make_pair(x1, y1));
			setnum(make_pair(x2, y2), r);
		}
		else if (st == "SR") {
			int y1, y2; cin >> y1 >> y2; y1--; y2--;
			int x1 = 0, x2 = 0;

			if (r_num == 0) {

			}
			else if (r_num == 2) {
				y1 = N - 1 - y1;
				y2 = N - 1 - y2;
				x1 = N - 1 - x1;
				x2 = N - 1 - x2;
			}
			else if (r_num == 1) {
				x1 = N - 1 - y1;
				x2 = N - 1 - y2;
				y1 = 0;
				y2 = 0;
			}
			else if (r_num == 3) {
				x1 = y1;
				x2 = y2;
				y1 = 0;
				y2 = 0;
			}
			if (ud_swap) {
				y1 = N - 1 - y1;
				y2 = N - 1 - y2;
			}
			if (lr_swap) {
				x1 = N - 1 - x1;
				x2 = N - 1 - x2;
			}
			{
				swap(ys[y1], ys[y2]);
				revys[ys[y1]] = y1;
				revys[ys[y2]] = y2;
				swap(xs[x1], xs[x2]);
				revxs[xs[x1]] = x1;
				revxs[xs[x2]] = x2;
			}
		}
		else if (st == "SC") {
			int x1, x2; cin >> x1 >> x2; x1--; x2--;
			int y1 = 0, y2 = 0;

			if (r_num == 0) {

			}
			else if (r_num == 2) {
				y1 = N - 1 - y1;
				y2 = N - 1 - y2;
				x1 = N - 1 - x1;
				x2 = N - 1 - x2;
			}
			else if (r_num == 1) {
				y1 =  x1;
				y2 =  x2;
				x1 = 0;
				x2 = 0;
			}
			else if (r_num == 3) {
				y1 = N - 1 - x1;
				y2 = N - 1 - x2;
				x1 = 0;
				x2 = 0;
			}
			if (ud_swap) {
				y1 = N - 1 - y1;
				y2 = N - 1 - y2;
			}
			if (lr_swap) {
				x1 = N - 1 - x1;
				x2 = N - 1 - x2;
			}
			{
				swap(ys[y1], ys[y2]);
				revys[ys[y1]] = y1;
				revys[ys[y2]] = y2;
				swap(xs[x1], xs[x2]);
				revxs[xs[x1]] = x1;
				revxs[xs[x2]] = x2;
			}
		}
		else if (st == "RL") {
			
			r_num = (r_num + 1) % 4;
		}
		else if (st == "RR") {
			r_num = (r_num + 3) % 4;
		}
		else if (st == "RH") {
			if (r_num % 2) {
				lr_swap = !lr_swap;
			}
			else {
				ud_swap = !ud_swap;
			}
		}
		else {
			if (r_num % 2) {
				ud_swap = !ud_swap;
			}
			else {
				lr_swap = !lr_swap;
			}
		}
	}
	Mod ans = 314159265;
	for (int y = D - 1; y <= E - 1; ++y) {
		for (int x = F - 1; x <= G - 1; ++x) {
			ans = Mod(31) * ans + getnum(make_pair(x, y));
		}
	}
	cout << ans << endl;
	return 0;
}