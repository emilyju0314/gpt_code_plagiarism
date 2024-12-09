#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isReachable(string t, int l1, int l2, int len) {
    string sub1 = t.substr(l1 - 1, len);
    string sub2 = t.substr(l2 - 1, len);

    // Check if the substrings can be transformed into each other
    int diff = 0;
    for (int i = 0; i < len; i++) {
        if (sub1[i] != sub2[i]) {
            diff++;
            if (diff > 2) {
                return false; // More than one difference, not reachable
            }
            if (i+2 < len && sub1[i] == '1' && sub1[i+1] == '1' && sub1[i+2] == '0') {
                i += 2; // Skip 011 or 110 in sub1
            }
            else return false; // Substrings can't be transformed with one operation
        }
    }

    return true; // Substrings are reachable
}

int main() {
    int n;
    cin >> n;

    string t;
    cin >> t;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l1, l2, len;
        cin >> l1 >> l2 >> len;

        if (isReachable(t, l1, l2, len)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}