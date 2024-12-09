#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int l, r, t;
};

bool compareSegments(Segment s1, Segment s2) {
    return s1.r < s2.r;
}

int main() {
    int n;
    cin >> n;

    vector<Segment> segments(n);
    for(int i = 0; i < n; i++) {
        cin >> segments[i].l >> segments[i].r >> segments[i].t;
    }

    sort(segments.begin(), segments.end(), compareSegments);

    int dp[n];
    dp[0] = 1;

    for(int i = 1; i < n; i++) {
        dp[i] = 1;
        for(int j = i - 1; j >= 0; j--) {
            if(segments[i].t != segments[j].t && segments[i].l <= segments[j].r) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int maxSegments = *max_element(dp, dp+n);

    cout << maxSegments << endl;

    return 0;
}