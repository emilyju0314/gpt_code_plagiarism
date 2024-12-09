#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int q;
    cin >> q;

    while (q--) {
        int queryType;
        cin >> queryType;

        if (queryType == 1) {
            int i;
            char c;
            cin >> i >> c;
            s[i - 1] = c;
        } else if (queryType == 2) {
            int l, r;
            string y;
            cin >> l >> r >> y;

            int count = 0;
            for (int i = l - 1; i <= r - y.size(); i++) {
                if (s.substr(i, y.size()) == y) {
                    count++;
                }
            }

            cout << count << endl;
        }
    }

    return 0;
}