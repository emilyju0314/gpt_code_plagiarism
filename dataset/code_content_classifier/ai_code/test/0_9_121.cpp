#include <iostream>
#include <string>
#include <vector>

using namespace std;

int min_operations(int n, string a, string b) {
    vector<int> operations;

    for (int i = n - 1; i >= 0; i--) {
        if (a[i] != b[i]) {
            if (a[i] == '0') {
                operations.push_back(1);
            } else {
                if (i > 0) {
                    operations.push_back(1);
                    a[i] = '0';
                }
                operations.push_back(i + 1);
            }
        }
    }

    if (a == b) {
        cout << operations.size() << endl;
        for (int op : operations) {
            cout << op << " ";
        }
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        min_operations(n, a, b);
    }

    return 0;
}