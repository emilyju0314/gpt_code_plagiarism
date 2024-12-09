#include <bits/stdc++.h>
float triangle_area(float x1, float y1, float x2, float y2, float x3,
                    float y3) {
  return fabs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
}
int main() {
  float x1, x2, x3, y1, y2, y3, x, y;
  float s6 = sin(M_PI / 3.0);
  float s3 = 0.5;
  float s = 0;
  float s1 = sqrt(3.0) / 2.0;
  int l;
  x1 = y1 = 0;
  x2 = y2 = 0;
  x3 = y3 = 0;
  for (int i = 0; i < 6; ++i) {
    scanf("%d", &l);
    x = x3;
    y = y3;
    if (i == 0) {
      x += l;
    } else if (i == 3) {
      x -= l;
    } else if (i == 1) {
      x += l * s3;
      y += l * s6;
    } else if (i == 2) {
      x -= l * s3;
      y += l * s6;
    } else if (i == 4) {
      x -= l * s3;
      y -= l * s6;
    } else if (i == 5) {
      x += l * s3;
      y -= l * s6;
    }
    x1 = x2;
    y1 = y2;
    x2 = x3;
    y2 = y3;
    x3 = x;
    y3 = y;
    s += triangle_area(0, 0, x2, y2, x3, y3);
  }
  printf("%d\n", (int)((s + 0.5) / s1));
  return 0;
}
