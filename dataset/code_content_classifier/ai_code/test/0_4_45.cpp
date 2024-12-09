#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t; // number of test cases

    for (int i = 0; i < t; i++) {
        int n;
        cin >> n; // number of days

        vector<int> watered(n); // vector to store whether the flower was watered on each day
        for (int j = 0; j < n; j++) {
            cin >> watered[j];
        }

        int height = 1; // starting height of the flower
        bool dead = false;

        for (int j = 0; j < n; j++) {
            if (watered[j] == 1) {
                if (j > 0 && watered[j-1] == 1) {
                    height += 5;
                } else {
                    height += 1;
                }
            } else {
                if (j > 0 && watered[j-1] == 0) {
                    dead = true; // flower dies if not watered for two days in a row
                    break;
                }
            }
        }

        if (dead) {
            cout << -1 << endl;
        } else {
            cout << height << endl;
        }
    }

    return 0;
}