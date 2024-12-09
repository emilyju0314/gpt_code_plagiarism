#include <algorithm>
#include <bitset>
#include <cassert>
#include <complex>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>
#include <array>
#include <chrono>
#include <random>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#define INIT std::ios::sync_with_stdio(false);std::cin.tie(0);
#define VAR(type, ...)type __VA_ARGS__;Scan(__VA_ARGS__);
template<typename T> void Scan(T& t) { std::cin >> t; }
template<typename First, typename...Rest>void Scan(First& first, Rest&...rest) { std::cin >> first; Scan(rest...); }
#define OUT(d) std::cout<<d;
#define FOUT(n, d) std::cout<<std::fixed<<std::setprecision(n)<<d;
#define SOUT(n, c, d) std::cout<<std::setw(n)<<std::setfill(c)<<d;
#define SP std::cout<<" ";
#define TAB std::cout<<"\t";
#define BR std::cout<<"\n";
#define ENDL std::cout<<std::endl;
#define FLUSH std::cout<<std::flush;
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define MAT(type, c, m, n) std::vector<std::vector<type>> c(m, std::vector<type>(n));for(auto& r:c)for(auto& i:r)std::cin>>i;
#define ALL(a) (a).begin(),(a).end()
#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define RFOR(i, a, b) for(int i=(b)-1;i>=(a);--i)
#define REP(i, n) for(int i=0;i<int(n);++i)
#define RREP(i, n) for(int i=(n)-1;i>=0;--i)
#define FORLL(i, a, b) for(ll i=ll(a);i<ll(b);++i)
#define RFORLL(i, a, b) for(ll i=ll(b)-1;i>=ll(a);--i)
#define REPLL(i, n) for(ll i=0;i<ll(n);++i)
#define RREPLL(i, n) for(ll i=ll(n)-1;i>=0;--i)
#define PAIR std::pair<int, int>
#define PAIRLL std::pair<ll, ll>
#define IN(a, x, b) (a<=x && x<b)
#define SHOW(d) {std::cout << #d << "\t:" << d << "\t";}
#define SHOWVECTOR(v) {std::cout << #v << "\t:";for(const auto& i : v){std::cout << i << " ";}std::cout << "\n";}
#define SHOWVECTOR2(v) {std::cout << #v << "\t:\n";for(const auto& i : v){for(const auto& j : i){std::cout << j << " ";}std::cout << "\n";}}
#define SHOWPAIRVECTOR2(v) {std::cout << #v << "\t:\n";for(const auto& i : v){for(const auto& j : i){std::cout<<'('<<j.first<<", "<<j.second<<") ";}std::cout << "\n";}}
#define SHOWPAIRVECTOR(v) {for(const auto& i:v){std::cout<<'('<<i.first<<", "<<i.second<<") ";}std::cout<<"\n";}
#define CHECKTIME(state) {auto start=std::chrono::system_clock::now();state();auto end=std::chrono::system_clock::now();auto res=std::chrono::duration_cast<std::chrono::nanoseconds>(end-start).count();std::cerr<<"[Time:"<<res<<"ns  ("<<res/(1.0e9)<<"s)]\n";}
#define SHOWQUEUE(a) {std::queue<decltype(a.front())> tmp(a);std::cout << #a << "\t:";for(int i=0; i<static_cast<int>(a.size()); ++i){std::cout << tmp.front() << "\n";tmp.pop();}std::cout << "\n";}
#define CHMAX(a, b) a = (((a)<(b)) ? (b) : (a))
#define CHMIN(a, b) a = (((a)>(b)) ? (b) : (a))

//#define int ll
using ll = long long;
using ull = unsigned long long;
constexpr int INFINT = 1 << 30;
constexpr ll INFLL = 1LL << 60;
constexpr double EPS = 0.0000000001;
constexpr int MOD = 1000000007;

signed main() {
	INIT;
	VAR(int, n, d);
	VEC(int, p, n);
	int ans = 0;
	REP(i, n) {
		ans += std::max(0, p[i] - d);
	}
	if (ans == 0) {
		OUT("kusoge")BR;
	}
	else {
		OUT(ans)BR;
	}
	return 0;
}