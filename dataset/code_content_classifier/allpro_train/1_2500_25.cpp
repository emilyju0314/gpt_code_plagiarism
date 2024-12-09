#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <cassert>
#include <bitset>
using namespace std;

typedef pair<int, int> P;
#define rep(i, n) for (int i=0; i<(n); i++)
#define all(c) (c).begin(), (c).end()
#define uniq(c) c.erase(unique(all(c)), (c).end())
#define index(xs, x) (int)(lower_bound(all(xs), x) - xs.begin())
#define _1 first
#define _2 second
#define pb push_back
#define INF 1145141919
#define MOD 1000000007
const int B = 12345;

int K, L;
int Lnum;
int pB[100001];
int A[100001];
int TA[100001];
string S;

bool g(int pos, string &T) {
  int lo = -1, hi = T.length();
  while (hi - lo > 1) {
    int mid = (lo + hi) / 2;
    // [0, mid]
    int a = (A[pos+mid]+MOD-(pos>0?A[pos-1]:0)) % MOD;
    if (a == (1LL*pB[pos]*TA[mid])%MOD) lo = mid;
    else hi = mid;
  }
  int lcp = lo+1;
  if (lcp == T.length()) return true;
  return S[pos+lcp] <= T[lcp];
}

bool f(string &T) {
  int pos = 0;
  int cl = 0, cr = 0;
  rep(_, K) {
    assert(pos < S.length());
    if (cl < Lnum && g(pos, T)) {
      pos += L;
      cl++;
    }
    else {
      if (cr >= K-Lnum) return false;
      pos += L-1;
      cr++;
    }
  }
  assert(pos == S.length() && cl == Lnum && cl+cr == K);
  return true;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(0);
  pB[0] = 1;
  for (int i=1; i<=100000; i++) pB[i] = (1LL*B*pB[i-1]) % MOD;
  cin >> K >> S;
  rep(i, S.length()) A[i] = ((i>0?A[i-1]:0)+1LL*S[i]*pB[i]) % MOD;
  K++;
  L = (S.length()+K-1)/K;
  Lnum = S.length()%K;
  if (S.length()%K==0) Lnum = K;
  string T;
  rep(i, L) {
    int dig = 9;
    for (int c=1; c<=8; c++) {
      string ct(T);
      ct += (char)('0'+c);
      TA[i] = ((i>0?TA[i-1]:0) + 1LL*pB[i]*ct.back()) % MOD;
      if (f(ct)) {
        dig = c;
        break;
      }
    }
    T += (char)('0'+dig);
    TA[i] = ((i>0?TA[i-1]:0) + 1LL*pB[i]*T.back()) % MOD;
  }
  cout << T << "\n";
  return 0;
}
