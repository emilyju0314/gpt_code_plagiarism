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

        string s;
        cin >> s;

        vector<pair<int, int>> prefix_sum(n+1, {0, 0});
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') x--;
            else if (s[i] == 'R') x++;
            else if (s[i] == 'U') y++;
            else y--;

            prefix_sum[i+1] = {x, y};
        }

        int min_len = n+1;
        int start, end;
        for (int i = 0; i < n; i++) {
            int l = 0, r = 0;
            if (s[i] == 'L') l = 1;
            else if (s[i] == 'R') r = 1;
            else if (s[i] == 'U') l = 1, r = i+1;
            else l = 1, r = i+1;

            int diff_x = prefix_sum[n].first - (l == 1 ? prefix_sum[i].first + prefix_sum[n].first - prefix_sum[r].first : prefix_sum[r].first);
            int diff_y = prefix_sum[n].second - (l == 1 ? prefix_sum[i].second + prefix_sum[n].second - prefix_sum[r].second : prefix_sum[r].second);

            if (diff_x == 0 && diff_y == 0 && r - l + 1 < min_len) {
                min_len = r - l + 1;
                start = l;
                end = r;
            }
        }

        if (min_len == n+1) {
            cout << -1 << endl;
        } else {
            cout << start << " " << end << endl;
        }
    }

    return 0;
}