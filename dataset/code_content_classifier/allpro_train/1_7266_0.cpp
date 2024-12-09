#include <iostream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <numeric>
#include <utility>
#include <iomanip>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long ll;
typedef vector<int> vint;
typedef vector<long long> vll;
typedef pair<int,int> pint;
typedef pair<long long, long long> pll;

#define MP make_pair
#define PB push_back
#define ALL(s) (s).begin(),(s).end()
#define EACH(i, s) for (__typeof__((s).begin()) i = (s).begin(); i != (s).end(); ++i)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T1, class T2> ostream& operator << (ostream &s, pair<T1,T2> P) 
{ return s << '<' << P.first << ", " << P.second << '>'; }
template<class T> ostream& operator << (ostream &s, vector<T> P) 
{ for (int i = 0; i < P.size(); ++i) { if (i > 0) { s << " "; } s << P[i]; } return s; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P) 
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s; }







long long MOD;

inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}

long long pow(long long a, long long n, long long m) {
    if (n == 0) return 1 % m;
    long long t = pow(a, n/2, m);
    t = mod(t * t, m);
    if (n & 1) t = mod(t * a, m);
    return t;
}

long long inv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a/b;
        a -= t*b; swap(a, b);
        u -= t*v; swap(u, v);
    }
    return mod(u, m);
}

struct ModPolynomial : vector<long long> {
    ModPolynomial() : vector<long long>(1, 0) { }
    ModPolynomial(long long num) : vector<long long>(1, num) { }
    ModPolynomial(int size, long long num) : vector<long long>(size, num) { }
    ModPolynomial(vector<long long> vec) { (*this) = vec; }
    
    ModPolynomial& normalize() {
        for (int i = 0; i < (*this).size(); ++i) (*this)[i] = mod((*this)[i], MOD);
        while ( (*this).size() > 1 && (*this).back() == 0 ) (*this).pop_back();
        return (*this);
    }
    
    inline ModPolynomial operator - () { 
        for (int i = 0; i < (*this).size(); ++i) (*this)[i] = (*this)[i] * (-1); 
        return (*this).normalize();
    }
};

ostream &operator << (ostream &os, ModPolynomial x) {
    for (int i = x.size()-1; i >= 0; --i) { 
        if (i != x.size()-1) os << abs(x[i]); else os << x[i];
        if (i != 0) {
            os << "x"; if (i != 1) os << "^" << i; os << " ";
            if (x[i-1] < 0) os << "- "; else os << "+ ";
        }
    }
    return os;
}

inline ModPolynomial operator + (ModPolynomial x, ModPolynomial y) {
    while (x.size() > y.size()) y.push_back(0);
    while (y.size() > x.size()) x.push_back(0);
    ModPolynomial z((int)x.size(), 0);
    for (int i = 0; i < x.size(); ++i) z[i] = x[i] + y[i];
    return z.normalize();
} 
inline ModPolynomial operator - (ModPolynomial x, ModPolynomial y) {
    y = -y;
    return x + y;
}
inline ModPolynomial operator * (ModPolynomial x, ModPolynomial y) {
    ModPolynomial z((int)x.size() + (int)y.size() - 1, 0);
    for (int i = 0; i < x.size(); ++i) for (int j = 0; j < y.size(); ++j) z[i+j] = mod(z[i+j] + x[i] * y[j], MOD);
    return z.normalize();
}
pair<ModPolynomial,long long> divmod(ModPolynomial x, long long a) {
    for (int i = x.size()-1; i >= 0; --i) x[i] = mod(x[i] * inv(a, MOD), MOD);
    return pair<ModPolynomial,long long>(x, 0);
}
pair<ModPolynomial,ModPolynomial> divmod(ModPolynomial x, ModPolynomial y) {
    if (x.size() < y.size()) return make_pair(0, x);
    if (y.size() == 1) return divmod(x, y.back());
    ModPolynomial q((int)x.size() - (int)y.size() + 1, 0);
    for (int i = x.size()-1; i >= y.size()-1; --i) {
        long long div = mod(x[i] * inv(y.back(), MOD), MOD);
        q[i-(int)y.size()+1] = div;
        for (int j = 0; j < y.size(); ++j) x[i+j-(int)y.size()+1] = mod(x[i+j-(int)y.size()+1] - y[j] * div, MOD);
    }
    return make_pair(q, x.normalize());
}
ModPolynomial operator % (ModPolynomial x, ModPolynomial y) {
    return divmod(x, y).second;
}
ModPolynomial pow(ModPolynomial a, long long n, ModPolynomial PMOD) {
    ModPolynomial res(1, 1);
    while (n > 0) { if (n & 1) { res = (res * a) % PMOD; } a = (a * a) % PMOD; n >>= 1;}
    return res;
}
ModPolynomial gcd(ModPolynomial x, ModPolynomial y) {
    if (y.size() == 1 && y.back() == 0) return x;
    else return gcd(y, x%y);
}
ModPolynomial generateX() { ModPolynomial X(2, 0); X[1] = 1; return X; }
ModPolynomial EX = generateX();



long long N, P, a;

int main() {
    while (cin >> N >> P) {
        if (N == 0) break;
        
        MOD = P;
        ModPolynomial pol(N+1, 0);
        for (int i = 0; i < N+1; ++i) cin >> pol[i];
        pol.normalize();
        
        if (pol.size() == 1 && pol.back() == 0) { cout << MOD << endl; continue; }
        
        ModPolynomial check = pow(EX, MOD, pol) - EX;
        ModPolynomial G = gcd(pol, check);
        
        cout << G.size() - 1 << endl;
    }
    return 0;
}
