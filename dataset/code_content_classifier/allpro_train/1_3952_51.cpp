#include <bits/stdc++.h>
using namespace std;
template <class T1>
void deb(T1 e1) {
  cout << e1 << endl;
}
template <class T1, class T2>
void deb(T1 e1, T2 e2) {
  cout << e1 << " " << e2 << endl;
}
template <class T1, class T2, class T3>
void deb(T1 e1, T2 e2, T3 e3) {
  cout << e1 << " " << e2 << " " << e3 << endl;
}
template <class T1, class T2, class T3, class T4>
void deb(T1 e1, T2 e2, T3 e3, T4 e4) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << endl;
}
template <class T1, class T2, class T3, class T4, class T5>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << endl;
}
template <class T1, class T2, class T3, class T4, class T5, class T6>
void deb(T1 e1, T2 e2, T3 e3, T4 e4, T5 e5, T6 e6) {
  cout << e1 << " " << e2 << " " << e3 << " " << e4 << " " << e5 << " " << e6
       << endl;
}
int dx[] = {0, 0, 1, -1};
int dy[] = {-1, 1, 0, 0};
int arr[200000 + 10];
int main() {
  int t, kase = 0, a, b, i, j, k, l, mx;
  int N, one, two, twoone;
  while (scanf("%d %d %d", &N, &one, &two) == 3) {
    twoone = 0;
    for (i = 0; i < N; i++) scanf("%d", &arr[i]);
    int cnt = 0;
    for (i = 0; i < N; i++) {
      a = arr[i];
      if (a == 1) {
        if (one > 0) {
          one--;
        } else if (two > 0) {
          two--;
          twoone++;
        } else if (twoone > 0) {
          twoone--;
        } else
          cnt++;
      } else {
        if (two > 0) {
          two--;
        } else
          cnt += 2;
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
