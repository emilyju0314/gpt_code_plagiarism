#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }

        vector<vector<int>> subsets(k);
        for (int i = 0; i < k; i++) {
            int c;
            cin >> c;
            subsets[i].resize(c);
            for (int j = 0; j < c; j++) {
                cin >> subsets[i][j];
            }
        }

        vector<int> password(k);
        for (int i = 0; i < k; i++) {
            cout << "? " << n - subsets[i].size() << " ";
            for (int j = 0; j < n; j++) {
                if (find(subsets[i].begin(), subsets[i].end(), j + 1) == subsets[i].end()) {
                    cout << j + 1 << " ";
                }
            }
            cout << endl;
            cout.flush();

            int x;
            cin >> x;
            password[i] = x;
        }

        cout << "! ";
        for (int i = 0; i < k; i++) {
            cout << password[i] << " ";
        }
        cout << endl;
        cout.flush();

        string response;
        cin >> response;
        if (response == "Incorrect") {
            break;
        }
    }

    return 0;
}