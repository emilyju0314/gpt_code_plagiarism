#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>

#include <iostream>
#include <complex>
#include <string>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>

#include <functional>
#include <cassert>

typedef long long ll;
using namespace std;

#ifndef LOCAL
#define debug(x) ;
#else
#define debug(x) cerr << __LINE__ << " : " << #x << " = " << (x) << endl;

template <typename T1, typename T2>
ostream &operator<<(ostream &out, const pair<T1, T2> &p) {
  out << "{" << p.first << ", " << p.second << "}";
  return out;
}

template <typename T>
ostream &operator<<(ostream &out, const vector<T> &v) {
  out << '{';
  for (const T &item : v) out << item << ", ";
  out << "\b\b}";
  return out;
}
#endif

#define mod 1000000007 //1e9+7(prime number)
#define INF 1000000000 //1e9
#define LLINF 2000000000000000000LL //2e18
#define SIZE 200010

char S[SIZE], T[SIZE];
ll dp1[SIZE][2], dp2[SIZE][2];

int main(){
  int N;

  scanf("%s%s", S, T);

  N = strlen(S);

  dp1[0][1] = 1;

  for(int i=0; i<N; i++) {
    if (T[i] == '?') {
      dp1[i+1][0] = (dp1[i][0] * 10 + dp1[i][1] * (S[i] - '0')) % mod;
      dp1[i+1][1] = dp1[i][1] % mod;
      dp2[i+1][0] = (dp2[i][1] * 10 * (S[i] - '0') + dp2[i][0] * 10 * 10 + dp1[i][0] * 45 + dp1[i][1] * ((S[i] - '0') * (S[i] - '0' - 1) / 2)) % mod;
      dp2[i+1][1] = (dp2[i][1] * 10 + dp1[i][1] * (S[i] - '0')) % mod;
    } else {
      if(S[i] < T[i]) {
        dp1[i+1][0] = (dp1[i+1][0] + dp1[i][0]) % mod;
        dp2[i+1][0] = (dp2[i][0] * 10 + dp1[i][0] * (T[i] - '0')) % mod;
      } else if (S[i] == T[i]) {
        dp1[i+1][0] = (dp1[i+1][0] + dp1[i][0]) % mod;
        dp1[i+1][1] = (dp1[i+1][1] + dp1[i][1]) % mod;
        dp2[i+1][0] = (dp2[i][0] * 10 + dp1[i][0] * (T[i] - '0')) % mod;
        dp2[i+1][1] = (dp2[i][1] * 10 + dp1[i][1] * (T[i] - '0')) % mod;
      } else {
        dp1[i+1][0] = (dp1[i][0] + dp1[i][1]) % mod;
        dp2[i+1][0] = (dp2[i][0] * 10 + dp2[i][1] * 10 + (dp1[i][0] + dp1[i][1]) * (T[i] - '0')) % mod;
      }
    }
  }

  cout << (dp2[N][0] + dp2[N][1]) % mod << endl;

  return 0;
}

