#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    int t;
    cin >> t;
 
    while (t--) {
        string s;
        cin >> s;
 
        int n = s.size();
        int cntAB = 0, cntBA = 0;
 
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'a' && s[i + 1] == 'b') {
                cntAB++;
            }
            if (s[i] == 'b' && s[i + 1] == 'a') {
                cntBA++;
            }
        }
 
        if (cntAB == 0 && cntBA == 0) {
            cout << s << endl;
        } else if (cntAB == cntBA) {
            cout << s << endl;
        } else if (cntAB > cntBA) {
            for (int i = 0; i < n - 1; i++) {
                if (s[i] == 'a' && s[i + 1] == 'b') {
                    s[i + 1] = 'a';
                    break;
                }
            }
            cout << s << endl;
        } else {
            for (int i = 0; i < n - 1; i++) {
                if (s[i] == 'b' && s[i + 1] == 'a') {
                    s[i + 1] = 'b';
                    break;
                }
            }
            cout << s << endl;
        }
    }
 
    return 0;
}