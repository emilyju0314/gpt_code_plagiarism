#include <bits/stdc++.h>
using namespace std;
int N;
int D[1 << 16], S[1 << 16];
int main() {
  scanf("%d", &N);
  for (int i = 0, i_len = (N); i < i_len; ++i) scanf("%d%d", D + i, S + i);
  stack<int> st;
  for (int i = 0, i_len = (N); i < i_len; ++i)
    if (D[i] == 1) st.push(i);
  vector<int> A, B;
  while (st.size()) {
    int v = st.top();
    st.pop();
    if (D[v] != 1) continue;
    A.push_back(v);
    B.push_back(S[v]);
    D[S[v]]--;
    S[S[v]] ^= v;
    if (D[S[v]] == 1) st.push(S[v]);
  }
  printf("%d\n", (int)A.size());
  for (int i = 0, i_len = (A.size()); i < i_len; ++i) {
    printf("%d %d\n", A[i], B[i]);
  }
  return 0;
}
