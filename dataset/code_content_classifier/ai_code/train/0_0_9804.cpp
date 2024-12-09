#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int k;
    cin >> k;

    vector<vector<int>> boxes(k);
    unordered_map<int, pair<int, int>> numToBox;

    for (int i = 0; i < k; ++i) {
        int n_i;
        cin >> n_i;
        boxes[i].resize(n_i);
        for (int j = 0; j < n_i; ++j) {
            cin >> boxes[i][j];
            numToBox[boxes[i][j]] = make_pair(i, j);
        }
    }

    vector<int> sums(k, 0);
    for (int i = 0; i < k; ++i) {
        for (int num : boxes[i]) {
            sums[i] += num;
        }
    }

    bool possible = true;
    for (int i = 1; i < k; ++i) {
        if (sums[i] != sums[0]) {
            possible = false;
            break;
        }
    }

    if (!possible) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for (int i = 0; i < k; ++i) {
            int targetSum = sums[i];
            int num = boxes[i][0];
            int targetBox = numToBox[targetSum - num].first + 1; // Adding 1 to convert to 1-based index
            cout << num << " " << targetBox << endl;
        }
    }

    return 0;
}