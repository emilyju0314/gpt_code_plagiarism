#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string message;
    cin >> message;

    int actionsNeeded = 0;
    bool foundLowercase = false;

    for (char c : message) {
        if (islower(c)) {
            foundLowercase = true;
        } else if (foundLowercase && isupper(c)) {
            actionsNeeded++;
        }
    }

    cout << actionsNeeded << endl;

    return 0;
}