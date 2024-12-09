#include <cstdio>
using namespace std;

int n;

int main() {
  while (1) {
    scanf("%d", &n);
    if (n == 0) return 0;

    int ans = 0;
    for (int i=n; i>=1; i--) {
      int i_ = i;
      while (i_%5 == 0) {
        ans++;
        i_ /= 5;
      }
    }

    printf("%d\n", ans);
  }
}