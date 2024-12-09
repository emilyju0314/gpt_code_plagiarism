#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <vector>
using namespace std;

#define REP2(i, m, n) for(int i = (int)(m); i < (int)(n); i++)
#define REP(i, n) REP2(i, 0, n)
#define ALL(c) (c).begin(), (c).end()
#define FOREACH(i, c) for(auto i = (c).begin(); i != (c).end(); ++i)
#define BIT(n, m) (((n) >> (m)) & 1)

typedef long long ll;
typedef pair<int, int> PI;

const ll inf = 1e15;
const ll mod = 1000 * 1000 * 1000 + 7;
const double eps = 1e-9;

template <typename S, typename T> ostream &operator<<(ostream &out, const pair<S, T> &p) {
  out << "(" << p.first << ", " << p.second << ")";
  return out;
}

template <typename T> ostream &operator<<(ostream &out, const vector<T> &v) {
  out << "[";
  REP(i, v.size()){
    if (i > 0) out << ", ";
    out << v[i];
  }
  out << "]";
  return out;
}


int H, L;
vector<string> T;
vector<int> hint;
vector<int> blow;
vector<int> h_count;
vector<int> t_mask;
int used_mask = 0;

void dfs(int pos, string &str, string &ans)
{
  if (ans == "-2") return;
  
  if (pos == str.size()){
    bool ok = true;
    REP(i, T.size()) if (ok){
      int h = h_count[i];
      int b = __builtin_popcount(used_mask & t_mask[i]) - h;
      ok = ok && h == hint[i] && b == blow[i];
    }
    if (ok){
      if (ans == "-1"){
        ans = str;
      } else {
        ans = "-2";
      }
    }
    return;
  }

  REP(i, 10) if ((used_mask & (1 << i)) == 0){
    str[pos] = '0' + i;
    used_mask = used_mask | 1 << i;

    bool ok = true;
    REP(j, T.size()) {
      h_count[j] += T[j][pos] == str[pos];
      if (h_count[j] > hint[j]) ok = false;
    }
    if (ok) dfs(pos + 1, str, ans);
    REP(j, T.size()) h_count[j] -= T[j][pos] == str[pos];
    
    used_mask = used_mask ^ 1 << i;
  }
}


int main(){
  int L, H;
  while (cin >> L >> H && L + H){
    T.resize(H);
    hint.resize(H);
    blow.resize(H);
    t_mask.resize(H);
    h_count.resize(H);
    fill(ALL(h_count), 0);
    used_mask = 0;
    REP(i, H){
      cin >> T[i] >> hint[i] >> blow[i];
      t_mask[i] = 0;
      REP(j, T[i].size()) t_mask[i] |= (1 << (T[i][j] - '0'));
    }
    string ans = "-1";
    string str(L, ' ');
    dfs(0, str, ans);
    if (ans != "-1" && ans != "-2"){
      cout << ans << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}