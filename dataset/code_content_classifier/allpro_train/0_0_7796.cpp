#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    unordered_map<int, unordered_map<int, int>> points; // map of points and their counts

    for (int i = 0; i < n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int x = x1; x < x2; x++) {
            for (int y = y1; y < y2; y++) {
                points[x][y]++; // increment the count of each point in the rectangle
            }
        }
    }

    for (auto& p_x : points) {
        for (auto& p_y : p_x.second) {
            if (p_y.second >= n - 1) { // check if point belongs to at least (n-1) rectangles
                cout << p_x.first << " " << p_y.first << endl;
                return 0;
            }
        }
    }

    return 0;
}