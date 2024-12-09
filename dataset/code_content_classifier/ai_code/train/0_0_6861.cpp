#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, W;
        cin >> n >> W;

        vector<int> widths(n);
        for(int i = 0; i < n; i++) {
            cin >> widths[i];
        }

        sort(widths.begin(), widths.end(), greater<int>());

        int current_height = 0;
        int remaining_width = W;
        int max_width_in_level = W;

        for(int i = 0; i < n; i++) {
            if (remaining_width >= widths[i]) {
                remaining_width -= widths[i];
            } else {
                current_height++;
                remaining_width = max_width_in_level - widths[i];
            }
            max_width_in_level = max(max_width_in_level, remaining_width);
        }

        cout << current_height + 1 << endl;
    }

    return 0;
}