#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> temperatures(n);
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
    }

    int changes = 0;
    int consecutiveWinterDays = 0;
    bool usingWinterTires = false;

    for (int i = 0; i < n; i++) {
        if (temperatures[i] < 0) {
            cout << -1 << endl;
            return 0;
        }

        if (!usingWinterTires) {
            usingWinterTires = true;
            changes++;
        }

        consecutiveWinterDays++;
        if (consecutiveWinterDays > k) {
            usingWinterTires = false;
            consecutiveWinterDays = 0;
        }
    }

    cout << changes << endl;

    return 0;
}