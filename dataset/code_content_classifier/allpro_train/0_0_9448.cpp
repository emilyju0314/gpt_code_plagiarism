#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, k;
        cin >> n >> k;

        vector<char> alphabets(k, 'a');
        for (int i = 1; i < k; i++) {
            alphabets[i] = alphabets[i-1] + 1;
        }

        string ans = "";

        int idx = 0;
        for (int i = 0; i < n; i++) {
            ans += alphabets[idx];
            idx = (idx + 1) % k;
        }

        cout << ans << endl;
    }

    return 0;
}