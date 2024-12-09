#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
        }

        vector<int> winner(n, 0);
        
        int min_strength_a = a[0];
        int min_strength_b = b[0];

        for (int i = 0; i < n; i++) {
            min_strength_a = min(min_strength_a, a[i]);
            if (a[i] > min_strength_b) {
                winner[i] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            min_strength_b = min(min_strength_b, b[i]);
            if (b[i] > min_strength_a) {
                winner[i] = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            cout << winner[i];
        }
        cout << endl;
    }

    return 0;
}