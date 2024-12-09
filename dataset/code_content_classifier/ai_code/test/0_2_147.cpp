#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string s;
        cin >> s;

        bool possible = true;
        // Check if any consecutive N followed by E leads to inconsistency
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'N' && s[(i+1)%s.length()] == 'E') {
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}