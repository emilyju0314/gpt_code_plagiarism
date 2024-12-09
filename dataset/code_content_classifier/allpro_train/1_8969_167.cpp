#include <bits/stdc++.h>
using namespace std;
long long int isprime[1000001];
long long GCD(long long A, long long B) {
  if (B == 0)
    return A;
  else
    return GCD(B, A % B);
}
void sieve() {
  fill_n(isprime, 1000001, 1);
  isprime[0] = 0;
  isprime[1] = 0;
  for (int i = 2; i * i <= 1000000; i++) {
    if (isprime[i] == 1) {
      for (int j = i * i; j <= 1000000; j += i) isprime[j] = 0;
    }
  }
}
void fastfactor() {
  fill_n(isprime, 1000001, 0);
  isprime[0] = 1;
  isprime[1] = 1;
  for (int i = 2; i * i <= 1000000; i++) {
    if (isprime[i] == 0) {
      for (int j = i * i; j <= 1000000; j += i)
        if (isprime[j] == 0) isprime[j] = i;
    }
  }
  for (int i = 2; i * i <= 1000000; i++) {
    if (isprime[i] == 0) isprime[i] = i;
  }
}
long long int modpow(long long int x, long long int n, long long int M) {
  if (n == 0) {
    return 1;
  } else if (n == 1) {
    return x % M;
  } else if (n % 2 == 0) {
    return modpow((x * x) % M, n / 2, M);
  } else {
    return (x * modpow((x * x) % M, (n - 1) / 2, M)) % M;
  }
}
int main() {
  long long a, b, cc;
  cin >> a >> b >> cc;
  long long m;
  cin >> m;
  deque<long long> usb, ps2;
  while (m--) {
    int x;
    string s;
    cin >> x >> s;
    if (s == "USB")
      usb.push_back(x);
    else
      ps2.push_back(x);
  }
  sort(usb.begin(), usb.end());
  sort(ps2.begin(), ps2.end());
  long long c = 0, cost = 0;
  while (!usb.empty() && a > 0) {
    cost += usb.front();
    usb.pop_front();
    c++;
    a--;
  }
  while (!ps2.empty() && b > 0) {
    cost += ps2.front();
    ps2.pop_front();
    c++;
    b--;
  }
  while ((!usb.empty() || !ps2.empty()) && cc > 0) {
    if (usb.empty()) {
      cost += ps2.front();
      ps2.pop_front();
    } else if (ps2.empty()) {
      cost += usb.front();
      usb.pop_front();
    } else if (usb.front() < ps2.front()) {
      cost += usb.front();
      usb.pop_front();
    } else {
      cost += ps2.front();
      ps2.pop_front();
    }
    c++;
    cc--;
  }
  cout << c << " " << cost;
  printf("\n");
}
