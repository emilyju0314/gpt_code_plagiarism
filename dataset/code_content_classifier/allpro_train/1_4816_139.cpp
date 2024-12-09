#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> countOnes(vector<string> &matrix, int n, int m) {
  vector<vector<int>> ones = vector<vector<int>>(n);
  for (int i = 0; i < n; i++) {
    ones[i] = vector<int>(m, 0);
  }
  int temp;
  ones[0][0] = (matrix[0][0] == '1') ? 1 : 0;
  for (int i = 1; i < n; i++) {
    temp = (matrix[i][0] == '1') ? 1 : 0;
    ones[i][0] = ones[i - 1][0] + temp;
  }
  for (int i = 1; i < m; i++) {
    temp = (matrix[0][i] == '1') ? 1 : 0;
    ones[0][i] = ones[0][i - 1] + temp;
  }
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      temp = (matrix[i][j] == '1') ? 1 : 0;
      ones[i][j] = temp - ones[i - 1][j - 1] + ones[i - 1][j] + ones[i][j - 1];
    }
  }
  return ones;
}
int cost(int k, vector<vector<int>> &count, int n, int m) {
  int step = 0;
  for (int i = 0; i < n; i += k) {
    for (int j = 0; j < m; j += k) {
      int i_end = (i + k - 1 < n) ? (i + k - 1) : (n - 1);
      int j_end = (j + k - 1 < m) ? (j + k - 1) : (m - 1);
      int a, b, c;
      if (i - 1 < 0)
        b = 0;
      else
        b = count[i - 1][j_end];
      if (j - 1 < 0)
        c = 0;
      else
        c = count[i_end][j - 1];
      if (j - 1 < 0 || i - 1 < 0)
        a = 0;
      else
        a = count[i - 1][j - 1];
      int ones = count[i_end][j_end] + a - b - c;
      step += min({ones, k * k - ones});
    }
  }
  return step;
}
int main() {
  int n, m;
  vector<string> matrix;
  vector<int> used_k;
  cin >> n >> m;
  getchar();
  matrix = vector<string>(n);
  for (int i = 0; i < n; i++) {
    getline(cin, matrix[i]);
  }
  vector<vector<int>> count = countOnes(matrix, n, m);
  int minStep = m * n;
  int k = 2;
  while (k <= n || k <= m) {
    int step = 0;
    bool ok = true;
    for (int i = 2; i < sqrt(k); i++) {
      if (k != 2 && k % i == 0) {
        ok = false;
        break;
      }
    }
    if (ok) {
      step = cost(k, count, n, m);
      minStep = min({minStep, step});
    }
    k++;
  }
  cout << minStep << endl;
  return 0;
}
