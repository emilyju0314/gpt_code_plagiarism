#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> heights(n+1, 0); // initialize heights of trees at each position to 0
    vector<int> dp(n+1, 0); // initialize dynamic programming array for storing length of longest increasing subsequence

    for (int i = 0; i < m; i++) {
        int type;
        cin >> type;

        if (type == 1) {
            int p, h;
            cin >> p >> h;

            heights[p] = h;
            dp[p] = 1; // initialize as a sequence of length 1

            // update dp array by checking previous positions for increasing trees
            for (int j = 1; j < p; j++) {
                if (heights[j] < h) {
                    dp[p] = max(dp[p], dp[j] + 1);
                }
            }

            // print length of longest increasing subsequence
            cout << *max_element(dp.begin(), dp.end()) << endl;
        } else {
            int x;
            cin >> x;

            // cut down the x-th existent tree
            heights[x] = 0;

            // update dp array by re-calculating longest increasing subsequence
            fill(dp.begin(), dp.end(), 0);
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k < j; k++) {
                    if (heights[j] > 0 && heights[k] < heights[j]) {
                        dp[j] = max(dp[j], dp[k] + 1);
                    }
                }
            }

            // print length of longest increasing subsequence
            cout << *max_element(dp.begin(), dp.end()) << endl;
        }
    }

    return 0;
}