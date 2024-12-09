#include <bits/stdc++.h>
using namespace std;
long long cnt[200009];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  memset(cnt, -1, sizeof cnt);
  long long i, j, k, l, m, n, a, b;
  long long mn = 0;
  string s;
  cin >> s;
  n = s.size();
  stack<long long> st;
  a = -1, b = -3;
  for (i = 0; i < n; i++) {
    if (s[i] == '(') st.push(i);
    if (s[i] == '[') st.push(i);
    if (s[i] == ')') {
      if (st.size() && s[st.top()] == '(') {
        cnt[st.top()] = i;
        st.pop();
      } else {
        while (st.size()) st.pop();
      }
    }
    if (s[i] == ']') {
      if (st.size() && s[st.top()] == '[') {
        cnt[st.top()] = i;
        st.pop();
      } else {
        while (st.size()) st.pop();
      }
    }
  }
  long long pok;
  for (i = n - 2; i >= 0; i--) {
    if (cnt[i] != -1 && cnt[i] + 1 < n) {
      cnt[i] = max(cnt[i], cnt[cnt[i] + 1]);
    }
  }
  for (i = 0; i < n;) {
    if (s[i] == ')' || s[i] == ']' || cnt[i] == -1) {
      i++;
      continue;
    }
    pok = 0;
    for (j = i; j <= cnt[i]; j++) {
      if (s[j] == '[') pok++;
    }
    if (pok > mn) {
      mn = pok;
      a = i;
      b = cnt[i];
    }
    i = j;
  }
  cout << mn << '\n';
  for (i = a; i <= b; i++) cout << s[i];
  cout << '\n';
}
