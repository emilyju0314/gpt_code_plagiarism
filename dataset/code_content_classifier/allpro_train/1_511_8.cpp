#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <tuple>
#include <cstring>
#include <queue>
using namespace std;
using ll = long long int;

const ll MOD = 1000000007;
const int SIZE = 26;

struct PMA {
  PMA* node[SIZE + 1];
  vector<int> matched;
  PMA() { memset(node, 0, sizeof(node)); }

  vector<int> unite(const vector<int> &a, const vector<int> &b) {
    vector<int> ret;
    set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(ret));
    return ret;
  }

  void build(vector<string> pattern) {
    PMA* root = this;
    root -> node[SIZE] = root;
    for(size_t i=0; i<pattern.size(); i++) {
      PMA* now = root;
      for(size_t j=0; j<pattern[i].size(); j++) {
        int c = pattern[i][j] - 'a';
        if(!now -> node[c]) {
          now -> node[c] = new PMA;
        }
        now = now -> node[c];
      }
      now -> matched.push_back(i);
    }

    queue<PMA*> que;
    for(int i=0; i<SIZE; i++) {
      if(!root -> node[i]) root -> node[i] = root;
      else {
        root -> node[i] -> node[SIZE] = root;
        que.push(root -> node[i]);
      }
    }

    while(que.size()) {
      PMA* now = que.front(); que.pop();
      for(int i=0; i<SIZE; i++) {
        if(now -> node[i]) {
          PMA* nxt = now -> node[SIZE];
          while(!nxt -> node[i]) nxt = nxt -> node[SIZE];

          now->node[i]->node[SIZE] = nxt->node[i];
          now->node[i]->matched=unite(now->node[i]->matched, nxt->node[i]->matched);
          que.push(now->node[i]);
        }
      }
    }
  }

  ll solve(const string s, vector<string> pattern) {
    PMA* pma = this;

    int N = s.length();
    vector<ll> dp(N+1);
    dp[0] = 1;
    for(size_t i=0; i<s.length(); i++) {
      int c = s[i] - 'a';
      while(!pma -> node[c]) pma = pma -> node[SIZE];

      pma = pma -> node[c];
      for(size_t j=0; j<pma->matched.size(); j++) {
        int r = i+1, l=r-pattern[ pma->matched[j] ].length();
        (dp[r] += dp[l]) %= MOD;
      }
    }

    return dp[N];
  }
};

int main() {
  int N; cin >> N;
  vector<string> pats(N);
  for(int i=0; i<N; i++) {
    cin >> pats[i];
  }

  string text; cin >> text;
  PMA pma;
  pma.build(pats);

  cout << pma.solve(text, pats) << endl;
  return 0;
}
