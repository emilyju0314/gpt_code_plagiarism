#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> heights(n);
        for (int i = 0; i < n; i++) {
            cin >> heights[i];
        }

        bool can_increase = true;
        int current = 0;
        for (int i = 0; i < n; i++) {
            if (heights[i] < current) {
                can_increase = false;
                break;
            } else {
                current = heights[i] - current;
            }
        }

        if (can_increase) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}