#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        string s;
        cin >> s;

        int cnt = 0;
        int balance = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                balance++;
            } else {
                if (balance == 0) {
                    cnt++;
                } else {
                    balance--;
                }
            }
        }

        cout << cnt << endl;
    }

    return 0;
}