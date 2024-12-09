#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        string result = s;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                if (s[i] == 'a') {
                    result[i] = 'b';
                } else {
                    result[i] = 'a';
                }
            } else {
                if (s[i] == 'z') {
                    result[i] = 'y';
                } else {
                    result[i] = 'z';
                }
            }
        }

        cout << result << endl;
    }

    return 0;
}