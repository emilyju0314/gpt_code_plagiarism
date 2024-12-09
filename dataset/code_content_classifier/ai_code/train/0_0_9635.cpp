#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n, k;
        cin >> n >> k;

        string s;
        cin >> s;

        int ans = 0;
        for(int i = 0; i < n; ) {
            if(s[i] == '0') {
                ans++;
                i += k + 1;
            } else {
                i++;
            }
        }

        cout << ans << endl;
    }

    return 0;
}