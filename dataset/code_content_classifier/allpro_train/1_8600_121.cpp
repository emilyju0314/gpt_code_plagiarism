#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int arr[n + 1];
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    arr[k] = i + 1;
  }
  int m;
  long long int vas = 0, pet = 0;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    vas += arr[k];
    pet += n + 1 - arr[k];
  }
  cout << vas << " " << pet;
  return 0;
}
