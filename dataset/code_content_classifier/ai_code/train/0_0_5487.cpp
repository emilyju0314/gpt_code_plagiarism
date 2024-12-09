#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define MOD 4294967296

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s;
    cin >> s;
    
    int questionMarks = count(s.begin(), s.end(), '?');
    
    if(n % 2 != 0 || s[0] >= 'a' + n / 2) {
        cout << "0" << endl;
        return 0;
    }
    
    long long ans = 1;
    
    for(int i = 0; i < questionMarks; i++) {
        ans = (ans * 26) % MOD;
    }
    
    cout << ans << endl;
    
    return 0;
}