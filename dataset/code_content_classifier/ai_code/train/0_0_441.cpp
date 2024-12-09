#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, l, k;
    cin >> n >> l >> k;
    string letters;
    cin >> letters;

    sort(letters.begin(), letters.end());

    string ans[n];
    int pos = 0;
    for (int i = 0; i < n; i++) {
        ans[i] = letters.substr(pos, l);
        pos += l;
    }

    sort(ans, ans+n);

    for (int i = 0; i < n; i++) {
        cout << ans[i] << endl;
    }

    return 0;
}