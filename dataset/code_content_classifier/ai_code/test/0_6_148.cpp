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

        vector<int> x1, x2, y1, y2;
        int k;

        cin >> k;
        for (int i = 0; i < k; i++) {
            int val;
            cin >> val;
            x1.push_back(val);
        }

        cin >> k;
        for (int i = 0; i < k; i++) {
            int val;
            cin >> val;
            x2.push_back(val);
        }

        cin >> k;
        for (int i = 0; i < k; i++) {
            int val;
            cin >> val;
            y1.push_back(val);
        }

        cin >> k;
        for (int i = 0; i < k; i++) {
            int val;
            cin >> val;
            y2.push_back(val);
        }

        int max_area = 0;

        for (int x : x1) {
            for (int y : y1) {
                int max2 = 0;
                for (int y2_val : y2) {
                    max2 = max(max2, min(w - x, y2_val - y) * min(w - x, h - y2_val));
                }
                for (int x2_val : x2) {
                    max2 = max(max2, min(x2_val - x, h - y) * min(w - x2_val, h - y));
                }
                max_area = max(max_area, max2);
            }
        }

        cout << 2 * max_area << endl;
    }

    return 0;
}