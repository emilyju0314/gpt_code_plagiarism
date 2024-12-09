#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        char c;
        cin >> n >> c;
        string s;
        cin >> s;

        vector<int> operations;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != c) {
                count++;
                operations.push_back(i+1);
            }
        }

        if (count == 0) {
            cout << "0\n";
        } else {
            if (count <= n/2) {
                cout << count << "\n";
                for (int op : operations) {
                    cout << op << " ";
                }
                cout << "\n";
            } else {
                cout << n - count << "\n";
                for (int i = 1; i <= n; i++) {
                    if (s[i-1] == c) {
                        cout << i << " ";
                    }
                }
                cout << "\n";
            }
        }
    }

    return 0;
}