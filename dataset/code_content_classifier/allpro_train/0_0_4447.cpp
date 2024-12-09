#include <iostream>
#include <string>

using namespace std;

int main() {
    string a;
    cin >> a;

    int index = -1;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '0') {
            index = i;
            break;
        }
    }

    if (index == -1) {
        // If a does not contain any '0', delete the first digit
        a = a.substr(1);
    } else {
        // Delete the '0' digit found
        a.erase(index, 1);
    }

    cout << a << endl;

    return 0;
}