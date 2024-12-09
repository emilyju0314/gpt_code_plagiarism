#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
};

bool isPossibleToPassThroughHole(int n, vector<Point>& vertices) {
    for (int i = 0; i < n - 1; i++) {
        // Check if the segment between vertices[i] and vertices[i+1] crosses the wall y = 0
        if ((vertices[i].y > 0 && vertices[i+1].y < 0) || (vertices[i].y < 0 && vertices[i+1].y > 0)) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;

    vector<Point> vertices(n);
    for (int i = 0; i < n; i++) {
        cin >> vertices[i].x >> vertices[i].y;
    }

    if (isPossibleToPassThroughHole(n, vertices)) {
        cout << "Possible" << endl;
    } else {
        cout << "Impossible" << endl;
    }

    return 0;
}