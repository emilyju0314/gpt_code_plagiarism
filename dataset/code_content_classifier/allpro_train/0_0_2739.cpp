#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string s, t;
    cin >> s >> t;
    
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        long long cnt = 0;
        for(int j = i; j < n; j++) {
            if(t[j] == '1') break;
            cnt += (s[j] == s[i]);
            ans = max(ans, cnt * (j - i + 1));
        }
    }
    
    cout << ans << endl;
    
    return 0;
}