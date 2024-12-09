#include <bits/stdc++.h>
using namespace std;
char line[(5 * 100000) + 100];
bool fromLast[(5 * 100000) + 100];
void update(int len) {
  bool l = false;
  for (int i = len - 1; i >= 0; i--) {
    fromLast[i] = l;
    if (line[i] == 'H') {
      l = true;
    }
  }
}
bool ok(long long tym, int n) {
  tym--;
  int rem = 0;
  int last = 0;
  int sweets = 0;
  for (int i = 0; i < n; i++) {
    if (line[i] == 'H') {
      if (sweets > 0) {
        sweets--;
      } else {
        if (rem == 0) {
          last = i;
          rem++;
        } else {
          rem++;
        }
      }
      if (i != 0) tym--;
    } else if (line[i] == 'S') {
      if (rem > 0) {
        rem--;
        if (rem == 0) {
          if (fromLast[i] == false) {
            tym -= i - last;
          } else {
            tym -= 2 * (i - last);
          }
        }
      } else {
        sweets++;
      }
      if (i != 0) tym--;
    } else {
      if (i != 0) tym--;
    }
    if (fromLast[i] == false && rem == 0) break;
  }
  if (tym < 0) return false;
  if (rem > 0) return false;
  return true;
}
bool predicate(int add, int tym, int n) {
  int rem = 0;
  int last = 0;
  int sweets = 0;
  int A = add;
  for (int i = 0; i < n; i++) {
    if (line[i] == 'H') {
      if (sweets == 0) {
        if (add == 0) {
          rem++;
          if (rem == 1) {
            last = i;
          }
        } else {
          add--;
        }
      } else {
        sweets--;
      }
      tym--;
    } else if (line[i] == 'S') {
      if (rem > 0) {
        rem--;
        if (rem == 0) {
          if (fromLast[i] == false) {
            tym -= i - last;
          } else {
            tym -= 2 * (i - last);
          }
        }
      } else {
        sweets++;
      }
      tym--;
    } else {
      tym--;
    }
    if (fromLast[i] == false && rem == 0) break;
  }
  if (tym < 0) return false;
  if (rem > 0) return false;
  return true;
}
int solve(int n, int t) {
  int lo = 1;
  int hi = n;
  while ((hi - lo) > 5) {
    int mid = (hi + lo) / 2;
    if (predicate(mid, t, n)) {
      hi = mid;
    } else
      lo = mid + 1;
  }
  bool pos = false;
  int val = -1;
  for (int i = lo; i <= hi; i++) {
    if (predicate(i, t, n)) {
      val = i;
      break;
    }
  }
  return val;
}
bool ok2(int t, int n) {
  int a = 0;
  int b = 0;
  for (int i = 0; i < n; i++) {
    if (line[i] == 'H') a++;
    if (line[i] == 'S') b++;
  }
  if (a > b) return false;
  int fst = 0;
  int lst = 0;
  int mxa = a;
  a = b = 0;
  for (int i = 0; i < n; i++) {
    if (line[i] == 'H') {
      a++;
      if (a == 1) {
        fst = i;
      }
      if (a == mxa) {
        lst = i;
      }
    } else if (line[i] == 'S') {
      b++;
      if (b == mxa) {
        lst = i;
      }
    }
  }
  int tot = lst + 1;
  tot += lst - fst;
  if (tot <= t) return true;
  return false;
}
int main() {
  int n, t;
  cin >> n >> t;
  scanf("%s", line);
  update(n);
  if (ok(t, n) || ok2(t, n)) {
    cout << 0 << endl;
    return 0;
  } else {
    int res = solve(n, t);
    cout << res << endl;
  }
  return 0;
}
