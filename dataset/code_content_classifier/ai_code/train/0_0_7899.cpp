#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef pair<int, int> Point;

double dist(Point p1, Point p2) {
    return sqrt(pow(p1.first - p2.first, 2) + pow(p1.second - p2.second, 2));
}

int main() {
    vector<Point> points(8);

    for (int i = 0; i < 8; i++) {
        cin >> points[i].first >> points[i].second;
    }

    sort(points.begin(), points.end());

    do {
        Point p1 = points[0];
        Point p2 = points[1];
        Point p3 = points[2];
        Point p4 = points[3];

        double d12 = dist(p1, p2);
        double d13 = dist(p1, p3);
        double d14 = dist(p1, p4);

        if (d12 == d13 && d12 == d14) {
            vector<int> squareIndexes = {1, 2, 3, 4};
            vector<int> rectangleIndexes;

            for (int i = 0; i < 8; i++) {
                if (i != 0 && i != 1 && i != 2 && i != 3) {
                    rectangleIndexes.push_back(i + 1);
                }
            }

            cout << "YES" << endl;
            for (int idx : squareIndexes) {
                cout << idx << " ";
            }
            cout << endl;
            for (int idx : rectangleIndexes) {
                cout << idx << " ";
            }
            cout << endl;

            return 0;
        }
    } while (next_permutation(points.begin(), points.end()));

    cout << "NO" << endl;
    
    return 0;
}