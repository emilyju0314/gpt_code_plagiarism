#include <bits/stdc++.h>
using namespace std;
long long arr[77800], grundy[881925];
multiset<int> st;
void pre() {
  long long maxx = 881920;
  int l = 1, r = 1, nl, nr, j, i;
  grundy[1] = 0;
  st.insert(grundy[1]);
  for (i = 2; i <= maxx; i++) {
    nl = ceil(sqrt((double)sqrt(i)));
    nr = sqrt(i);
    if (nr < nl) continue;
    while (r < nr) {
      r++;
      st.insert(grundy[r]);
    }
    while (l < nl) {
      multiset<int>::iterator it = st.find(grundy[l]);
      st.erase(it);
      l++;
    }
    j = 0;
    while (st.find(j) != st.end()) j++;
    grundy[i] = j;
  }
  st.clear();
}
int main() {
  long long n, ans = 0;
  long long l = 1, r = 1, nl, nr, j, i;
  scanf("%I64d", &n);
  for (i = 0; i < n; i++) scanf("%I64d", &arr[i]);
  pre();
  sort(arr, arr + n);
  l = r = 1;
  st.insert(grundy[1]);
  for (i = 0; i < n; i++) {
    if (arr[i] == 1) continue;
    nl = ceil(sqrt((double)sqrt(arr[i])));
    nr = sqrt(arr[i]);
    if (nr < nl) continue;
    while (r < nr) {
      r++;
      st.insert(grundy[r]);
    }
    while (l < nl) {
      multiset<int>::iterator it = st.find(grundy[l]);
      st.erase(it);
      l++;
    }
    j = 0;
    while (st.find(j) != st.end()) j++;
    ans ^= j;
  }
  if (ans == 0)
    printf("Rublo\n");
  else
    printf("Furlo\n");
  return 0;
}
