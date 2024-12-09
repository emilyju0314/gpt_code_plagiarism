#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long int n;
    cin >> n;
    long long int arr[n];
    long long int total = 0;
    for (int i = 0; i < n; i++) {
      cin >> arr[i];
      total += arr[i];
    }
    long long int sum = 0;
    long long int best = 0, m = 0;
    vector<long long int> ar;
    int flag = 0;
    int count = 0;
    int check = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] > 0) check = 1;
      if (arr[i] > m) m = arr[i];
      sum = sum + arr[i];
      count++;
      if (sum == 0) count = 0;
      if (sum < 0)
        sum = 0;
      else if (best < sum) {
        best = sum;
        if (best == total && count < n) flag = 1;
        ar.push_back(best);
      }
    }
    int s = ar.size();
    if (check == 1) {
      if (ar[s - 1] > total)
        cout << "NO\n";
      else if (ar[s - 1] == total && flag == 1)
        cout << "NO\n";
      else
        cout << "YES\n";
    } else
      cout << "NO\n";
  }
}
