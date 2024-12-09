#include <bits/stdc++.h>
using namespace std;
int main() {
  double n, H, h;
  scanf("%lf %lf", &n, &H);
  for (int i = 0; i < n - 1; i++) {
    h = H * sqrt((i + 1) / n);
    printf("%.12lf ", h);
  }
}
