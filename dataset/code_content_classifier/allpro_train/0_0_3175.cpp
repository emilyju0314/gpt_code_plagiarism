#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    string ans = "";
    for (int i = 0; i < n; i++) {
        if (ans.size() >= 1 && s[i] == '0' && ans.back() == '1') {
            ans.pop_back();
        } else {
            ans += s[i];
        }
    }

    cout << ans << endl;

    return 0;
}