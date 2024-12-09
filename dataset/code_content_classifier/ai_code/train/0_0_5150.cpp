#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> banknotes(n);
    for (int i = 0; i < n; i++) {
        cin >> banknotes[i];
    }

    sort(banknotes.begin(), banknotes.end());

    int min_unfortunate_sum = -1;
    for (int i = 0; i < n - 1; i++) {
        if (banknotes[i + 1] - banknotes[i] > 1) {
            min_unfortunate_sum = banknotes[i] + 1;
            break;
        }
    }

    cout << min_unfortunate_sum << endl;

    return 0;
}