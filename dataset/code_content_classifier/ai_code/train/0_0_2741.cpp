#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> taps(k);
        for (int i = 0; i < k; i++) {
            cin >> taps[i];
        }

        int max_time = 0;
        for (int i = 0; i < k; i++) {
            int time;
            if (taps[i] - 1 > n - taps[i]) {
                time = taps[i] - 1;
            } else {
                time = n - taps[i];
            }
            if (time > max_time) {
                max_time = time;
            }
        }

        cout << max_time + 1 << endl;
    }

    return 0;
}