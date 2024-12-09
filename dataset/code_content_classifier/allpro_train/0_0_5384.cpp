#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> r(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> r[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int max_points = -1;
    bool possible = false;

    for (int i = 1; i <= 100; i++) {
        bool r_more_points = false;
        bool b_more_points = false;

        for (int j = 0; j < n; j++) {
            if (r[j] == 1 && b[j] == 0 && i > 1) {
                r_more_points = true;
            }

            if (r[j] == 0 && b[j] == 1) {
                b_more_points = true;
            }
        }

        if (r_more_points && b_more_points) {
            possible = true;
            max_points = i;
            break;
        }
    }

    if (possible) {
        cout << max_points << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}