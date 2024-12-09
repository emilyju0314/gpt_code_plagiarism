#include <bits/stdc++.h>
using namespace std;
long long int const mod = 1000000007;
long long int arr1[1000009];
set<long long int> sieve;
void sievefun(long long int n) {
  for (long long int i = 2; i <= n; i++) {
    if (arr1[i] == 0) {
      for (long long int j = i * i; j <= n; j += i) {
        arr1[j] = 1;
      }
    }
  }
  for (int i = 2; i <= n; i++) {
    if (arr1[i] == 0) sieve.insert(i);
  }
}
long long int power(long long int x, long long int y) {
  long long int temp;
  if (y == 0) return 1;
  temp = power(x, y / 2);
  if (y % 2 == 0)
    return ((temp) * (temp));
  else
    return (((x)) * ((temp * temp)));
}
char a[100];
void fun(long long int k, char aa, char bb) {
  for (int i = 0; i < (int)k; i++) {
    int x;
    cin >> x;
    a[x] = aa;
    a[x + 1] = bb;
  }
}
string ans;
void fun1(int n, int ind, string second) {
  if (ind == n + 1) {
    cout << "? " << second << endl;
    int k;
    cin >> k;
    if (k > 0) {
      int x;
      for (int i = 0; i < (int)k; i++) cin >> x;
      ans = second;
    }
    return;
  }
  if (a[ind] != 'A') {
    second += a[ind];
    fun1(n, ind + 1, second);
  } else {
    if (ind == n) {
      second += 'C';
      fun1(n, ind + 1, second);
      second.pop_back();
      second += 'H';
      fun1(n, ind + 1, second);
      second.pop_back();
      second += 'O';
      fun1(n, ind + 1, second);
    } else {
      second += 'H';
      fun1(n, ind + 1, second);
      second.pop_back();
      second += 'O';
      fun1(n, ind + 1, second);
    }
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < (int)n + 1; i++) a[i] = 'A';
    if (n == 4) {
      cout << "? CH" << endl;
      int k;
      cin >> k;
      int flag = 0;
      if (k > 0) {
        fun(k, 'C', 'H');
        flag = 1;
      }
      cout << "? CO" << endl;
      cin >> k;
      if (k > 0) {
        fun(k, 'C', 'O');
        flag = 1;
      }
      cout << "? CC" << endl;
      cin >> k;
      if (k > 0) {
        fun(k, 'C', 'C');
        flag = 1;
      }
      if (flag) {
        flag = 0;
        fun1(n, 1, "");
        cout << "! " << ans << endl;
        cin >> k;
        continue;
      } else {
        cout << "? OH" << endl;
        cin >> k;
        if (k > 0) {
          fun(k, 'O', 'H');
          fun1(n, 1, "");
          cout << "! " << ans << endl;
          cin >> k;
          continue;
        }
        cout << "? HH" << endl;
        cin >> k;
        if (k > 0) {
          fun(k, 'H', 'H');
          if (a[3] == 'A') a[3] = 'O';
          if (a[4] == 'A') {
            cout << "? ";
            for (int i = 1; i <= 3; i++) cout << a[i];
            cout << "O" << endl;
            cin >> k;
            if (k > 0) {
              cin >> k;
              a[4] = 'O';
            } else {
              a[4] = 'C';
            }
            cout << "! ";
            for (int i = 1; i <= 4; i++) cout << a[i];
            cout << endl;
            cin >> k;
          } else {
            cout << "! ";
            for (int i = 1; i <= 4; i++) cout << a[i];
            cout << endl;
            cin >> k;
          }
        } else {
          cout << "? OOO" << endl;
          cin >> k;
          if (k == 1) {
            cin >> k;
            if (k == 1) {
              cout << "! OOOC" << endl;
              cin >> k;
            } else if (k == 2) {
              cout << "! HOOO" << endl;
              cin >> k;
            }
          } else if (k == 2) {
            cin >> k;
            cin >> k;
            cout << "! OOOO" << endl;
            cin >> k;
          } else {
            cout << "! HOOC" << endl;
            cin >> k;
          }
        }
      }
    } else {
      cout << "? CH" << endl;
      int k;
      cin >> k;
      if (k > 0) {
        fun(k, 'C', 'H');
      }
      cout << "? CO" << endl;
      cin >> k;
      if (k > 0) {
        fun(k, 'C', 'O');
      }
      cout << "? CC" << endl;
      cin >> k;
      if (k > 0) {
        fun(k, 'C', 'C');
      }
      cout << "? HO" << endl;
      cin >> k;
      if (k > 0) {
        fun(k, 'H', 'O');
      }
      cout << "? OH" << endl;
      cin >> k;
      if (k > 0) {
        fun(k, 'O', 'H');
      }
      for (int i = 1; i <= n; i++) {
        if (a[i] == 'H') {
          for (int j = i + 1; j < n; j++) {
            if (a[j] != 'A') break;
            a[j] = 'H';
          }
          for (int j = i - 1; j >= 1; j--) {
            if (a[j] != 'A') break;
            a[j] = 'H';
          }
        }
        if (a[i] == 'O') {
          for (int j = i + 1; j < n; j++) {
            if (a[j] != 'A') break;
            a[j] = 'O';
          }
          for (int j = i - 1; j >= 1; j--) {
            if (a[j] != 'A') break;
            a[j] = 'O';
          }
        }
      }
      string second = "";
      for (int i = 1; i <= n - 1; i++) {
        if (a[i] == 'A')
          second += 'O';
        else
          second += a[i];
      }
      cout << "? " << second << endl;
      cin >> k;
      if (k == 0) {
        for (int i = 1; i <= n - 1; i++)
          if (a[i] == 'A') a[i] = 'H';
        second = "";
        for (int i = 1; i <= n - 1; i++) second += a[i];
        if (a[n] != 'A') {
          second += a[n];
          cout << "! " << second << endl;
          cin >> k;
        } else {
          second += 'C';
          cout << "? " << second << endl;
          cin >> k;
          if (k == 0) {
            second.pop_back();
            second += a[n - 1];
          } else {
            int x;
            for (int i = 0; i < (int)k; i++) cin >> x;
          }
          cout << "! " << second << endl;
          cin >> k;
        }
      } else {
        int x;
        for (int i = 0; i < (int)k; i++) cin >> x;
        for (int i = 1; i <= n - 1; i++)
          if (a[i] == 'A') a[i] = 'O';
        second = "";
        for (int i = 1; i <= n - 1; i++) second += a[i];
        if (a[n] != 'A') {
          second += a[n];
          cout << "! " << second << endl;
          cin >> k;
        } else {
          second += 'C';
          cout << "? " << second << endl;
          cin >> k;
          if (k == 0) {
            second.pop_back();
            second += a[n - 1];
          } else {
            cin >> k;
          }
          cout << "! " << second << endl;
          cin >> k;
        }
      }
    }
  }
}
