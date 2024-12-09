#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    string s;

    // Taking input
    cin >> n;
    cin >> s;

    int maxRemovable = 0;

    // Iterate through the string
    while (true) {
        bool removed = false;

        // Check if there are any characters that can be removed
        for (int i = 0; i < s.length(); i++) {
            if (i > 0 && s[i] == s[i-1] + 1) {
                s.erase(i, 1);
                removed = true;
                break;
            } else if (i < s.length() - 1 && s[i] == s[i+1] + 1) {
                s.erase(i, 1);
                removed = true;
                break;
            }
        }

        // If no character was removed, break out of the loop
        if (!removed) {
            break;
        }

        maxRemovable++;
    }

    cout << maxRemovable << endl;

    return 0;
}