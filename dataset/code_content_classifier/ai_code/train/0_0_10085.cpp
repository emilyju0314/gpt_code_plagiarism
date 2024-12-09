#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int m;
    cin >> m;

    vector<pair<int, int>> swaps;
    for (int i = 0; i < n; i++) {
        if (p[i] != i + 1) {
            int j;
            for (j = i + 1; j < n; j++) {
                if (p[j] == i + 1) {
                    break;
                }
            }

            while (j != i) {
                swaps.push_back({i, j});
                swap(p[i], p[j]);
                j--;
            }
        }
    }

    if (swaps.size() > m) {
        cout << -1 << endl;
        return 0;
    }

    int additional_swaps = m - swaps.size();

    vector<pair<int, int>> remaining_swaps;
    for (int i = 0; i < n; i++) {
        if (p[i] != i + 1) {
            remaining_swaps.push_back({i, i + 1});
            swap(p[i], p[i + 1]);
        }
    }

    vector<pair<int, int>> result_swaps;
    if (additional_swaps % 2 == 1) {
        result_swaps.push_back(remaining_swaps.back());
        remaining_swaps.pop_back();
        additional_swaps--;
    }

    for (int i = 0; i < additional_swaps; i += 2) {
        result_swaps.push_back({remaining_swaps[0].first, remaining_swaps[1].first});
        result_swaps.push_back({remaining_swaps[0].second, remaining_swaps[1].second});
        remaining_swaps.erase(remaining_swaps.begin(), remaining_swaps.begin() + 2);
    }

    cout << swaps.size() + result_swaps.size() << endl;
    for (auto &swap : swaps) {
        cout << swap.first + 1 << " " << swap.second + 1 << " ";
    }
    for (auto &swap : result_swaps) {
        cout << swap.first + 1 << " " << swap.second + 1 << " ";
    }

    return 0;
}