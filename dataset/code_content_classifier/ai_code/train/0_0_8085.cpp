#include <iostream>
#include <string>

#define MOD 1000000007

using namespace std;

int main() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    long long result = 1;
    for(int i = 0; i < n; i++) {
        if(s1[i] == '?' && s2[i] == '?') {
            result = (result * 2) % MOD;
        } else if(s1[i] != '?' && s2[i] != '?' && s1[i] != s2[i]) {
            result = 0;
        }
    }

    cout << result << endl;

    return 0;
}