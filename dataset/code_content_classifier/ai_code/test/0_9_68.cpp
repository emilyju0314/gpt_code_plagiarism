#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> bubbles(n);
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        bubbles[i] = {x, y};
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int dx, dy, k;
        cin >> dx >> dy >> k;
        int last_popped = 0;
        double max_angle = -1;
        
        for (int j = 0; j < n; j++) {
            int x = bubbles[j].first;
            int y = bubbles[j].second;
            double angle = atan2(y, x);
            if (angle < 0) {
                angle += 2 * M_PI;
            }
            double curr_angle = atan2(dy, dx);
            if (curr_angle < 0) {
                curr_angle += 2 * M_PI;
            }
            double diff = angle - curr_angle;
            
            if (diff < 0) {
                diff += 2 * M_PI;
            }
            if (diff > max_angle) {
                max_angle = diff;
                last_popped = j + 1;
            }
        }
        
        cout << last_popped << endl;
    }

    return 0;
}