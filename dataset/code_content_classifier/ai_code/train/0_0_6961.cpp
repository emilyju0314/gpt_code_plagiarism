#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string heading, text;
    getline(cin, heading);
    getline(cin, text);

    for (char c : text) {
        if (c != ' ') {
            size_t pos = heading.find(c);
            if (pos != string::npos) {
                heading[pos] = ' '; // Mark the letter as used
            } else {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;

    return 0;
}