#include <iostream>
#include <vector>

using namespace std;

struct Ramp {
    int x, d, t, p;
};

int main() {
    int n, L;
    cin >> n >> L;

    vector<Ramp> ramps(n);
    for (int i = 0; i < n; i++) {
        cin >> ramps[i].x >> ramps[i].d >> ramps[i].t >> ramps[i].p;
    }

    vector<int> dp(L + 1, INT_MAX);
    vector<int> prev(L + 1, -1);

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        Ramp ramp = ramps[i];
        for (int j = ramp.x; j <= L; j++) {
            if (dp[j - ramp.p] != INT_MAX) {
                int time = dp[j - ramp.p] + ramp.p + ramp.t + (j - ramp.x - ramp.p);
                if (time < dp[j + ramp.d]) {
                    dp[j + ramp.d] = time;
                    prev[j + ramp.d] = i;
                }
            }
        }
    }

    cout << dp[L] << endl;

    int current = L;
    vector<int> result;
    while (prev[current] != -1) {
        result.push_back(prev[current] + 1);
        current = ramps[prev[current]].x - ramps[prev[current]].p;
    }

    cout << result.size() << endl;
    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }

    return 0;
}