#include <iostream>
#include <vector>

using namespace std;

void reverseSubstring(vector<pair<int, int>>& operations, int l, int r) {
    operations.push_back(make_pair(l, r));
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        vector<pair<int, int>> operations;

        int regularPrefixes = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                int cnt = 1;
                for (int j = i + 1; j < n; j++) {
                    if (s[j] == '(') {
                        cnt++;
                    } else {
                        cnt--;
                    }

                    if (cnt == 0) {
                        reverseSubstring(operations, i, j);
                        regularPrefixes++;
                        break;
                    }
                }
            }
        }

        cout << operations.size() << endl;
        for (auto& op : operations) {
            cout << op.first + 1 << " " << op.second + 1 << endl;
        }
    }

    return 0;
}