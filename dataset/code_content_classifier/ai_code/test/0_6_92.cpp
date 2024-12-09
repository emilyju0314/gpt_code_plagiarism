#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int n = s.length();
        int ab_count = 0, ba_count = 0;
        
        for(int i = 0; i < n - 1; i++) {
            if(s[i] == 'a' && s[i+1] == 'b') ab_count++;
            if(s[i] == 'b' && s[i+1] == 'a') ba_count++;
        }

        if(ab_count == 0 || ba_count == 0) {
            cout << s << endl;
        } else if(ab_count > ba_count) {
            for(int i = 0; i < n - 1; i++) {
                if(s[i] == 'a' && s[i+1] == 'b') {
                    s[i+1] = 'a';
                    break;
                }
            }
            cout << s << endl;
        } else {
            for(int i = 0; i < n - 1; i++) {
                if(s[i] == 'b' && s[i+1] == 'a') {
                    s[i+1] = 'b';
                    break;
                }
            }
            cout << s << endl;
        }
    }

    return 0;
}