#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int w, h;
        cin >> w >> h;

        vector<int> horizontalPoints;
        vector<int> verticalPoints;

        int k;
        cin >> k;
        for (int i = 0; i < k; i++) {
            int p;
            cin >> p;
            horizontalPoints.push_back(p);
        }

        cin >> k;
        for (int i = 0; i < k; i++) {
            int p;
            cin >> p;
            verticalPoints.push_back(p);
        }

        // Sort the points to get the minimum and maximum values
        sort(horizontalPoints.begin(), horizontalPoints.end());
        sort(verticalPoints.begin(), verticalPoints.end());

        int maxArea = 0;

        // Iterate through all possible combinations of points
        for (int i = 0; i < horizontalPoints.size(); i++) {
            for (int j = 0; j < verticalPoints.size(); j++) {
                for (int l = j+1; l < verticalPoints.size(); l++) {
                    int area = max(horizontalPoints[i], w - horizontalPoints[i]) * (verticalPoints[l] - verticalPoints[j]);
                    maxArea = max(maxArea, area);
                }
            }
        }

        cout << 2*maxArea << endl;
    }

    return 0;
}