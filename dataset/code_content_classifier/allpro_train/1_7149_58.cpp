#include <bits/stdc++.h>
using namespace std;
constexpr int INF = 1000000000;
typedef long long ll;
void print(const char* msg, ...);
inline unsigned long long exp10(int e) {
  if (e == 0) return 1;
  return (e == 1) ? 10 : 10 * exp10(e - 1);
}
int main() {
  int N;
  unsigned long long n;
  char command;
  map<unsigned long long, int> m;
  unsigned long long pot[18];
  for (int i = 0; i < 18; i++) pot[i] = exp10(i);
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    scanf("\n%c %llu", &command, &n);
    if (command == '+') {
      unsigned long long ind = 0;
      for (int i = 0; i < 18; i++) ind += ((n / pot[i]) % 2) * pot[i];
      m[ind] += 1;
    } else if (command == '-') {
      unsigned long long ind = 0;
      for (int i = 0; i < 18; i++) ind += ((n / pot[i]) % 2) * pot[i];
      m[ind] -= 1;
    } else
      printf("%d\n", m[n]);
  }
  return EXIT_SUCCESS;
}
void print(const char* msg, ...) {}
