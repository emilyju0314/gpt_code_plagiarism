#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int w, h;
        cin >> w >> h;

        // Read points on horizontal sides
        int k;
        cin >> k;
        vector<int> x1(k);
        for (int i = 0; i < k; i++) {
            cin >> x1[i];
        }

        cin >> k;
        vector<int> x2(k);
        for (int i = 0; i < k; i++) {
            cin >> x2[i];
        }

        // Read points on vertical sides
        cin >> k;
        vector<int> y1(k);
        for (int i = 0; i < k; i++) {
            cin >> y1[i];
        }

		cin >> k;
        vector<int> y2(k);
        for (int i = 0; i < k; i++) {
            cin >> y2[i];
        }

        // Choose the three points to form the triangle
        int maxX = x1.back();
        int maxY = y1.back();

        // Calculate the doubled maximum area of triangle
        int maxArea = max(maxX*(h - maxY), max(w - maxX, maxY)*maxX);
        cout << 2*maxArea << endl;
    }

    return 0;
}