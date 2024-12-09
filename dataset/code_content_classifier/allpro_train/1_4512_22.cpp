#include <bits/stdc++.h>
using namespace std;
struct shitClass {};
template <class T>
shitClass& operator<<(shitClass& c1, const T&) {
  return c1;
};
shitClass cerr1;
ostream& operator<<(ostream& os, const vector<long long>& a) {
  for (int i = 0; i < a.size(); i++) os << a[i] << " ";
  return os;
}
ostream& operator<<(ostream& os, const pair<long long, long long>& a) {
  os << a.first << " " << a.second;
  return os;
}
ostream& operator<<(ostream& os, const vector<int>& a) {
  for (int i = 0; i < a.size(); i++) os << a[i] << " ";
  return os;
}
istream& operator>>(istream& is, pair<long long, long long>& a) {
  is >> a.first >> a.second;
  return is;
}
long long n;
vector<vector<vector<long long> > > ask;
bool det(bool var, bool isPal) {
  if (var && isPal) return 1;
  if (!var && isPal) return 0;
  if (var && !isPal) return 0;
  return 1;
}
vector<vector<long long> > fillTable(vector<vector<long long> > field,
                                     bool isOdd) {
  if (!isOdd) {
    for (int i = 0; i < n; i++) {
      cerr1 << "i = " << i << '\n';
      for (int j = (i % 2 == 0 ? 2 : 3); j < n; j += 2)
        field[i][j] = det(field[i][j - 2], ask[i][j - 2][0]);
      if (i == 0) {
        field[i + 1][1] = det(field[i][0], ask[i][0][2]);
      }
      if (i < n - 2) {
        field[i + 2][i % 2 == 0 ? 0 : 1] =
            det(field[i][i % 2 == 0 ? 0 : 1], ask[i][i % 2 == 0 ? 0 : 1][1]);
      }
    }
  } else {
    for (int i = 0; i < n; i++) {
      for (int j = (i % 2 == 1 ? 2 : 3); j < n; j += 2)
        field[i][j] = det(field[i][j - 2], ask[i][j - 2][0]);
      if (i == 0) {
        field[i + 1][2] = det(field[i][1], ask[i][1][2]);
        field[i + 1][0] = det(field[i + 1][2], ask[i + 1][0][0]);
      }
      if (i < n - 2) {
        field[i + 2][i % 2 == 0 ? 1 : 0] =
            det(field[i][i % 2 == 0 ? 1 : 0], ask[i][i % 2 == 0 ? 1 : 0][1]);
      }
    }
  }
  return field;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  ask.resize(n, vector<vector<long long> >(n, vector<long long>(3)));
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n - 2; j++) {
      cout << "? " << i + 1 << " " << j + 1 << " " << i + 1 << " " << j + 3
           << '\n';
      cout.flush();
      cin >> ask[i][j][0];
    }
  for (int i = 0; i < n - 2; i++) {
    for (int j = 0; j < 2; j++) {
      cout << "? " << i + 1 << " " << j + 1 << " " << i + 3 << " " << j + 1
           << '\n';
      cout.flush();
      cin >> ask[i][j][1];
    }
  }
  cout << "? " << 1 << " " << 1 << " " << 2 << " " << 2 << '\n';
  cout.flush();
  cin >> ask[0][0][2];
  cout << "? " << n - 1 << " " << 1 << " " << n << " " << 2 << '\n';
  cout.flush();
  cin >> ask[n - 2][0][2];
  cout << "? " << 1 << " " << 2 << " " << 2 << " " << 3 << '\n';
  cout.flush();
  cin >> ask[0][1][2];
  vector<vector<long long> > field(n, vector<long long>(n));
  field[0][0] = 1;
  field = fillTable(field, 0);
  field = fillTable(field, 1);
  bool flag = 1;
  int answer = -1;
  for (int i = 0; i < n - 3 && flag; i++) {
    if (ask[i][0][1] == ask[i + 1][0][1]) {
      cout << "? " << i + 1 << " " << 1 << " " << i + 4 << " " << 1 << '\n';
      cout.flush();
      long long x;
      cin >> x;
      if ((ask[i][0][1] && x) || (!ask[i][0][1] && !x)) {
        answer = (field[i][0] == field[i + 1][0]);
      } else {
        answer = (field[i][0] != field[i + 1][0]);
      }
      flag = 0;
    }
  }
  if (flag) {
    if (ask[n - 3][0][1] == ask[n - 2][0][2]) {
      cout << "? " << n - 2 << " " << 1 << " " << n << " " << 2 << '\n';
      cout.flush();
      long long x;
      cin >> x;
      if ((ask[n - 3][0][1] && x) || (!ask[n - 3][0][1] && !x)) {
        answer = (field[n - 3][0] == field[n - 2][0]);
      } else {
        answer = (field[n - 3][0] != field[n - 2][0]);
      }
      flag = 0;
    }
  }
  if (flag) {
    if (ask[n - 2][0][2] == ask[n - 1][0][0]) {
      cout << "? " << n - 1 << " " << 1 << " " << n << " " << 3 << '\n';
      cout.flush();
      long long x;
      cin >> x;
      if ((ask[n - 2][0][2] && x) || (!ask[n - 2][0][2] && !x)) {
        answer = (field[n - 2][0] == field[n - 1][0]);
      } else {
        answer = (field[n - 2][0] != field[n - 1][0]);
      }
      flag = 0;
    }
  }
  for (int i = 0; i < n - 3 && flag; i++) {
    if (ask[n - 1][i][0] == ask[n - 1][i + 1][0]) {
      cout << "? " << n << " " << i + 1 << " " << n << " " << i + 4 << '\n';
      cout.flush();
      long long x;
      cin >> x;
      if ((ask[n - 1][i][0] && x) || (!ask[n - 1][i][0] && !x)) {
        answer = (field[n - 1][i] == field[n - 1][i + 1]);
      } else {
        answer = (field[n - 1][i] != field[n - 1][i + 1]);
      }
      flag = 0;
    }
  }
  cout << "!" << '\n';
  cout.flush();
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if ((i + j) % 2 == 0)
        cout << field[i][j];
      else
        cout << (field[i][j] ^ (answer ^ 1));
    }
    cout << '\n';
  }
  return 0;
}
