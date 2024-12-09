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
int n;
string S[100];
int H[100], B[100];
string str;
set<string> se;
void func(int pos, int used) {
  if (pos == 4) {
    bool f = 1;
    REP(i, n) {
      int h=0,b=0;
      REP(j,4) {
        if (S[i][j]==str[j]) h++;
        if (used>>(S[i][j]-'0')&1) b++;
      }
      b -= h;
      if (H[i] != h || B[i] != b) {
        f = 0;
        break;
      }
    }
    if (f) se.insert(str);
    return;
  }
  REP(i, 10) {
    if (used>>i&1) continue;
    str[pos] = '0'+i;
    func(pos+1, used|1<<i);
  }
}
bool table[4][4];
bool func2(int pos, int used) {
  if (pos == 4) {
    memset(table, 0, sizeof(table));
    FOR(it, se) {
      int h=0,b=0;
      string t = *it;
      REP(j,4) {
        if (t[j]==str[j]) h++;
        if (used>>(t[j]-'0')&1) b++;
      }
      b -= h;
      if (table[h][b]) return 0;
      table[h][b] = 1;
    }
    return 1;
  }
  REP(i, 10) {
    if (used>>i&1) continue;
    str[pos] = '0'+i;
    if (func2(pos+1, used|1<<i)) return 1;
  }
  return 0;
}



int main() {
  while(cin >> n, n) {
    REP(i, n) {
      cin >> S[i] >> H[i] >> B[i];
    }
    se.clear();
    str = "0000";
    func(0,0);
    
    if(se.size() == 1) {
      cout << *se.begin() << endl;
    } else if(se.size() >= 2 && func2(0, 0)) {
      cout << str << endl;
    } else {
      cout << "????" << endl;
    }
    
  }
}