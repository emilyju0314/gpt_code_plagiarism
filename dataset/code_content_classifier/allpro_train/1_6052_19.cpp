#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
typedef vector<ll> Array;
typedef vector<Array> Matrix;

// 正方行列の掛け算 O(N^3)
Matrix mul(const Matrix &a, const Matrix &b){
  const int N = a.size();
  Matrix res(N, Array(N, 0));
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      for(int k = 0; k < N; k++){
        res[i][j] += a[i][k] * b[k][j];
        res[i][j] %= MOD;
      }
    }
  }
  return res;
}
// サイズNの単位行列
Matrix Mat_E(int N){
  Matrix res(N, Array(N, 0));
  for(int i = 0; i < N; i++){
    res[i][i] = 1;
  }
  return res;
}
// 正方行列の累乗 O(M^3 * logn)
Matrix pow(const Matrix &a, long long n){
  const int M = a.size();
  if(n == 0) return Mat_E(M);
  Matrix res = pow(mul(a, a), n / 2);
  if(n & 1) res = mul(res, a);
  return res;
}

void make_mat(int x1, int y1, int dx[6], int dy[6], Matrix& mat, map< pair<int, int>, int >& to_index){
  int u = to_index[make_pair(x1, y1)];
  REP(r, 6) {
    int x2 = x1 + dx[r];
    int y2 = y1 + dy[r];
    if(to_index.count(make_pair(x2, y2))){
      int v = to_index[make_pair(x2, y2)];
      mat[u][v] = 1;
    }
  }
}
int main(){
  int N, M, L;
  int CASENUM = 1;
  while(cin >> N >> M >> L && N){
    printf("Case %d: ", CASENUM++);
    MOD = M;
    map< pair<int, int>, int > to_index;
    vector<int> init;
    REP(y, 2 * N - 1){
      REP(x, 2 * N - 1 - abs(y - (N - 1))){
        int X; cin >> X;
        int T = to_index.size();
        assert(init.size() == T);
        init.push_back(X);
        to_index[make_pair(x, y)] = T;
      }
    }
    int T = to_index.size();
    Matrix mat(T, Array(T, 0));
    REP(i, T) mat[i][i] = 1;
    REP(y1, 2 * N - 1){
      REP(x1, 2 * N - 1 - abs(y1 - (N - 1))){
        int dy[6] = {-1, -1, 0, 1, 1, 0};
        if(y1 < N - 1){
          int dx[6] = {-1, 0, 1, 1, 0, -1};
          make_mat(x1, y1, dx, dy, mat, to_index);
        }else if(y1 == N - 1){
          int dx[6] = {-1, 0, 1, 0, -1, -1};
          make_mat(x1, y1, dx, dy, mat, to_index);
        }else{
          int dx[6] = {0, 1, 1, 0, -1, -1};
          make_mat(x1, y1, dx, dy, mat, to_index);
        }
      }
    }
    mat = pow(mat, L);
    /*
    REP(i, T) {
      REP(j, T) cout << mat[i][j] << " ";
      cout << endl;
    }
    cout << endl;
    */
    //REP(i, T) cout << init[i] << " "; cout << endl;
    vector<ll> terminal(T);
    REP(i, T) REP(j, T) terminal[i] = (terminal[i] + mat[i][j] * init[j]) % M;
    /*
    REP(y1, 2 * N - 1){
      REP(x1, 2 * N - 1 - abs(y1 - (N - 1))){
        cout << terminal[to_index[ make_pair(x1, y1) ]] << " ";
      }
      cout << endl;
    }
    */
    ll ans = 0;
    REP(i, T) ans += terminal[i];
    cout << ans << endl;
  }
  return 0;
}