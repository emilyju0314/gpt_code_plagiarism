#include <iostream>
#include <string>

using namespace std;

int main() {
    int L;
    string A;
    cin >> L >> A;

    int A_length = A.length();
    int P_length = (A_length + L - 1) / L;
    string P = string(P_length, '0');
    P[0] = '1';

    string X = P;
    while (X.length() < A_length) {
        X += P;
    }

    if (X <= A) {
        X += P;
    }

    cout << X.substr(0, A_length) << endl;

    return 0;
}