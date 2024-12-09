#include <bits/stdc++.h>
inline void swap(double &a, double &b) {
  double c = a;
  a = b;
  b = c;
}
inline double three(double n) { return n * n * n; }
struct Point {
  double x, y, z;
  Point() {}
  Point(double a, double b, double c) {
    x = a;
    y = b;
    z = c;
  }
  void read() { scanf("%lf %lf", &x, &y); }
  Point operator+(const Point &o) { return Point(x + o.x, y + o.y, z + o.z); }
  Point operator*(double n) { return Point(x * n, y * n, z * n); }
  void print() { printf("(%f,%f,%f)\n", x, y, z); }
};
Point A[102], B[102];
Point getHeart(int index) { return (A[index] + B[index]) * 0.5; }
double getLength(int index) { return B[index].x - A[index].x; }
bool judge(int index, const Point &p) {
  return A[index].x <= p.x && p.x <= B[index].x && A[index].y <= p.y &&
         p.y <= B[index].y;
}
bool test(int index) {
  Point heart = getHeart(index);
  double weight = 0;
  for (int i = index; i > 0; i--) {
    double tw = three(getLength(i));
    Point th = getHeart(i);
    heart = (heart * weight + th * tw) * (1.0 / (weight + tw));
    for (int j = i - 1; j >= 0; j--) {
      if (judge(i - 1, heart) == false) {
        return false;
      }
    }
    weight += tw;
  }
  return true;
}
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int ans = -1;
    double z = 0;
    for (int i = 0; i < n; i++) {
      A[i].read();
      B[i].read();
      if (A[i].x > B[i].x) {
        swap(A[i].x, B[i].x);
      }
      if (A[i].y > B[i].y) {
        swap(A[i].y, B[i].y);
      }
      int h = B[i].x - A[i].x;
      A[i].z = z;
      B[i].z = z + h;
      z += h;
      if (ans == -1 && test(i) == false) {
        ans = i;
      }
    }
    if (ans == -1) {
      ans = n;
    }
    printf("%d\n", ans);
  }
  return 0;
}
