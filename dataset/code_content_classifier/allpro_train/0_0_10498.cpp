#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;

        vector<int> ans(n); // to store the answer for each character

        int k = 1; // current subsequence number

        for(int i = 0; i < n; i++) {
            // check if the current character is different from the previous one
            if(i > 0 && s[i] != s[i-1]) {
                ans[i] = ans[i-1]; // assign it to the same subsequence
            } else {
                ans[i] = k; // assign it to a new subsequence
                k = 3 - k; // switch between 1 and 2
            }
        }

        cout << 2 << endl; // minimum number of subsequences is 2

        for(int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}