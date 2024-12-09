#include <bits/stdc++.h>
using namespace std;
void pv(vector<int> amount) {
  for (auto i = amount.begin(); i != amount.end(); i++) cout << *i << " ";
  cout << endl;
}
void pv(vector<long long> amount) {
  for (auto i = amount.begin(); i != amount.end(); i++) cout << *i << " ";
  cout << endl;
}
void pv(vector<double> amount) {
  for (auto i = amount.begin(); i != amount.end(); i++) cout << *i << " ";
  cout << endl;
}
void pv(vector<string> amount) {
  for (auto i = amount.begin(); i != amount.end(); i++) cout << *i << " ";
  cout << endl;
}
void pv(vector<bool> amount) {
  for (auto i = amount.begin(); i != amount.end(); i++) cout << *i << " ";
  cout << endl;
}
int main() {
  ios_base::sync_with_stdio(0);
  long long t;
  cin >> t;
  for (int j = 0; j < t; j++) {
    long long n, k;
    cin >> n >> k;
    long long arr[n];
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
    }
    long long max = *max_element(arr, arr + n);
    long long min = *min_element(arr, arr + n);
    if (k % 2 == 0) {
      k = 2;
    } else {
      k = 1;
    }
    while (k > 0) {
      for (int i = 0; i < n; i++) {
        arr[i] = max - arr[i];
      }
      max = max - min;
      min = 0;
      k--;
    }
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
}
