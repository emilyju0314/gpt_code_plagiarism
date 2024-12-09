#include <iostream>
#include <vector>
#include <map>
#include <climits>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        vector<int> a(n);
        map<int, int> lastPos;

        int minLength = INT_MAX;
        bool dominated = false;

        for (int i = 0; i < n; i++) {
            cin >> a[i];
            if (lastPos.count(a[i]) > 0) {
                minLength = min(minLength, i - lastPos[a[i]] + 1);
                dominated = true;
            }
            lastPos[a[i]] = i;
        }

        if (dominated) {
            cout << minLength << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}