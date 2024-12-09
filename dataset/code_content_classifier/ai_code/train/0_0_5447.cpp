#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <utility>

using namespace std;

// Point struct to represent 2D points
struct Point {
    int x, y;
};

// Calculate the cross product of two vectors
long long cross_product(const Point& p1, const Point& p2) {
    return (long long)p1.x * p2.y - (long long)p1.y * p2.x;
}

// Calculate the area of a convex polygon given its vertices
long long calculate_area(const vector<Point>& polygon) {
    long long area = 0;
    for (int i = 0; i < polygon.size(); i++) {
        int j = (i + 1) % polygon.size();
        area += cross_product(polygon[i], polygon[j]);
    }
    return abs(area) / 2;  // Taking the absolute value and halving it
}

int main() {
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        vector<Point> R(n), S(m);
        for (int i = 0; i < n; i++) {
            cin >> R[i].x >> R[i].y;
        }
        for (int i = 0; i < m; i++) {
            cin >> S[i].x >> S[i].y;
        }

        long long min_area = 1e18;

        // Trying different combinations of a, b, c, d
        for (int a = 1; a < n; a++) {
            for (int b = 1; b < n; b++) {
                if (a * b != n) continue;
                for (int c = 1; c < m; c++) {
                    for (int d = 1; d < m; d++) {
                        if (c * d != m) continue;

                        vector<Point> P, Q;

                        // Obtain P and Q based on the values of a, b, c, d
                        for (int i = 0; i < n; i++) {
                            Point p;
                            p.x = a * R[i].x + b * S[i].x;
                            p.y = a * R[i].y + b * S[i].y;
                            P.push_back(p);
                        }
                        for (int i = 0; i < m; i++) {
                            Point q;
                            q.x = c * R[i].x + d * S[i].x;
                            q.y = c * R[i].y + d * S[i].y;
                            Q.push_back(q);
                        }

                        // Calculate the area of P and Q
                        long long area_P = calculate_area(P);
                        long long area_Q = calculate_area(Q);

                        // Update the minimum area
                        min_area = min(min_area, area_P + area_Q);
                    }
                }
            }
        }

        // Output the double of the sum of the areas of P and Q
        cout << min_area * 2 << endl;
    }

    return 0;
}