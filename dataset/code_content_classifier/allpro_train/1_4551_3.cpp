#include <bits/stdc++.h>
using namespace std;
int PASSED_POINT = 0;
void Duxar() {}
template <class T>
void read_int(T &_value) {
  T sign = 1;
  char ch;
  _value = 0;
  while (!isdigit(ch = getchar())) {
    (ch == '-') && (sign = -1);
  }
  do {
    _value = _value * 10 + (ch - '0');
  } while (isdigit(ch = getchar()));
  _value *= sign;
}
template <class T>
T add_nr(T a, T b) {
  T _res = a + b;
  return _res % 1000000007;
}
int N, S, K;
string station;
int main() {
  string aux;
  int i, dir = 1, lg;
  cin >> N >> S >> K;
  cin >> aux >> aux;
  cin >> station;
  lg = station.length();
  if (aux == "head") {
    dir = -1;
  }
  for (i = 0; i < lg - 1; ++i) {
    if (station[i] == '0') {
      if (S < K && S > 1) {
        --S;
      }
      if (S > K && S < N) {
        ++S;
      }
      K += dir;
      if (K == 0) {
        K = 2;
        dir = -dir;
      }
      if (K == N + 1) {
        K = N - 1;
        dir = -dir;
      }
      if (K == S) {
        printf("Controller %d\n", i + 1);
        return 0;
      }
    } else {
      K += dir;
      if (K == 0) {
        K = 2;
        dir = -dir;
      }
      if (K == N + 1) {
        K = N - 1;
        dir = -dir;
      }
      if (dir == 1) {
        if (K > 1)
          S = 1;
        else
          S = N;
      }
      if (dir == -1) {
        if (K < N)
          S = N;
        else
          S = 1;
      }
    }
  }
  printf("Stowaway\n");
  return 0;
}
