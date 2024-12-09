#include <bits/stdc++.h>
using namespace std;

int N, K, a;
string s;

int main() {
  cin >> N >> K;
  cin >> s;
  
  for (int i = 1; i < N; i++) {
    if (s[i] != s[i-1]) {
      a++;
    }
  }
  a = N - a - 1;
  cout << min(N-1, a + 2*K);
}