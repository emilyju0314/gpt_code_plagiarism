#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, vectSize, k;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> vectSize >> k;
    vector<int> vectA(vectSize);
    vector<int> vectB(vectSize);
    for (int j = 0; j < vectSize; j++) {
      cin >> vectA[j];
    }
    for (int j = 0; j < vectSize; j++) {
      cin >> vectB[j];
    }
    sort(vectA.begin(), vectA.end());
    sort(vectB.begin(), vectB.end(), greater<int>());
    for (int x = 0; x < vectSize; x++) {
      for (int y = 0; y < vectSize; y++) {
        if (vectA[x] < vectB[y]) {
          if (k > 0) {
            swap(vectA[x], vectB[y]);
            k--;
          } else {
            break;
          }
        }
      }
      if (k <= 0) {
        break;
      }
    }
    cout << accumulate(vectA.begin(), vectA.end(), 0) << endl;
  }
  return 0;
}
