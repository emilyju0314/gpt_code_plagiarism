#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, pair<int, int>>> cells; // (color, (x, y))
    vector<int> colorsCount(4, 0);

    for (int i = 0; i < n; i++) {
        int x, y, color;
        cin >> x >> y >> color;
        cells.push_back({color, {x, y}});
        colorsCount[color]++;
    }

    sort(cells.begin(), cells.end());

    vector<int> prefixSum(4, 0);
    for (int i = 1; i <= 3; i++) {
        prefixSum[i] = prefixSum[i - 1] + colorsCount[i];
    }

    int totalCells = n / 3;

    int minK = INT_MAX;
    for (int right = 0; right <= totalCells; right++) {
        int left = max(totalCells - right, prefixSum[1] - right);
        int mid = totalCells - left - right;

        vector<int> count(4, 0);
        for (int i = 0; i < n; i++) {
            if (i < left || (i < left + mid && cells[i].first == 2) || (i < left + mid + right && cells[i].first == 3)) {
                count[cells[i].first]++;
            }
        }

        if (count[1] >= left && count[2] >= mid && count[3] >= right) {
            minK = min(minK, n - totalCells);
        }
    }

    cout << minK << endl;

    return 0;
}