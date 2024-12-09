#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> denominations(n);
        for (int i = 0; i < n; i++) {
            cin >> denominations[i];
        }

        int current_amount = 0;
        for (int i = 1; i < k; i++) {
            int min_banknotes = k+1;
            for (int j = 0; j < n; j++) {
                if (i - (1 << denominations[j]) >= 0) {
                    min_banknotes = min(min_banknotes, current_amount + 1);
                }
            }
            if (min_banknotes > k) {
                cout << i << endl;
                break;
            }
            current_amount = min_banknotes;
        }
    }

    return 0;
}