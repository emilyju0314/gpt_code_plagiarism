#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int avg = sum / n;
    int extra = 0;
    int meetings = 0;
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {
        int diff = a[i] - avg - extra;
        while (diff < 0) {
            a[i] += k;
            diff += k;
            meetings++;
            vector<int> meeting = {i, 0};
            for (int j = 0; j < k; j++) {
                meeting.push_back(min(-diff, a[(i + j) % n] - avg - extra));
                a[(i + j) % n] -= min(-diff, a[(i + j) % n] - avg - extra);
                diff += min(-diff, a[(i + j) % n] - avg - extra);
            }
            ans.push_back(meeting);
        }
        extra = diff;
    }

    cout << meetings << endl;
    for (vector<int> meeting : ans) {
        cout << meeting[0] << " ";
        for (int i = 1; i < meeting.size(); i++) {
            cout << meeting[i] << " ";
        }
        cout << endl;
    }

    return 0;
}