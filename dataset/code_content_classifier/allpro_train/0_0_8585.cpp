#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;

    while (k--) {
        int n;
        cin >> n;

        string s, t;
        cin >> s >> t;

        vector<int> diff_indices;
        for (int i = 0; i < n; i++) {
            if (s[i] != t[i]) {
                diff_indices.push_back(i);
            }
        }

        if (diff_indices.size() != 2) {
            cout << "No" << endl;
        } else {
            if (s[diff_indices[0]] == s[diff_indices[1]] && t[diff_indices[0]] == t[diff_indices[1]]) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}