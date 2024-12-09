#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        vector<int> left(n+1, n+1);
        vector<int> right(n+1, 0);

        for (int i = 0; i < n; i++) {
            left[p[i]] = min(left[p[i]], i);
            right[p[i]] = max(right[p[i]], i);
        }

        string beautiful = "";
        int cur_min = n+1, cur_max = 0;
        for (int i = 1; i <= n; i++) {
            cur_min = min(cur_min, left[i]);
            cur_max = max(cur_max, right[i]);

            if (cur_max - cur_min == i - 1) {
                beautiful += "1";
            } else {
                beautiful += "0";
            }
        }

        cout << beautiful << endl;
    }

    return 0;
}