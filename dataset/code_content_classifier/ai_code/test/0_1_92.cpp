#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        string s;
        cin >> s;
        
        int abCount = 0, baCount = 0;
        
        for(int i = 0; i < s.length() - 1; i++) {
            if(s[i] == 'a' && s[i+1] == 'b') abCount++;
            if(s[i] == 'b' && s[i+1] == 'a') baCount++;
        }
        
        if(abCount == baCount) {
            cout << s << "\n";
        } else if (abCount > baCount) {
            for(int i = 0; i < s.length() - 1; i++) {
                if(s[i] == 'a' && s[i+1] == 'b') {
                    s[i] = 'b';
                    abCount--;
                    if(abCount == baCount) break;
                }
            }
            cout << s << "\n";
        } else {
            for(int i = 0; i < s.length() - 1; i++) {
                if(s[i] == 'b' && s[i+1] == 'a') {
                    s[i+1] = 'b';
                    baCount--;
                    if(abCount == baCount) break;
                }
            }
            cout << s << "\n";
        }
    }

    return 0;
}