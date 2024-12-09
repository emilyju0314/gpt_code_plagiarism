#include <bits/stdc++.h>
using namespace std;
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << ' ' << H;
  debug_out(T...);
}
const long long MOD = 1e9 + 7;
void query(int a, int b, int c) {
  cout << "? " << a << " " << b << " " << c << "\n";
}
void solve() {
  int n, pos1 = 0, pos2 = 0;
  cin >> n;
  vector<int> a;
  for (int i = 1; i < n; i += 3) {
    query(i, i + 1, i + 2);
    int x;
    cin >> x;
    if (x == 1) {
      pos1 = i;
    } else {
      pos2 = i;
    }
    a.push_back(x);
  }
  vector<int> temp, temp1;
  for (int i = 0; i < 6; i++) {
    if (i < 3)
      temp.push_back(pos1 + i);
    else
      temp.push_back(pos2 + i - 3);
  };
  temp1.push_back(a[(pos1 - 1) / 3]);
  for (int i = 1; i < 3; i++) {
    query(temp[i], temp[i + 1], temp[i + 2]);
    int x;
    cin >> x;
    temp1.push_back(x);
  }
  temp1.push_back(a[(pos2 - 1) / 3]);
  vector<int> ans(n + 1, -1);
  int crewpos, imppos;
  for (int i = 1; i < 4; i++) {
    if (temp1[i] != temp1[i - 1]) {
      ans[temp[i - 1]] = temp1[i - 1];
      ans[temp[i + 2]] = temp1[i];
      query(temp[i - 1], temp[i], temp[i + 2]);
      cin >> ans[temp[i]];
      query(temp[i - 1], temp[i + 1], temp[i + 2]);
      cin >> ans[temp[i + 1]];
      crewpos = temp[i];
      imppos = temp[i + 1];
      break;
    }
  }
  if (!ans[crewpos]) {
    swap(crewpos, imppos);
  }
  for (int i = 0; i < 6; i++) {
    if (ans[temp[i]] == -1) {
      query(temp[i], crewpos, imppos);
      cin >> ans[temp[i]];
    }
  }
  for (int i = 0; i * 3 + 3 <= n; i++) {
    if (ans[i * 3 + 1] != -1) continue;
    if (a[i] == 0) {
      int x = i * 3 + 1, y = i * 3 + 2, z = i * 3 + 3, t1, t2;
      query(x, y, crewpos);
      cin >> t1;
      query(x, z, crewpos);
      cin >> t2;
      if (!t1 && !t2) {
        ans[x] = ans[y] = ans[z] = 0;
      }
      if (!t1 && t2) {
        ans[x] = 0;
        ans[y] = 0;
        ans[z] = 1;
      }
      if (t1 && !t2) {
        ans[x] = 0;
        ans[y] = 1;
        ans[z] = 0;
      }
      if (t1 && t2) {
        ans[x] = 1;
        ans[z] = 0;
        ans[y] = 0;
      }
    } else {
      int x = i * 3 + 1, y = i * 3 + 2, z = i * 3 + 3, t1, t2;
      query(x, y, imppos);
      cin >> t1;
      query(x, z, imppos);
      cin >> t2;
      if (!t1 && !t2) {
        ans[x] = 0;
        ans[y] = 1;
        ans[z] = 1;
      }
      if (!t1 && t2) {
        ans[x] = 1;
        ans[y] = 0;
        ans[z] = 1;
      }
      if (t1 && !t2) {
        ans[x] = 1;
        ans[y] = 1;
        ans[z] = 0;
      }
      if (t1 && t2) {
        ans[x] = 1;
        ans[z] = 1;
        ans[y] = 1;
      }
    }
  }
  vector<int> imposters;
  for (int i = 1; i <= n; i++) {
    if (!ans[i]) imposters.push_back(i);
  }
  cout << "! " << imposters.size() << " ";
  for (int x : imposters) {
    cout << x << " ";
  }
  cout << "\n";
  cout.flush();
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
