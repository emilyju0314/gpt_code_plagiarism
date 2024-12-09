#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cin >> input;

    bool flag = true;
    for(int i = 0; i < input.length(); i++) {
        if ((i % 2 == 0 && (input[i] - '0') % 2 != 0) || (i % 2 == 1 && (input[i] - '0') % 2 == 0)) {
            flag = false;
            break;
        }
    }

    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}