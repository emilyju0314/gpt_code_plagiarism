#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n);

        // Query 1
        cout << "? 2 4 1 3" << endl;
        int ans1;
        cin >> ans1;

        // Query 2
        cout << "? 1 2 4 2" << endl;
        int ans2;
        cin >> ans2;

        // Deduce the permutation
        if (ans1 < ans2) {
            p[0] = ans2;
            p[1] = ans1;
        } else {
            p[0] = ans1;
            p[1] = ans2;
        }

        // Find p3
        for (int i = 1; i <= n; i++) {
            if (i != p[0] && i != p[1]) {
                cout << "? 2 3 4 " << i << endl;
                int ans3;
                cin >> ans3;
                p[2] = ans3;
                break;
            }
        }

        // Find the remaining elements
        for (int i = 3; i < n; i++) {
            cout << "? 1 " << i << " " << n << " 1" << endl;
            int ans;
            cin >> ans;
            p[i] = ans;
        }

        // Print the permutation
        cout << "! ";
        for (int i = 0; i < n; i++) {
            cout << p[i] << " ";
        }
        cout << endl;
        cout.flush();
    }

    return 0;
}