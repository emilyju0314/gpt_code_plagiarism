#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<string> phoneNumbers(n);
    for (int i = 0; i < n; i++) {
        cin >> phoneNumbers[i];
    }

    vector<vector<int>> calls(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < phoneNumbers[i].size(); k++) {
                string sub = phoneNumbers[i].substr(0, k + 1);
                if (phoneNumbers[j].find(sub) != string::npos) {
                    calls[i][j]++;
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << calls[l-1][r-1] << endl;
    }

    return 0;
}