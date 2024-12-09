#include <bits/stdc++.h>
using namespace std;
int B[1000006];
int main() {
  int cc = 1000000;
  int n;
  cin >> n;
  vector<int> p, A;
  multiset<int> K;
  multiset<int>::iterator itr, it, it1;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    A.push_back(a);
    K.insert(a);
  }
  int sum = 0;
  for (itr = K.begin(); itr != K.end(); itr++) {
    if (B[*itr] == 1) continue;
    it = K.find(cc + 1 - *itr);
    if (it == K.end()) {
      p.push_back(cc + 1 - *itr);
    } else {
      sum++;
    }
    B[*itr] = 1;
    B[cc + 1 - *itr] = 1;
  }
  for (int i = 1; i <= 1000000; i++) {
    if (sum == 0) break;
    if (B[i] == 0) {
      p.push_back(i);
      p.push_back(cc + 1 - i);
      B[i] = 1;
      B[cc + 1 - i] = 1;
      sum--;
    }
  }
  sort(p.begin(), p.end());
  cout << n << endl;
  for (int i = 0; i < n; i++) {
    printf("%d ", p[i]);
  }
}
