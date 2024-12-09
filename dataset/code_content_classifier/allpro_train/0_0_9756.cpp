#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    // Read colors of Mr. Meeseeks
    vector<int> colors(n);
    for (int i = 0; i < n; i++) {
        cin >> colors[i];
    }

    vector<int> ans(n, 0);
    unordered_map<int, int> colorCount;

    for (int k = 1; k <= n; k++) {
        colorCount.clear();
        int maxColor = 0;
        int maxColorCount = 0;
        int differentColors = 0;

        for (int i = 0, j = 0; i < n; i++) {
            while (j < n && (differentColors < k || (differentColors == k && colorCount[colors[j]] > 0))) {
                if (colorCount[colors[j]] == 0) {
                    differentColors++;
                }
                colorCount[colors[j]]++;
                maxColorCount = max(maxColorCount, colorCount[colors[j]]);
                maxColor = max(maxColor, differentColors);

                j++;
            }
            ans[k - 1] = max(ans[k - 1], i - j + 2);

            if (--colorCount[colors[i]] == 0) {
                differentColors--;
            }
        }
    }

    // Output minimum number of presidios needed for each k
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}