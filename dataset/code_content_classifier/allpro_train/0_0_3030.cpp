#include <iostream>

using namespace std;

int main() {
    int a, b, x;
    cin >> a >> b >> x;

    string ans = "";
    if (a >= b) {
        for (int i = 0; i < x; i++) {
            ans += "0";
            a--;
        }
        ans += "1";
        b--;
        x--;
    } else {
        for (int i = 0; i < x; i++) {
            ans += "1";
            b--;
        }
        ans += "0";
        a--;
        x--;
    }

    char start = ans[0];
    while (a > 0) {
        ans += "0";
        a--;
    }

    while (b > 0) {
        ans += "1";
        b--;
    }

    for (int i = x; i < ans.size() - 1; i += 2) {
        if (start == '0') {
            swap(ans[i], ans[i+1]);
        }
    }

    cout << ans << endl;

    return 0;
}