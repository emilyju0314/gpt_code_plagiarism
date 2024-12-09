#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    unordered_map<int, int> max_folds;  // store the maximum number of folds for each unique currency

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        vector<int> curr_folds(n, 0);

        for (int j = 0; j < i; j++) {
            if (a[j] == a[i]) {
                int diff = j - curr_folds[j];
                curr_folds[i] = max(curr_folds[i], diff);
            }
        }

        max_folds[a[i]] = max(max_folds[a[i]], curr_folds[i]);
        cout << max_folds[a[i]] << " ";
    }

    return 0;
}