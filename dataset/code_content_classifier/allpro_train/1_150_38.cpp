#include <bits/stdc++.h>
std::vector<int> A['   '];
int N, M, S['   '], B, L, R, I;
void U(int z, int u) {
  while (z <= N)
    S[z] += u, z += z & -z;
}
int main() {
  ~scanf("%d%d", &M, &N);
  for (; ~scanf("%d%d", &L, &R);)
    A[R - L + 1]
        .push_back(L);
  for (L = 1; L <= N; L++) {
    B = M;
    for (I = L; I <= N; I += L) {
      R = I;
      while (R)
        B += S[R], R -= R & -R;
    }
    for (int u : A[L])
      U(u, 1), U(u + L, -1), M--;
    printf("%d\n", B);
  }
}