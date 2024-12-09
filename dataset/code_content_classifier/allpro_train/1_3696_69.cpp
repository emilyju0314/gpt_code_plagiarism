#include <bits/stdc++.h>
using namespace std;
template <class T>
T gcd(T a, T b) {
  return (b != 0 ? gcd<T>(b, a % b) : a);
}
template <class T>
T lcm(T a, T b) {
  return (a / gcd<T>(a, b) * b);
}
double tick() {
  static clock_t oldt, newt = clock();
  double diff = 1.0 * (newt - oldt) / CLOCKS_PER_SEC;
  oldt = newt;
  return diff;
}
float roundoff(float val, float p) {
  return floor(val * pow(10.0, p) + 0.5) / pow(10.0, p);
}
const int INF = 0x3f3f3f3f;
int main(void) {
  ios_base::sync_with_stdio(true);
  cin.tie(NULL);
  cout.tie(NULL);
  string str;
  cin >> str;
  int idx = -1;
  for (int i = 0; i < str.length(); i++) {
    if (str[i] == '1') {
      idx = i;
      break;
    }
  }
  if (idx == -1) {
    cout << "no";
    return 0;
  } else {
    int cnt = 0;
    for (int i = idx; i < str.length(); i++) {
      if (str[i] == '0') cnt++;
    }
    if (cnt >= 6) {
      cout << "yes";
    } else {
      cout << "no";
    }
  }
  return 0;
}
