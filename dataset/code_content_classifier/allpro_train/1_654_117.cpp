#include <bits/stdc++.h>
using namespace std;
string a, b;
int aa[26], bb[26];
vector<int> av, bv;
char ans[300010];
int first = 0, last;
int main() {
  cin >> a >> b;
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<char>());
  for (int i = 0; i < (a.size() + 1) / 2; ++i) ++aa[a[i] - 'a'];
  for (int i = 0; i < (a.size()) / 2; ++i) ++bb[b[i] - 'a'];
  last = a.size() - 1;
  for (int i = 0; i < a.size(); ++i) {
    if (i % 2 == 0) {
      char c, cc;
      for (int j = 0; j < 26; ++j) {
        if (aa[j]) {
          c = 'a' + j;
          break;
        }
      }
      for (int j = 25; j >= 0; --j) {
        if (bb[j]) {
          cc = 'a' + j;
          break;
        }
      }
      if (cc > c) {
        ans[first++] = c;
        --aa[c - 'a'];
      } else {
        for (int j = 25; j >= 0; --j) {
          if (aa[j]) {
            ans[last--] = 'a' + j;
            --aa[j];
            break;
          }
        }
      }
    } else {
      char c, cc;
      for (int j = 0; j < 26; ++j) {
        if (aa[j]) {
          cc = 'a' + j;
          break;
        }
      }
      for (int j = 25; j >= 0; --j) {
        if (bb[j]) {
          c = 'a' + j;
          break;
        }
      }
      if (cc < c) {
        ans[first++] = c;
        --bb[c - 'a'];
      } else {
        for (int j = 0; j < 26; ++j) {
          if (bb[j]) {
            ans[last--] = 'a' + j;
            --bb[j];
            break;
          }
        }
      }
    }
  }
  for (int i = 0; i < a.size(); ++i) putchar(ans[i]);
  cout << endl;
  return 0;
}
