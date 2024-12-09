#include <iostream>
#include <string>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int pos = 0;
    bool found = true;
    for (char c : t) {
        pos = s.find(c, pos);
        if (pos == string::npos) {
            found = false;
            break;
        }
        pos++;
    }

    if (found) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}