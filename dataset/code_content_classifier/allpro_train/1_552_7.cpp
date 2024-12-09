#include <bits/stdc++.h>
long long int count_odd = 0;
long long int count_even = 0;
using namespace std;
void total_count(string str) {
  long long int o[2], e[2];
  o[0] = o[1] = e[0] = e[1] = 0;
  for (long long int i = 0; i < str.length(); i++) {
    count_odd++;
    int id = (str[i] == 'a') ? 0 : 1;
    if (i % 2 == 0) {
      count_even += o[id];
      count_odd += e[id];
      e[id]++;
    } else {
      count_even += e[id];
      count_odd += o[id];
      o[id]++;
    }
  }
}
int main() {
  string str;
  cin >> str;
  total_count(str);
  cout << count_even << ' ' << count_odd << '\n';
}
