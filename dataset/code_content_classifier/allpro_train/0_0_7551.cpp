#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Segment {
    int left, right;
};

bool compareSegments(Segment s1, Segment s2) {
    return s1.right < s2.right;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<Segment> segments(n);
        for (int i = 0; i < n; i++) {
            cin >> segments[i].left >> segments[i].right;
        }

        sort(segments.begin(), segments.end(), compareSegments);

        vector<int> dp(n, 1);
        int result = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (segments[i].left >= segments[j].right) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }

        cout << result << endl;
    }

    return 0;
}