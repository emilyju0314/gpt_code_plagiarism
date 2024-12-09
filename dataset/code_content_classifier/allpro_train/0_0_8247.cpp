#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "First" << endl;
        for (int i = 1; i <= 2 * n; ++i) {
            cout << (i + 1) / 2 << " ";
        }
        cout << endl;
    } else {
        cout << "Second" << endl;
        vector<int> pairs(2 * n);
        for (int i = 0; i < 2 * n; ++i) {
            cin >> pairs[i];
        }

        vector<int> chosen_nums(n);
        for (int i = 0; i < 2 * n; i += 2) {
            if (pairs[i] == pairs[i + 1]) {
                chosen_nums[pairs[i] - 1] = i + 1;
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << chosen_nums[i] << " ";
        }
        cout << endl;
    }

    cout << flush;
    int verdict;
    cin >> verdict;

    return 0;
}