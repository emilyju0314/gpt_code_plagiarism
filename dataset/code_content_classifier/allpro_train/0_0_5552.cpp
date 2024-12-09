#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n, r;
    cin >> n >> r;

    map<int, vector<int>> x_points, y_points;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x_points[x].push_back(y);
        y_points[y].push_back(x);
    }

    int max_points = 0;

    // Check for maximum number of points covered for each unique x-coordinate
    for (auto it = x_points.begin(); it != x_points.end(); it++) {
        int x_coord = it->first;
        vector<int> y_coords = it->second;
        sort(y_coords.begin(), y_coords.end());

        int count = 0;
        int ptr1 = -1, ptr2 = 0;
        while (ptr2 < y_coords.size()) {
            while (ptr1 + 1 < ptr2 && y_coords[ptr2] - y_coords[ptr1+1] > 2*r) {
                ptr1++;
            }
            count = max(count, ptr2 - ptr1);
            ptr2++;
        }
        
        max_points = max(max_points, count);
    }

    // Check for maximum number of points covered for each unique y-coordinate
    for (auto it = y_points.begin(); it != y_points.end(); it++) {
        int y_coord = it->first;
        vector<int> x_coords = it->second;
        sort(x_coords.begin(), x_coords.end());

        int count = 0;
        int ptr1 = -1, ptr2 = 0;
        while (ptr2 < x_coords.size()) {
            while (ptr1 + 1 < ptr2 && x_coords[ptr2] - x_coords[ptr1+1] > 2*r) {
                ptr1++;
            }
            count = max(count, ptr2 - ptr1);
            ptr2++;
        }

        max_points = max(max_points, count);
    }

    cout << max_points << endl;

    return 0;
}