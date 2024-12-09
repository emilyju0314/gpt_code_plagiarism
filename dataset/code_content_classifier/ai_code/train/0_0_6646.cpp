#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    string S;
    long long K;

    cin >> S >> K;

    for (int i = 0; i < 5 * pow(10, 15); i++) {
        string temp = "";
        for (int j = 0; j < S.length(); j++) {
            if (S[j] == '1') {
                temp += "1";
            } else {
                temp += string(S[j] - '0', S[j]);
            }
        }
        S = temp;
    }

    cout << S[K - 1] << endl;

    return 0;
}