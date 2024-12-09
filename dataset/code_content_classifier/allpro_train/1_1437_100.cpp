#include <bits/stdc++.h>
using namespace std;
struct node {
  int a, b, co;
  node() : a(a), b(b), co(co) {}
  node(int a, int b, int c) : a(a), b(b), co(co) {}
  bool operator<(const node& x) const {
    return make_pair(a, b) > make_pair(x.a, x.b);
  }
};
node arr[1003];
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i].a);
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i].b);
  }
  priority_queue<node> heap;
  for (int i = 0; i < n; i++) {
    node tmp;
    tmp.a = arr[i].b / arr[i].a;
    tmp.b = arr[i].a - arr[i].b % arr[i].a;
    tmp.co = arr[i].a;
    heap.push(tmp);
  }
  int magic = k;
  int ans = 0;
  while (!heap.empty()) {
    node tmp = heap.top();
    heap.pop();
    if (tmp.b <= magic) {
      magic -= tmp.b;
      ans = tmp.a;
      tmp.a++;
      tmp.b = tmp.co;
      heap.push(tmp);
    } else {
      ans = min(ans + 1, tmp.a);
      break;
    }
  }
  printf("%d", ans);
}
