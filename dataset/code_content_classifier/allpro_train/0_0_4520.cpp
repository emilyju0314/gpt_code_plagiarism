#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> strings(n);
    for (int i = 0; i < n; i++) {
        cin >> strings[i];
    }

    int max_dist = 0;
    string t;
    for (int split = 0; split <= 1; split++) {
        int dist = 0;
        for (int i = 0; i < n; i++) {
            int cnt1 = 0, cnt2 = 0;
            for (char c : strings[i]) {
                if (c == 'B') {
                    if (split == 0) cnt1++;
                    else cnt2++;
                } else {
                    if (split == 0) cnt2++;
                    else cnt1++;
                }
            }
            dist = max(dist, max(cnt1, cnt2));
        }

        if (dist > max_dist) {
            max_dist = dist;
            if (split == 0) t = "BN";
            else t = "NB";
        }
    }

    cout << max_dist << endl;
    for (int i = 0; i < max_dist; i++) {
        cout << t;
    }
    cout << endl;

    return 0;
}