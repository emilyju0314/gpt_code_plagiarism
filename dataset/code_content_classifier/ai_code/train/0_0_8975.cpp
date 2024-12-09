#include <iostream>
#include <vector>

using namespace std;

int orientation(int x1, int y1, int x2, int y2, int x3, int y3) {
    int val = (y2 - y1) * (x3 - x2) - (x2 - x1) * (y3 - y2);
    
    if (val == 0) return 0; // collinear
    return (val > 0) ? 1 : -1; // clockwise or counterclockwise
}

bool sideOfYAxis(int x1, int y1, int x2, int y2, int x3, int y3) {
    int orientation_value = orientation(x1, y1, x2, y2, x3, y3);
    
    if (orientation_value == 0) return false; // collinear
    
    for (int i = 0; i < points.size(); i++) {
        if (i != 0) {
            if (orientation_value != orientation(points[i][0], points[i][1], x2, y2, x3, y3)) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> points(n, vector<int>(2));
    
    for (int i = 0; i < n; i++) {
        cin >> points[i][0] >> points[i][1];
    }
    
    bool found = false;
    
    for (int i = 0; i < n; i++) {
        if (sideOfYAxis(points[(i+1)%n][0], points[(i+1)%n][1], points[(i+2)%n][0], points[(i+2)%n][1], points[i][0], points[i][1])) {
            found = true;
            break;
        }
    }
    
    if (found) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}