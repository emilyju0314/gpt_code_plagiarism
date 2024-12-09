#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Point {
    int x, y, index;
};

bool isLeftTurn(Point &p1, Point &p2, Point &p3) {
    return (p2.x - p1.x) * (p3.y - p2.y) - (p2.y - p1.y) * (p3.x - p2.x) > 0;
}

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
        points[i].index = i + 1;
    }

    string s;
    cin >> s;

    vector<int> permutation;
    permutation.push_back(1);
    permutation.push_back(2);
    permutation.push_back(3);

    for (int i = 0; i < n - 3; i++) {
        if (s[i] == 'L') {
            permutation.insert(permutation.begin() + i + 2, i + 4);
        } else {
            permutation.push_back(i + 4);
        }
    }

    for (int i = 0; i < n - 2; i++) {
        if (!isLeftTurn(points[permutation[i] - 1], points[permutation[i + 1] - 1], points[permutation[i + 2] - 1])) {
            cout << -1 << endl;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << permutation[i] << " ";
    }
    cout << endl;

    return 0;
}