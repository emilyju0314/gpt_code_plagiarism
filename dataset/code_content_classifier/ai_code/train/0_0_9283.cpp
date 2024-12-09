#include <iostream>
#include <vector>

using namespace std;

// Function to check if t[l1 ... l1+len-1] is reachable from t[l2 ... l2+len-1]
bool reachable(string t, int l1, int l2, int len) {
    string sub1 = t.substr(l1 - 1, len);
    string sub2 = t.substr(l2 - 1, len);

    int diff1 = 0, diff2 = 0;
    for (int i = 0; i < len; i++) {
        if (sub1[i] != sub2[i]) {
            if (sub1[i] == '0' && i + 2 < len && sub1[i + 1] == '1' && sub1[i + 2] == '1') {
                diff1++;
                i += 2;
            } else if (sub1[i] == '1' && i + 2 < len && sub1[i + 1] == '1' && sub1[i + 2] == '0') {
                diff1++;
                i += 2;
            } else {
                return false;
            }
        }
    }

    return (diff1 % 2 == diff2 % 2);
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

        bool can_reach = reachable(t, l1, l2, len);

        if (can_reach) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}