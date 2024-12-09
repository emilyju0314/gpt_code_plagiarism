#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string garland;
    cin >> garland;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int m;
        char c;
        cin >> m >> c;

        vector<int> maxKoyomity(n+1, 0);
        int left = 0, right = 0, cnt = 0;
        int maxCnt = 0;

        while (right < n) {
            if (garland[right] != c) {
                cnt++;
            }
            right++;

            while (cnt > m) {
                if (garland[left] != c) {
                    cnt--;
                }
                left++;
            }

            maxCnt = max(maxCnt, right - left);
            maxKoyomity[right] = maxCnt;
        }

        cout << maxKoyomity[n] << "\n";
    }

    return 0;
}