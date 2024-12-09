#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> container;
int a, b, c;
int diffc(vector<int> aVi) {
  int maxz = aVi[1] - aVi[0];
  for (int i = 0; i < aVi.size() - 1; i++) {
    if (aVi[i + 1] - aVi[i] > maxz) maxz = aVi[i + 1] - aVi[i];
  }
  return maxz;
}
int minDiff(vector<int> aVi) {
  vector<int> bVi;
  int minim = 1001;
  for (vector<int>::iterator it = aVi.begin() + 1; it < aVi.end() - 1; it++) {
    bVi.clear();
    bVi = aVi;
    c = it - aVi.begin();
    bVi.erase(bVi.begin() + c);
    b = diffc(bVi);
    if (b < minim) minim = b;
  }
  return minim;
}
int main() {
  scanf("%d", &n);
  container.clear();
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    container.push_back(a);
  }
  printf("%d\n", minDiff(container));
}
