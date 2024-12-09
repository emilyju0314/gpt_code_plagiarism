#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double calculate_area(const vector<double>& points, const vector<int>& vertices) {
    double area = 0.0;
    for (int i = 0; i < vertices.size(); i++) {
        int i1 = vertices[i];
        int i2 = vertices[(i + 1) % vertices.size()];
        area += 0.5 * sin(2 * M_PI * (points[i1] - points[i2]));
    }
    return abs(area);
}

int main() {
    int n, m;
    while (cin >> n >> m && n != 0 && m != 0) {
        vector<double> points(n);
        for (int i = 0; i < n; i++) {
            cin >> points[i];
        }

        double max_area = 0.0;
        vector<int> indices(n);
        for (int i = 0; i < m; i++) {
            indices[i] = 1;
        }

        do {
            vector<int> vertices;
            for (int i = 0; i < n; i++) {
                if (indices[i] == 1) {
                    vertices.push_back(i);
                }
            }
            max_area = max(max_area, calculate_area(points, vertices));
        } while (prev_permutation(indices.begin(), indices.end()));

        cout << fixed;
        cout.precision(6);
        cout << max_area << endl;
    }

    return 0;
}