#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> ans;
    int open = 0, hash = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            open++;
        } else if (s[i] == '#') {
            hash++;
        } else {
            if (open == 0) {
                cout << -1 << endl;
                return 0;
            }
            ans.push_back(1);
            open--;
        }
    }

    if (open + hash == 0) {
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << endl;
        }
    } else {
        for (int i = 0; i < ans.size(); i++) {
            if (i == ans.size() - 1) {
                ans[i] += open;
            } else {
                ans[i] += open / (ans.size() - i);
                open -= open / (ans.size() - i);
            }
            cout << ans[i] << endl;
        }
    }

    return 0;
}