#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int min_difficulty = 1001; // Maximum possible height difference

    for (int i = 1; i < n - 1; i++) {
        int max_diff = 0;
        for (int j = 1; j < n; j++) {
            if (j == i) {
                max_diff = max(max_diff, a[j + 1] - a[j - 1]);
            } else {
                max_diff = max(max_diff, a[j] - a[j - 1]);
            }
        }
        min_difficulty = min(min_difficulty, max_diff);
    }

    cout << min_difficulty << endl;

    return 0;
}