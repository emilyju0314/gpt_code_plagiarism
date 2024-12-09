#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    sort(sequence.begin(), sequence.end());

    if (k == 0) {
        if (sequence[0] > 1) {
            cout << 1 << endl;
        } else {
            cout << -1 << endl;
        }
    } else if (k == n) {
        cout << sequence[n-1] << endl;
    } else if (sequence[k-1] == sequence[k]) {
        cout << -1 << endl;
    } else {
        cout << sequence[k-1] << endl;
    }

    return 0;
}