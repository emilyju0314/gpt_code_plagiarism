#include <iostream>
#include <vector>
#include <string>

#define MOD 1000000007

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        string start, end;
        cin >> start >> end;

        long long ans = 1;
        for (int i = 0; i < n; i++) {
            if (start[i] == '?' && end[i] == '?')
                ans = (ans * 2) % MOD;
            else if (start[i] == '?' || end[i] == '?' || start[i] != end[i])
                ans = 0;
        }

        cout << ans << endl;
    }

    return 0;
}