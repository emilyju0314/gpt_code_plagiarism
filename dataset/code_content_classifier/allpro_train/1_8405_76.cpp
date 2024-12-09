#include <bits/stdc++.h>
using namespace std;
template <class T, class T2>
inline bool chkmax(T &x, const T2 &y) {
  return x < y ? x = y, 1 : 0;
}
template <class T, class T2>
inline bool chkmin(T &x, const T2 &y) {
  return x > y ? x = y, 1 : 0;
}
const long long mod = 1e9 + 7;
template <class T>
inline void fix(T &x) {
  if (x >= mod | x <= -mod) {
    x %= mod;
  }
  if (x < 0) {
    x += mod;
  }
}
const int MAX_N = 1e6 + 10;
int t[MAX_N], l[MAX_N], r[MAX_N];
int dp[MAX_N];
int encode(string &in) {
  if (in[0] == 'A') {
    return 0;
  } else if (in[0] == 'O') {
    return 1;
  } else if (in[0] == 'X') {
    return 2;
  } else if (in[0] == 'N') {
    return 3;
  } else {
    return 4;
  }
}
int dfs(int x) {
  if (t[x] == 4) {
    return dp[x];
  }
  dp[x] = dfs(l[x]);
  if (t[x] == 0) {
    dp[x] &= dfs(r[x]);
  } else if (t[x] == 1) {
    dp[x] |= dfs(r[x]);
  } else if (t[x] == 2) {
    dp[x] ^= dfs(r[x]);
  } else if (t[x] == 3) {
    dp[x] = 1 ^ dp[x];
  }
  return dp[x];
}
bool ans[MAX_N];
bool change(int x) {
  if (t[x] == 4) {
    ans[x] = true;
    return true;
  }
  if (t[x] == 0) {
    int cse = dp[l[x]] + 2 * dp[r[x]];
    if (cse == 0) {
      ans[x] = false;
    } else if (cse == 1) {
      ans[x] = change(r[x]);
    } else if (cse == 2) {
      ans[x] = change(l[x]);
    } else {
      ans[x] = change(l[x]) | change(r[x]);
    }
  } else if (t[x] == 1) {
    int cse = dp[l[x]] + 2 * dp[r[x]];
    if (cse == 0) {
      ans[x] = change(l[x]) | change(r[x]);
    } else if (cse == 1) {
      ans[x] = change(l[x]);
    } else if (cse == 2) {
      ans[x] = change(r[x]);
    } else {
      ans[x] = false;
    }
  } else if (t[x] == 2) {
    ans[x] = change(l[x]) | change(r[x]);
  } else if (t[x] == 3) {
    ans[x] = change(l[x]);
  }
  return ans[x];
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    string code;
    cin >> code;
    t[i] = encode(code);
    if (t[i] == 3) {
      cin >> l[i];
    } else if (t[i] == 4) {
      cin >> dp[i];
    } else {
      cin >> l[i] >> r[i];
    }
  }
  dfs(1);
  change(1);
  for (int i = 1; i <= n; i++) {
    if (t[i] == 4 && !ans[i]) {
      cout << dp[1];
    } else if (t[i] == 4) {
      cout << (1 ^ dp[1]);
    }
  }
  return 0;
}
