#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using lll = __int128;
template <typename T>
using v = vector<T>;
const ll N = 250;
const ll V = 26;
const ll P = 1e11 + 3;
const ll C = 251;
ll arr[N][N];
ll hashes[N][N];
ll seq[N][V];
ll pows[V];
ll keys[N];
ll matchlen[N + 1];
ll oddcounts[N];
bool pal[N];
int main(int argc, char const* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  ll n, m;
  cin >> n >> m;
  pows[0] = 1;
  for (ll v = 1; v < V; v++) {
    pows[v] = (pows[v - 1] * C) % P;
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      char cur;
      cin >> cur;
      arr[i][j] = cur - 'a';
    }
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      ll cur = arr[i][j];
      hashes[i][j] = (j > 0) ? hashes[i][j - 1] : 0;
      hashes[i][j] += pows[cur];
    }
  }
  ll result = 0;
  for (ll j0 = 0; j0 < m; j0++) {
    memset(seq, 0, sizeof(seq));
    memset(oddcounts, 0, sizeof(oddcounts));
    for (ll j1 = j0; j1 < m; j1++) {
      for (ll i = 0; i < n; i++) {
        ll cur = arr[i][j1];
        seq[i][cur]++;
        if (seq[i][cur] & 1) {
          oddcounts[i]++;
        } else {
          oddcounts[i]--;
        }
        pal[i] = (oddcounts[i] < 2);
        keys[i] = hashes[i][j1] - ((j0 > 0) ? hashes[i][j0 - 1] : 0);
      }
      ll l = 0, r = -1;
      for (ll i = 0; i < n; i++) {
        ll j = (i <= r) ? min(matchlen[l + r - i], r + 1 - i) : 0;
        ll mj = min(i + 1, n - i);
        for (; j <= mj - 1 && pal[i + j] && keys[i + j] == keys[i - j]; j++) {
        }
        matchlen[i] = j;
        if (i + (j - 1) > r) {
          r = i + (j - 1);
          l = i - (j - 1);
        }
        result += matchlen[i];
      }
      l = 0, r = -1;
      for (ll i = 0; i <= n; i++) {
        ll j = (i < r) ? min(matchlen[l + r - i], r - i) : 0;
        ll mj = min(i, n - i);
        for (; j <= mj - 1 && pal[i + j] && keys[i + j] == keys[i - j - 1];
             j++) {
        }
        matchlen[i] = j;
        if (i + j > r) {
          r = i + j;
          l = i - j;
        }
        result += matchlen[i];
      }
    }
  }
  cout << result << "\n";
  return 0;
}
