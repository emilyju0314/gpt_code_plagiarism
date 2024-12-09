#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;
        
        bool possible = true;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == 'E' && s[(i+1)%n] == 'N') { // check if there are contradictory pairs
                possible = false;
                break;
            }
        }

        if (possible) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}