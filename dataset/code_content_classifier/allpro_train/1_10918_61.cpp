#include <bits/stdc++.h>
using namespace std;
int main() {
  int tc;
  cin >> tc;
  while (tc--) {
    long long int cnt = 0;
    long long int n;
    cin >> n;
    long long int arr[n];
    long long int brr[n];
    long long int min1, min2, max1, max2;
    vector<pair<long long int, long long int> > vect;
    vector<int> v;
    for (auto i = 0; i < n; i++) {
      long long int a, b;
      cin >> a;
      vect.push_back(make_pair(a, i));
      cin >> arr[i];
    }
    sort(vect.begin(), vect.end());
    long long int x = vect[0].first;
    long long int y = arr[vect[0].second];
    brr[vect[0].second] = 1;
    for (auto i = 1; i < n; i++) {
      if ((vect[i].first >= x and vect[i].first <= y) or
          (arr[vect[i].second] >= x and arr[vect[i].second] <= y) or
          (vect[i].first < x and arr[vect[i].second] > y)) {
        brr[vect[i].second] = 1;
        if (x > vect[i].first) x = vect[i].first;
        if (y < arr[vect[i].second]) y = arr[vect[i].second];
      } else {
        cnt++;
        brr[vect[i].second] = 2;
      }
    }
    if (cnt == n or cnt == 0)
      cout << "-1\n";
    else {
      for (auto i = 0; i < n; i++) cout << brr[i] << " ";
      cout << "\n";
    }
  }
}
