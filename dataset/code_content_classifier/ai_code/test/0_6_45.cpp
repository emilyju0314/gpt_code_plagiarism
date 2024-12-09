#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        vector<int> days(n);
        for (int j = 0; j < n; j++) {
            cin >> days[j];
        }

        int height = 1;
        int consecutive = 0;
        bool alive = true;

        for (int j = 0; j < n; j++) {
            if (days[j] == 1) {
                height += 1;
                consecutive++;
                if (consecutive >= 2) {
                    height += 4;
                    consecutive = 0;
                }
            } else {
                consecutive = 0;
                height -= 2;
            }

            if (height <= 0) {
                alive = false;
                break;
            }
        }

        if (alive) {
            cout << height << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}