#include <bits/stdc++.h>
using namespace std;
const int N = 10e5 + 2;
long long n;
long long int arr[N];
stack<char> st;
int pluss = 0, minuss = 0;
int main() {
  string str;
  cin >> str;
  int counter = 0, counter2 = 0;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] == '+') {
      pluss++;
      if (minuss > 0) minuss--;
    } else {
      minuss++;
      if (pluss > 0) pluss--;
    }
  }
  cout << minuss + pluss;
}
