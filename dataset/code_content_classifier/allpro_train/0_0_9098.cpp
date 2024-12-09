#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Envelope {
    int s, t, d, w;
};

bool compare(const Envelope& e1, const Envelope& e2) {
    if (e1.w != e2.w) {
        return e1.w > e2.w;
    }
    return e1.d > e2.d;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<Envelope> envelopes(k);
    for (int i = 0; i < k; i++) {
        cin >> envelopes[i].s >> envelopes[i].t >> envelopes[i].d >> envelopes[i].w;
    }

    sort(envelopes.begin(), envelopes.end(), compare);

    vector<int> dp(n+1, 0);
    for (int i = 0; i < k; i++) {
        for (int j = n; j >= envelopes[i].s; j--) {
            if (dp[j] < dp[envelopes[i].s-1] + envelopes[i].w) {
                dp[j] = dp[envelopes[i].s-1] + envelopes[i].w;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        int disturb_time;
        cin >> disturb_time;
        for (int j = n; j >= disturb_time; j--) {
            dp[j] = max(dp[j], dp[j-1]);
        }
    }

    cout << dp[n] << endl;

    return 0;
}