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
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a.begin(), a.end(), greater<int>());

        int alice = 0, bob = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (a[i] % 2 == 0) {
                    alice += a[i];
                }
            } else {
                if (a[i] % 2 != 0) {
                    bob += a[i];
                }
            }
        }

        if (alice > bob) {
            cout << "Alice" << endl;
        } else if (bob > alice) {
            cout << "Bob" << endl;
        } else {
            cout << "Tie" << endl;
        }
    }

    return 0;
}