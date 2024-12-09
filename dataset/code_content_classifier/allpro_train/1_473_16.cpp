#include <bits/stdc++.h>
using namespace std;
long long int dot(long long int A[], long long int B[], long long int C[]) {
  long long int* AB = new long long int[2];
  long long int* BC = new long long int[2];
  AB[0] = B[0] - A[0];
  AB[1] = B[1] - A[1];
  BC[0] = C[0] - B[0];
  BC[1] = C[1] - B[1];
  long long int dot = AB[0] * BC[0] + AB[1] * BC[1];
  return dot;
}
long long int cross(long long int A[], long long int B[], long long int C[]) {
  long long int* AB = new long long int[2];
  long long int* AC = new long long int[2];
  AB[0] = B[0] - A[0];
  AB[1] = B[1] - A[1];
  AC[0] = C[0] - A[0];
  AC[1] = C[1] - A[1];
  long long int cross = AB[0] * AC[1] - AB[1] * AC[0];
  return cross;
}
double distance(long long int A[], long long int B[]) {
  long long int d1 = A[0] - B[0];
  long long int d2 = A[1] - B[1];
  return sqrt(d1 * d1 + d2 * d2);
}
double linePointDist(long long int A[], long long int B[], long long int C[],
                     bool isSegment) {
  double dist = cross(A, B, C) / distance(A, B);
  if (isSegment) {
    long long int dot1 = dot(A, B, C);
    if (dot1 > 0) return distance(B, C);
    long long int dot2 = dot(B, A, C);
    if (dot2 > 0) return distance(A, C);
  }
  return abs(dist);
}
long long int P[2];
long long int a[2], b[2];
long long int pts[100010][2];
int main() {
  int N;
  cin >> N;
  cin >> P[0] >> P[1];
  vector<pair<long long int, long long int> > v(N);
  double maxD = 0.0;
  double minD = 1e20;
  for (int i = 0; i < N; i++) {
    cin >> pts[i][0] >> pts[i][1];
    maxD = max(maxD, distance(pts[i], P));
    minD = min(minD, distance(pts[i], P));
  }
  for (int i = 0; i < N; i++)
    minD = min(linePointDist(pts[i], pts[(i + 1) % N], P, true), minD);
  double ans = (3.141592653589793) * (maxD * maxD - minD * minD);
  printf("%0.9lf\n", ans);
  return 0;
}
