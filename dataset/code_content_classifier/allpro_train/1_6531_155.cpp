#include <bits/stdc++.h>
using namespace std;
const long long inf = 2e9;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  vector<int> arr;
  cin >> n;
  while (n--) {
    long long temp;
    cin >> temp;
    arr.push_back(temp);
  }
  sort(arr.begin(), arr.end());
  if (arr[0] == arr[arr.size() - 1]) {
    long long wow = arr.size();
    wow = wow * (wow - (long long)1) / (long long)2;
    cout << "0 " << wow << "\n";
    return 0;
  }
  long long max_a = 0, min_a = 0;
  for (auto i : arr) {
    if (i == arr[0]) max_a++;
    if (i == arr[arr.size() - 1]) min_a++;
  }
  max_a *= min_a;
  cout << arr[arr.size() - 1] - arr[0] << " " << max_a << "\n";
  return 0;
}
