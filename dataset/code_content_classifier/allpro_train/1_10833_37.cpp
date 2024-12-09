#include <bits/stdc++.h>
using namespace std;
int isprime[1000005];
void seive() {
  memset(isprime, 1, sizeof isprime);
  for (int i = 2; i <= 1000000; ++i) {
    if (isprime[i]) {
      for (int j = i + i; j <= 1000000; j += i) isprime[j] = 0;
    }
  }
  isprime[1] = isprime[0] = 0;
  return;
}
int main() {
  seive();
  int n;
  cin >> n;
  int cnt[3] = {0};
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int curr = 0;
  while (1) {
    if (isprime[curr + 1] && cnt[1]) {
      cnt[1]--;
      curr += 1;
      cout << 1 << " ";
    } else if (isprime[curr + 2] && cnt[2]) {
      cnt[2]--;
      curr += 2;
      cout << 2 << " ";
    } else if (cnt[2]) {
      curr += 2;
      cout << 2 << " ";
      cnt[2]--;
    } else if (cnt[1]) {
      curr += 1;
      cout << 1 << " ";
      cnt[1]--;
    } else
      break;
  }
  cout << endl;
}
