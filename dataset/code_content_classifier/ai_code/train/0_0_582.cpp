#include <iostream>
#include <string>

using namespace std;

int main() {
    int A, B;
    string S;
    cin >> A >> B >> S;

    if (S.length() == A+B+1 && S[A] == '-' && count_if(S.begin(), S.end(), [](char c) { return isdigit(c); }) == A+B) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}