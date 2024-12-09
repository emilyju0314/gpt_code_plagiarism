#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int X, K, Q;
    cin >> X >> K;
    vector<int> r(K);
    for (int i = 0; i < K; i++) {
        cin >> r[i];
    }
    cin >> Q;
    for (int i = 0; i < Q; i++) {
        int t, a;
        cin >> t >> a;
        int upper_bulb = 0, lower_bulb = X;
        for (int j = 0; j < K; j++) {
            if (t >= r[j]) {
                int time_passed = min(t - r[j], r[j] - r[j-1]);
                if (upper_bulb == 0) {
                    lower_bulb -= time_passed;
                    upper_bulb = time_passed;
                } else {
                    upper_bulb -= time_passed;
                    lower_bulb = time_passed;
                }
            }
        }
        if (upper_bulb == 0) {
            cout << lower_bulb << endl;
        } else {
            cout << upper_bulb << endl;
        }
    }
    return 0;
}