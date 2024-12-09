#include <iostream>
#include <string>

using namespace std;

int main() {
    string S;
    cin >> S;

    if (S[0] == 'A' && S[1] == 'B') {
        cout << "Yes" << endl;
    } else if (S[1] == 'A' && S[2] == 'B') {
        cout << "Yes" << endl;
    } else if (S[0] == 'A' && S[2] == 'B') {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}