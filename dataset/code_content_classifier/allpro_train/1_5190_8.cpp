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
template<class T> ostream& operator << (ostream &s, vector<vector<T> > P) 
{ for (int i = 0; i < P.size(); ++i) { s << endl << P[i]; } return s << endl; }
template<class T1, class T2> ostream& operator << (ostream &s, map<T1,T2> P) 
{ EACH(it, P) { s << "<" << it->first << "->" << it->second << "> "; } return s; }



const int MAX_COL = 2510;
struct BitMatrix {
    int m;
    vector<bitset<MAX_COL> > val;
    BitMatrix(int n_ = 1, int m_ = 1) {m = m_; val.resize(n_, bitset<MAX_COL>(0));}
    void init(int n_, int m_) {m = m_; val.clear(); val.resize(n_, bitset<MAX_COL>(0));}
    inline int size() {return val.size();}
    inline bitset<MAX_COL>& operator [] (int i) {return val[i];}
    inline friend ostream& operator << (ostream& s, BitMatrix M) {
        s << endl; 
        for (int i = 0; i < M.val.size(); ++i) {
            for (int j = 0; j < M.m; ++j) s << M.val[i][j];
            s << endl;
        }
        return s;
    }
};

vector<vector<int> > Gauss_Jordan(BitMatrix A, vector<int> b) {
	int rank = 0;
    for (int i = 0; i < A.size(); ++i) { A[i][A.m] = b[i]; }
    
    vector<int> core, rem;
	for (int i = 0; i < A.m; ++i) {
		int pivot = -1;
		for (int j = rank; j < A.size(); ++j) {
			if (A[j][i]) {
				pivot = j;
				break;
			}
		}
		if (pivot != -1) {
            core.push_back(i);
			swap(A[pivot], A[rank]);
			for (int j = 0; j < A.size(); ++j) if (j != rank && A[j][i]) A[j] ^= A[rank];
			++rank;
		}
        else rem.push_back(i);
	}
    
    vector<vector<int> > res;
    for (int i = rank; i < A.size(); ++i) 
        if (A[i][A.m]) return res;     // return -1;
    
    vector<int> sol(A.m, 0);
    for (int i = 0; i < core.size(); ++i) sol[core[i]] = A[i][A.m];
    res.push_back(sol);
    
    for (int i = 0; i < rem.size(); ++i) {
        vector<int> temp(A.m, 0);
        temp[rem[i]] = 1;
        for (int j = 0; j < core.size(); ++j) temp[core[j]] = A[j][rem[i]];
        res.push_back(temp);
    }
    
    return res;     // return A[0].size()-rank;
};


int dx[8] = {1, 0, -1, 0, 1, -1, 1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, -1, 1};

int R, C;
const int MOD = 1000000009;

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

int main() {
    //freopen( "/Users/macuser/Dropbox/Contest/input.in", "r", stdin );
//    BitMatrix A(2, 3);
//    A[0] = 3; A[1]  = 6;
//    
//    vector<int> b(2); b[0] = 1, b[1] = 1;
//    
//    COUT(A);
//    vector<vector<int> > res = Gauss_Jordan(A, b);
//    
//    COUT(res);
    while (cin >> R >> C) {
        BitMatrix A(R*C, R*C);
        vector<int> b(R*C);
        for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) cin >> b[i*C + j];
        
        for (int i = 0; i < R; ++i) for (int j = 0; j < C; ++j) {
            int c = i*C + j;
            A[c][c] = 1;
            for (int k = 0; k < 8; ++k) {
                for (int l = 0; l < 50; ++l) {
                    int ni = i + dx[k]*l, nj = j + dy[k]*l;
                    if (ni < 0 || ni >= R || nj < 0 || nj >= C) break;
                    A[ni*C+nj][c] = 1;
                }
            }
        }
         
        vector<vector<int> > res = Gauss_Jordan(A, b);
        
//        COUT(A);
//        COUT(b);
//        COUT(res);
        
        if (res.size() == 0) cout << 0 << endl;
        else {
            int rank = res.size() - 1;
            long long res = pow(2LL, rank, MOD);
            cout << res << endl;
        }
    }
    return 0;
}
