#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> required(n);
    vector<int> initial(n);

    for (int i = 0; i < n; i++) {
        cin >> required[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> initial[i];
    }

    vector<pair<int, int>> swaps;

    for (int i = 0; i < n; i++) {
        if (required[i] != initial[i]) {
            int j = i;
            while (initial[j] != required[i]) {
                j++;
            }
            while (j > i) {
                swaps.push_back({j, j - 1});
                swap(initial[j], initial[j - 1]);
                j--;
            }
        }
    }

    cout << swaps.size() << endl;
    for (auto swap : swaps) {
        cout << swap.first + 1 << " " << swap.second + 1 << endl;
    }

    return 0;
}