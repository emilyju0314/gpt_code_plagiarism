#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        int ab_count = 0, ba_count = 0;

        // Count the occurrences of "ab" and "ba" sub-strings
        for(int i = 0; i < s.length() - 1; i++) {
            if(s[i] == 'a' && s[i+1] == 'b') {
                ab_count++;
            }
            if(s[i] == 'b' && s[i+1] == 'a') {
                ba_count++;
            }
        }

        // Check if counts are already equal
        if(ab_count == ba_count) {
            cout << s << endl;
        } else if(ab_count > ba_count) {
            // Replace 'a' with 'b' to reduce ab_count
            for(int i = 0; i < s.length() - 1; i++) {
                if(s[i] == 'a' && s[i+1] == 'b') {
                    s[i] = 'b';
                    ab_count--;
                    if(ab_count == ba_count) {
                        break;
                    }
                }
            }
            cout << s << endl;
        } else {
            // Replace 'b' with 'a' to reduce ba_count
            for(int i = 0; i < s.length() - 1; i++) {
                if(s[i] == 'b' && s[i+1] == 'a') {
                    s[i+1] = 'b';
                    ba_count--;
                    if(ab_count == ba_count) {
                        break;
                    }
                }
            }
            cout << s << endl;
        }
    }

    return 0;
}