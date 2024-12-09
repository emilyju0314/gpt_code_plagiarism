#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double euclideanDistance(int x1, int y1, int x2, int y2) {
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main() {
    int n;
    cin >> n;

    int x, y, m;
    cin >> x >> y >> m;

    x /= 1000;
    y /= 1000;

    vector<pair<int, int>> lines(n);
    for (int i = 0; i < n; i++) {
        cin >> lines[i].first >> lines[i].second;
    }

    vector<double> distances;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            double a1 = lines[i].first;
            double b1 = lines[i].second;
            double a2 = lines[j].first;
            double b2 = lines[j].second;

            double det = a1 * b2 - a2 * b1;
            if (det != 0) {
                double x_intersection = (b2 - b1) / det;
                double y_intersection = (a1 - a2) / det;

                double dist = euclideanDistance(x, y, x_intersection, y_intersection);
                distances.push_back(dist);
            }
        }
    }

    sort(distances.begin(), distances.end());

    double sum = 0;
    for (int i = 0; i < m; i++) {
        sum += distances[i];
    }

    cout << fixed;
    cout.precision(9);
    cout << sum << endl;

    return 0;
}