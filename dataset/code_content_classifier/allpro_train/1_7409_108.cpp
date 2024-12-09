#include <bits/stdc++.h>
using namespace std;
int A, B, N, Low, High;
set<int> Div;
int GCD(int A, int B) {
  if (!B) return A;
  return GCD(B, A % B);
}
int main() {
  scanf("%i %i", &A, &B);
  int D = GCD(A, B);
  for (int i = 1; 1LL * i * i <= D; ++i)
    if (D % i == 0) Div.insert(i), Div.insert(D / i);
  scanf("%i", &N);
  for (; N; N--) {
    scanf("%i %i", &Low, &High);
    set<int>::iterator it = Div.lower_bound(High);
    int Val = -1;
    if (it == Div.end() || !(Low <= *it && *it <= High)) {
      if (it != Div.begin()) --it;
      if (Low <= *it && *it <= High) Val = *it;
    } else if (Low <= *it && *it <= High)
      Val = *it;
    printf("%i\n", Val);
  }
}
