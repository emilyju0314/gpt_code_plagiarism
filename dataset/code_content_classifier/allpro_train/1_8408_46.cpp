#include <bits/stdc++.h>
using namespace std;
int arr[100005];
int freq[100005];
queue<pair<int, int> > groups[100005];
int main(int argc, char* argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> arr[i];
  for (int i = 0; i < n; i++) freq[n - arr[i]]++;
  int q = 1;
  for (int i = 1; i < n + 1; i++) {
    if (freq[i] % i != 0) {
      cout << "Impossible" << endl;
      return 0;
    } else {
      for (int j = 0; j < freq[i] / i; j++) {
        groups[i].push(make_pair(q++, i));
      }
    }
  }
  cout << "Possible" << endl;
  for (int i = 0; i < n; i++) {
    groups[n - arr[i]].front().second--;
    cout << groups[n - arr[i]].front().first << " ";
    if (groups[n - arr[i]].front().second == 0) groups[n - arr[i]].pop();
  }
  cout << endl;
  return 0;
}
