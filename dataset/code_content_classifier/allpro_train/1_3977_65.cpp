// memo version
#include<iostream>
#include<vector>
#include<functional>
template<typename T>
std::ostream &operator <<(std::ostream &os, const std::vector<T> &vs) {
    using namespace std;
    bool fst = true;
    for(auto &v : vs) {
      if(!fst) os << ",";
      os << v;
      fst = false;
    }
    return os;
}
using namespace std;
// next_combination:
// given an integer cur, next_combination returns an integer nxt s.t.
//   nxt has the same number of 1s as cur
//   nxt is bigger than cur
//   no integer between cur and nxt has the same number of 1s as cur (and nxt)
int next_combination(int cur){
  int r1 = cur & -cur;      // extracts the rightmost 1
  int moved1 = cur + r1;    // cancel the rightmost run of 1s and put 1 on its left
  int rm1s = cur & ~moved1; // extracts the rightmost run of 1s
  int reset = (rm1s / r1) >> 1; // the run of 1s moved to LSD and made its length decreased by 1
  int nxt = moved1 | reset; // new combination
  return nxt;
}
int memo[9][6*6*6*6*6*6*6*6*6];
int main(int argc, char *argv[])
{
  for(;;){
    int n; cin >> n;
    if(n == 0) break;

    vector<int> wons(n, 0); // wons
    vector<int> losts(n, 0); // losts
    int m; cin >> m;
    for(int k = 0; k < m; k++) {
      int i, j; cin >> i >> j;
      wons[i-1] |= (1 << (j-1));
      losts[j-1] |= (1 << (i-1));
    }
    for(int i = 2; i < n; i++) {
      unsigned int im = 1;
      for(int k = i; k < n; k++) {
        im *= 6;
      }
      for(unsigned int j = 0; j < im; j++) {
        memo[i-2][j] = -1;
      }
    }
    vector<int> ws(n, n/2); // # of to win
    function<int(int)> rec = [n,&rec,&wons,&losts,&ws](int i){
      if(i >= n) return 1;
      if(n - 1 - i < ws[i]) return 0;
      unsigned int idx = 0;
      for(int j = i; j < n; j++) {
        idx = idx*6 + ws[j];
      }
      if(i >= 2 && memo[i-2][idx]>=0) {
        return memo[i-2][idx];
      }
      int k = ws[i];
      int win = ((1<<k)-1) << (i+1);
      const int fin = win << (n-1-k-i);
      const int mask = (1<<n) - (1 << (i+1));
      const int won = wons[i] & mask;
      const int lost = losts[i];
      int cnt = 0;
      for(;;) {
        if(((won & win) == won) && (lost & win) == 0) {
          bool ok = true;
          for(int j = i + 1; j < n; j++) {
            if(((1<<j) & win) == 0) {
              if(ws[j] == 0) ok = false;
              ws[j]--;
            }
          }
          if(ok) cnt += rec(i+1);
          for(int j = i + 1; j < n; j++) {
            if(((1<<j) & win) == 0) {
              ws[j]++;
            }
          }
        }
        if(win == fin) break;
        win = next_combination(win);
      }
      if(i >= 2) {
        memo[i-2][idx] = cnt;
      }
      return cnt;
    };
    int ans = rec(0);
    cout << ans << endl;
  }
  return 0;
}

