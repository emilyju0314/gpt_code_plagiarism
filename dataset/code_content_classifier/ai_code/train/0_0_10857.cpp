#include <iostream>
#include <string>

using namespace std;

int main() {
    string password;
    cin >> password;

    int prefixLength = 0, suffixLength = 0;

    // Find the maximum possible length for prefix and suffix
    for (int i = 0; i < password.length() / 2; i++) {
        if (password[i] == password[password.length() - 1 - i]) {
            prefixLength++;
            suffixLength++;
        } else {
            break;
        }
    }

    int middleLength = 1;

    // Output the results
    cout << "3" << endl;
    cout << "1 " << prefixLength << endl;
    cout << prefixLength + 1 << " " << middleLength << endl;
    cout << password.length() - suffixLength + 1 << " " << suffixLength << endl;

    return 0;
}