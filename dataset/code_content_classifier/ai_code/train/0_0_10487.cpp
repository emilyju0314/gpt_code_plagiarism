#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    int open = 0, close = 0, ans = 0;
    for(int i = 0; i < n-1; i++) {
        if(s[i] == '(') {
            open++;
        } else {
            close++;
        }
        ans = max(ans, open - close);
    }

    cout << ans << endl;

    vector<int> deltas;
    for(int i = 0; i < q; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        int delta = (s[a] == '(' ? 1 : -1) - (s[b] == '(' ? 1 : -1);
        s[a] = (s[a] == '(' ? ')' : '(');
        s[b] = (s[b] == '(' ? ')' : '(');

        deltas.push_back(delta);

        open = 0, close = 0, ans = 0;
        for(int j = 0; j < n-1; j++) {
            if(s[j] == '(') {
                open++;
            } else {
                close++;
            }
            ans = max(ans, open - close);
        }

        for(int delta : deltas) {
            ans += delta;
            cout << ans << endl;
        }
    }

    return 0;
}