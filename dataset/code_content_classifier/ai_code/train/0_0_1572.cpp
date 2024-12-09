#include <iostream>
#include <vector>

using namespace std;

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;
        
        vector<int> s(n);
        bool canWin = false;

        for (int j = 0; j < n; j++) {
            cin >> s[j];
            if (s[j] == 2048) {
                canWin = true;
            }
        }

        if (canWin) {
            cout << "YES" << endl;
            continue;
        }

        for (int j = 0; j < n; j++) {
            if (s[j] == 2048) {
                canWin = true;
                break;
            } else if (s[j] < 2048) {
                int sum = s[j];
                for (int k = j+1; k < n; k++) {
                    if (s[j] == s[k]) {
                        sum *= 2;
                        break;
                    }
                }
                if (sum == 2048) {
                    canWin = true;
                    break;
                }
            }
        }

        if (canWin) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}