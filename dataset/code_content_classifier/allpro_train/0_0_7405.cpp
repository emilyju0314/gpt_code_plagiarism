#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> boys(n);
    for (int i = 0; i < n; i++) {
        boys[i] = i + 1;
    }

    int direction = 1; // 1 for clockwise, -1 for counter-clockwise

    for (int i = 0; i < q; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x;
            cin >> x;

            if (x < 0) {
                direction = -1;
                x = -x;
            } else {
                direction = 1;
            }

            if (direction == 1) {
                for (int j = 0; j < n; j++) {
                    boys[j] = (boys[j] + x - 1) % n + 1;
                }
            } else {
                for (int j = 0; j < n; j++) {
                    boys[j] = (boys[j] - x + n - 1) % n + 1;
                }
            }
        } else {
            for (int j = 0; j < n; j += 2) {
                swap(boys[j], boys[j + 1]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << boys[i] << " ";
    }
    cout << endl;

    return 0;
}