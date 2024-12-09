#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string s;
        cin >> s;

        bool consistent = true;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'N' && s[(i+1)%s.size()] == 'N') {
                consistent = true;
                break;
            } else if (s[i] == 'E' && s[(i+1)%s.size()] == 'E') {
                consistent = true;
                break;
            } else if (s[i] == 'N' && s[(i+1)%s.size()] == 'E') {
                consistent = false;
                break;
            }
        }

        if (consistent) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;

}