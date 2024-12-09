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
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == 'E' && s[(i+1) % s.size()] == 'N') {
                possible = false;
                break;
            }
        }

        if(possible) {
            cout << "YES" << endl;
        }
        else {
            cout << "NO" << endl;
        }
    }

    return 0;
}