#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, q;
        cin >> n >> q;

        string s, f;
        cin >> s >> f;

        int total_changes = 0;
        for(int i = 0; i < q; i++) {
            int l, r;
            cin >> l >> r;
            l--; // 0-based indexing
            r--; // 0-based indexing

            int zeros = 0, ones = 0;
            for(int j = l; j <= r; j++) {
                if(s[j] == '0') zeros++;
                else ones++;
            }

            if(zeros > 0 && ones > 0) {
                cout << "NO" << endl;
                total_changes = -1;
                break;
            }

            int changes_needed = 0;
            for(int j = l; j <= r; j++) {
                if(s[j] != f[j]) changes_needed++;
            }

            if(changes_needed > (r - l + 1) / 2) {
                cout << "NO" << endl;
                total_changes = -1;
                break;
            }

            total_changes += changes_needed;
        }

        if(total_changes >= 0) {
            cout << "YES" << endl;
        }
    }

    return 0;
}