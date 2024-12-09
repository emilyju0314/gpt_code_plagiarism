#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> cubes(n);
    for(int i = 0; i < n; i++) {
        cin >> cubes[i];
    }

    int left = 0;
    int ans = 0;
    int maxColor = 0;
    vector<int> colorCount(m + 1, 0);

    for(int right = 0; right < n; right++) {
        colorCount[cubes[right]]++;
        maxColor = max(maxColor, colorCount[cubes[right]]);

        while (right - left + 1 - maxColor > k) {
            colorCount[cubes[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    cout << ans << endl;

    return 0;
}