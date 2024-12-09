#include <bits/stdc++.h>
using namespace std;
struct pairs {
  long long first;
  long long second;
};
void generate(int numslot, int need, float &countans, int current) {
  if (need == current && numslot == 0) {
    countans += 1;
    return;
  }
  if (numslot == 0) {
    return;
  }
  generate(numslot - 1, need, countans, current + 1);
  generate(numslot - 1, need, countans, current - 1);
}
int factorial(int n) {
  if (n == 1) return 1;
  return n * factorial(n - 1);
}
bool checkout(int x1, int y1, int x2, int y2) {
  if (y1 < x2) return true;
  if (y2 < x1) return true;
  return false;
}
struct ranked {
  double height;
  int order;
};
void generate(int *a, int n, int index, bool &find, int total) {
  if (index == n) {
    if (total % 360 == 0) {
      find = true;
    }
    return;
  }
  generate(a, n, index + 1, find, total + a[index]);
  if (find == true) return;
  generate(a, n, index + 1, find, total - a[index]);
}
struct pair1 {
  int value;
  int fre;
};
bool sort11(pair1 x, pair1 y) { return x.fre < y.fre; }
int main() {
  int n, k;
  cin >> n >> k;
  int **a;
  a = new int *[10000];
  for (int i = 0; i < 10000; i++) {
    a[i] = new int[k];
    for (int j = 0; j < k; j++) {
      a[i][j] = 0;
    }
  }
  int fre[10000];
  for (int i = 0; i < 10000; i++) {
    fre[i] = 0;
  }
  int remain = k;
  int *input;
  input = new int[n];
  int maxfre = 0;
  for (int i = 0; i < n; i++) {
    cin >> input[i];
    fre[input[i]]++;
    if (fre[input[i]] > maxfre) maxfre = fre[input[i]];
  }
  if (maxfre > k)
    cout << "NO";
  else {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      if (a[input[i] - 1][remain - 1] == 1) {
        for (int j = 0; j < k; j++) {
          if (a[input[i] - 1][j] == 0) {
            cout << j + 1 << " ";
            a[input[i] - 1][j] = 1;
            break;
          }
        }
      } else {
        a[input[i] - 1][remain - 1] = 1;
        cout << remain << " ";
      }
      remain--;
      if (remain == 0) remain = k;
    }
  }
  return 0;
}
