#include <bits/stdc++.h>
using namespace std;
const long long MOD = 998244353;
const double oula = 0.57721566490153286060651209;
using namespace std;
int a[200005];
stack<int> st;
int main() {
  std::ios::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> a[i];
  }
  int k = n - m;
  int i = 1;
  int co = 1;
  int flag = 0;
  while (i <= m) {
    if (co != a[i]) {
      st.push(a[i]);
      i++;
    } else {
      co++;
      i++;
      while (!st.empty() && st.top() == co) {
        co++;
        st.pop();
      }
    }
  }
  if (!st.empty()) {
    int pre = st.top();
    st.pop();
    while (!st.empty()) {
      if (pre > st.top()) {
        flag = 1;
        break;
      }
      pre = st.top();
      st.pop();
    }
  }
  if (flag == 1) {
    cout << -1 << endl;
  } else {
    int i = 1;
    int co = 1;
    while (i <= m) {
      if (co != a[i]) {
        st.push(a[i]);
        i++;
      } else {
        co++;
        i++;
        while (!st.empty() && st.top() == co) {
          co++;
          st.pop();
        }
      }
    }
    while (!st.empty()) {
      int tmp = st.top();
      st.pop();
      for (i = tmp - 1; i >= co; i--) {
        a[++m] = i;
      }
      co = tmp + 1;
    }
    for (int i = n; i >= co; i--) a[++m] = i;
    for (int i = 1; i <= m; i++) {
      cout << a[i] << " ";
    }
  }
}
