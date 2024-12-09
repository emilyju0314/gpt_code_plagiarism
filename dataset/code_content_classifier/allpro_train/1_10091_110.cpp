#include <bits/stdc++.h>
using namespace std;
int s1[100], s2[100], cross[100];
int n;
int minGo() {
  int result = 99999;
  int resultIndex;
  int actual;
  for (int i = 0; i < n; i++) {
    actual = 0;
    for (int j = 0; j < i; j++) {
      actual += s1[j];
    }
    actual += cross[i];
    for (int j = i; j < n - 1; j++) {
      actual += s2[j];
    }
    if (actual < result) {
      result = actual;
      resultIndex = i;
    }
  }
  cross[resultIndex] = 99999;
  return result;
}
int minBack() {
  int result = 99999;
  int actual;
  for (int i = n - 1; i >= 0; i--) {
    actual = 0;
    for (int j = n - 1; j > i; j--) {
      actual += s2[j - 1];
    }
    actual += cross[i];
    for (int j = i - 1; j >= 0; j--) {
      actual += s1[j];
    }
    if (actual < result) {
      result = actual;
    }
  }
  return result;
}
int main() {
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    cin >> s1[i];
  }
  for (int i = 0; i < n - 1; i++) {
    cin >> s2[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> cross[i];
  }
  cout << minGo() + minBack() << endl;
  return 0;
}
