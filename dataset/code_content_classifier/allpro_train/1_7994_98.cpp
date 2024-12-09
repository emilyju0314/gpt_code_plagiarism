#include <bits/stdc++.h>
using namespace std;
int n, p[50];
int a, b, c, d, e;
long long ansA, ansB, ansC, ansD, ansE;
long long curAmount = 0;
void getPrize() {
  ansE += curAmount / e;
  curAmount -= e * (curAmount / e);
  ansD += curAmount / d;
  curAmount -= d * (curAmount / d);
  ansC += curAmount / c;
  curAmount -= c * (curAmount / c);
  ansB += curAmount / b;
  curAmount -= b * (curAmount / b);
  ansA += curAmount / a;
  curAmount -= a * (curAmount / a);
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> p[i];
  cin >> a >> b >> c >> d >> e;
  for (int i = 0; i < n; i++) {
    curAmount += p[i];
    getPrize();
  }
  cout << ansA << " " << ansB << " " << ansC << " " << ansD << " " << ansE
       << endl
       << curAmount;
  return 0;
}
