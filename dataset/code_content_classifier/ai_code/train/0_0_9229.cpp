#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);
    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int m;
    cin >> m;

    while(m--) {
        int l, r, d;
        cin >> l >> r >> d;

        heights[l-1] += d;
        heights[r] -= d;

        vector<int> prefix_sum(n);
        prefix_sum[0] = heights[0];
        for(int i = 1; i < n; i++) {
            prefix_sum[i] = prefix_sum[i-1] + heights[i];
        }

        vector<int> left(n);
        vector<int> right(n);

        for(int i = 1; i < n; i++) {
            if(prefix_sum[i] > prefix_sum[i-1]) {
                left[i] = left[i-1] + 1;
            }
        }

        for(int i = n-2; i >= 0; i--) {
            if(prefix_sum[i] > prefix_sum[i+1]) {
                right[i] = right[i+1] + 1;
            }
        }

        int max_width = 0;
        for(int i = 0; i < n; i++) {
            max_width = max(max_width, left[i] + right[i] + 1);
        }

        cout << max_width << endl;
    }

    return 0;
}