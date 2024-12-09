#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    string ans = s;
    int start, end;
    for(start = 0; start < n; start++) {
        if(s[start] == 'a') {
            break;
        }
    }
    for(end = start; end < n; end++) {
        if(s[end] != 'a') {
            ans[end] = (char)(s[end] - 1);
        } else {
            break;
        }
    }

    cout << ans << endl;

    return 0;
}