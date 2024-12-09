#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        vector<int> operations;
        bool possible = true;

        for (int i = n - 1; i >= 0; i--) {
            if (a[i] != b[i]) {
                if (a[0] != a[i]) {
                    operations.push_back(1);
                    a[0] = '1' + '0' - a[0];  // flipping the first element
                }

                reverse(a.begin(), a.begin() + i + 1);
                for (int j = 0; j <= i; j++) {
                    a[j] = '1' + '0' - a[j];  // flipping
                }

                operations.push_back(i + 1);
            }
        }

        for (char c : a) {
            if (c != b[0]) {
                possible = false;
                break;
            }
        }

        if (!possible) {
            cout << "-1\n";
        } else {
            cout << operations.size() << "\n";
            for (int op : operations) {
                cout << op << " ";
            }
            cout << "\n";
        }
    }
    
    return 0;
}