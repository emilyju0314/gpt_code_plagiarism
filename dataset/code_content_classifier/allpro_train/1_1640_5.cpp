#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <queue>
#include <set>
#include <map>
#include <valarray>
#include <bitset>
#include <stack>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
typedef long long ll;
typedef pair<int,int> pii;
const int INF = 1<<29;
const double PI = acos(-1);
const double EPS = 1e-8;

char op[] = {'+', '-', '*'};
int solve(string s) {
  //cout << s << endl;
  for (int i=s.size()-1; i>=0; --i) {
    REP(j, 3) {
      if (s[i] == op[j]) {
        int left = solve(s.substr(0, i));
        int right = solve(s.substr(i+1));
        if (left == -1 || right == -1) return -1;
        int res;
        if (j == 0) res = left + right;
        else if (j == 1) res = left - right;
        else res = left * right;
        if (res >= 10000 || res < 0) return -1;
        return res;
      }
    }
  }
  if (s.size() >= 5) return -1;
  int res = atoi(s.c_str());
  if (res >= 10000 || res < 0) return -1;
  return res;
}

int main() {
  string s;
  while(cin >> s) {
    int res = solve(s.substr(0, s.size()-1));
    if (res == -1) cout << "E" << endl;
    else cout << res << endl;
  }
}