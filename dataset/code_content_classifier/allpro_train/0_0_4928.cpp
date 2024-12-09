#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    // Creating a 2D vector to store the input points
    vector<vector<int>> points(k, vector<int>(2));

    // Getting the input points
    for (int i = 0; i < k; i++) {
        cin >> points[i][0] >> points[i][1];
    }

    // Calculating the number of rectangles
    int count = 0;

    // Checking if the points form a rectangle
    for (int i = 0; i < k; i++) {
        for (int j = i + 1; j < k; j++) {
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[j][0];
            int y2 = points[j][1];

            // Checking if the distance between the points is m
            if ((x1 != x2 && y1 != y2) && abs(x1 - x2) == m && abs(y1 - y2) == n) {
                count++;
            }
        }
    }

    // Output the number of rectangles
    cout << count << endl;

    return 0;
}