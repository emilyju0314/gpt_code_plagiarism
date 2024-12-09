#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool constructPolyline(int h, vector<int>& horizontalSegments, int v, vector<int>& verticalSegments) {
    int sumH = 0, sumV = 0;
    for (int len : horizontalSegments) sumH += len;
    for (int len : verticalSegments) sumV += len;
    
    if (sumH != sumV) return false;

    vector<pair<int, int>> polyline;
    int x = 0, y = 0;
    for (int i = 0; i < h && i < v; i++) {
        for (int j = 0; j < horizontalSegments[i]; j++) {
            x++;
            polyline.push_back({x, y});
        }

        for (int j = 0; j < verticalSegments[i]; j++) {
            y++;
            polyline.push_back({x, y});
        }
    }

    if (polyline.size() != sumH + sumV) return false;

    cout << "Yes" << endl;
    for (auto [x, y] : polyline) {
        cout << x << " " << y << endl;
    }

    return true;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int h, v;
        cin >> h;
        vector<int> horizontalSegments(h);
        for (int j = 0; j < h; j++) {
            cin >> horizontalSegments[j];
        }

        cin >> v;
        vector<int> verticalSegments(v);
        for (int j = 0; j < v; j++) {
            cin >> verticalSegments[j];
        }

        if (!constructPolyline(h, horizontalSegments, v, verticalSegments)) {
            cout << "No" << endl;
        }

        if (i != t-1) {
            cout << endl;  // Separate the test cases
        }
    }

    return 0;
}