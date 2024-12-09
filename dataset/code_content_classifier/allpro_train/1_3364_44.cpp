#include <iostream>
#include <complex>
#include <sstream>
#include <string>
#include <algorithm>
#include <deque>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <vector>
#include <set>
#include <limits>
#include <cstdio>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define REP(i, j) for(int i = 0; i < (int)(j); ++i)
#define FOR(i, j, k) for(int i = (int)(j); i < (int)(k); ++i)
#define SORT(v) sort((v).begin(), (v).end())
#define REVERSE(v) reverse((v).begin(), (v).end())

int P, N[6], cost[6] = {500, 100, 50, 10, 5, 1};

int check(int p){
  int cnt = 0;
  REP(i, 6){
    int n = min(N[i], p / cost[i]);
    cnt += n;
    p -= n * cost[i];
  }
  return p == 0 ? cnt : -1;
}

int f(int p){
  int res = 0;
  REP(i, 6){
    res += p / cost[i];
    p %= cost[i];
  }
  return res;
}

int main() {
  while(cin >>P && P){
    int sum = 0, ans = 1e9;
    REP(i, 6) { cin >>N[5 - i]; sum += N[5 - i] * cost[5 - i]; }
    FOR(i, P, sum + 1){
      int cnt = check(i);
      if(cnt != -1) ans = min(ans, cnt + f(i - P));
    }
    cout <<ans <<endl;
  }
  
  return 0;
}