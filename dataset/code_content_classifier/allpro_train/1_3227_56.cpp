#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, sum = 0;
  vector<int> arr;
  cin >> n;
  while (n--) {
    int num;
    cin >> num;
    sum += num;
    arr.push_back(num);
  }
  sort(arr.begin(), arr.end(), greater<int>());
  int temp = 0, count = 0;
  for (int num : arr) {
    temp += num;
    if (temp <= sum / 2) count++;
  }
  cout << count + 1 << endl;
}
