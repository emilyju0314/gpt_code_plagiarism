#include <iostream>
#include <string>
#define MOD 1000000007

using namespace std;

int main() {
    string s;
    cin >> s;

    long long ans = 1;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] >= 'A' && s[i] <= 'Z') {
            ans = (ans * 3) % MOD;
        } else if(s[i] >= 'a' && s[i] <= 'z') {
            ans = (ans * 3) % MOD;
        } else if(s[i] >= '0' && s[i] <= '9') {
            ans = (ans * 3) % MOD;
        } else if(s[i] == '-' || s[i] == '_') {
            ans = (ans * 3) % MOD;
        }
    }

    cout << ans << endl;

    return 0;
}