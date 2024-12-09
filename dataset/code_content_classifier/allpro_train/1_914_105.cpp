#include <bits/stdc++.h>
using namespace std;
int N;
vector<int> original;
int abs(int x) {
  if (x < 0) return -1 * x;
  return x;
}
int main() {
  cin >> N;
  original.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> original[i];
  }
  int onesLocation;
  for (onesLocation = 0; onesLocation < N; onesLocation++) {
    if (original[onesLocation] == 1) break;
  }
  int nsLocation;
  for (nsLocation = 0; nsLocation < N; nsLocation++) {
    if (original[nsLocation] == N) break;
  }
  int maxDistance = abs(onesLocation - nsLocation);
  for (int i = 0; i < N; i++) {
    if (i == nsLocation || i == onesLocation) continue;
    if (abs(nsLocation - i) > maxDistance) maxDistance = abs(nsLocation - i);
  }
  for (int i = 0; i < N; i++) {
    if (i == onesLocation || i == nsLocation) continue;
    if (abs(onesLocation - i) > maxDistance)
      maxDistance = abs(onesLocation - i);
  }
  cout << maxDistance << endl;
  return 0;
}
