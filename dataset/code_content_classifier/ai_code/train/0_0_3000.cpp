#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s, t;
    cin >> s >> t;

    vector<int> operations;

    for (int i = 0; i < n; i++) {
        int j = i;
        while (s[j] != t[i] && j < n) {
            j++;
        }

        if (j == n) {
            cout << -1 << endl;
            return 0;
        }

        for (int k = j; k > i; k--) {
            operations.push_back(k);
            swap(s[k], s[k-1]);
        }
    }

    cout << operations.size() << endl;
    for (int op : operations) {
        cout << op << " ";
    }
    cout << endl;

    return 0;
}