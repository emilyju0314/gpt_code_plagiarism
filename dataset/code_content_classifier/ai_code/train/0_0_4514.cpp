#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    int cnt = 0;
    int l = -1, r = -1;

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(s[i], s[j]);
            int balance = 0;
            int max_balance = 0;
            for (int k = 0; k < n; k++) {
                if (s[k] == '(') {
                    balance++;
                } else {
                    balance--;
                }
                max_balance = max(max_balance, balance);
            }
            if (max_balance == 0) {
                if (cnt < j - i + 1) {
                    cnt = j - i + 1;
                    l = i + 1;
                    r = j + 1;
                }
            }
            swap(s[i], s[j]);
        }
    }

    cout << cnt << endl;
    cout << l << " " << r << endl;

    return 0;
}