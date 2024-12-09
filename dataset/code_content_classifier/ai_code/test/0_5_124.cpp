#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define MOD 1000000007

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        string a, b;
        cin >> a >> b;

        int result = 1;

        for(int i = 0; i < n; i++) {
            if(a[i] == '?' && b[i] == '?') {
                result = (result * 2) % MOD;
            } else if(a[i] != '?' && b[i] != '?' && a[i] != b[i]) {
                result = 0;
                break;
            }
        }

        cout << result << endl;
    }

    return 0;
}