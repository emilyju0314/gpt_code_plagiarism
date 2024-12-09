#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        set<pair<int, int>> slopes;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                int dx = points[j].x - points[i].x;
                int dy = points[j].y - points[i].y;
                int a = dy;
                int b = dx * dx;
                int g = __gcd(a, b);
                a /= g;
                b /= g;
                slopes.insert({a, b});
            }
        }
        count += slopes.size();
    }

    cout << count / 2 << endl;

    return 0;
}