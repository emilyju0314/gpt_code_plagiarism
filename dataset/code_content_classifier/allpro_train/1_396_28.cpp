#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  map<int, int> mp;
  mp.clear();
  cin >> num;
  long long* array_long = new long long[num];
  long double result = 0;
  for (int i = 0; i < num; i++) {
    cin >> array_long[i];
  }
  long double sum = 0;
  for (int i = 0; i < num; i++) {
    result +=
        i * array_long[i] - sum + mp[array_long[i] + 1] - mp[array_long[i] - 1];
    sum += array_long[i];
    mp[array_long[i]]++;
  }
  cout << fixed << setprecision(0) << result << endl;
  delete[] array_long;
  return 0;
}
