#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    string S;
    cin >> S;

    if (n == 1 && k > 0) {
        cout << "0" << endl;
        return 0;
    }

    if (k > 0) {
        if (S != "1") {
            S[0] = '1';
            k--;
        }
        for (int i = 1; i < n && k > 0; i++) {
            if (S[i] != '0') {
                S[i] = '0';
                k--;
            }
        }
    }

    cout << S << endl;

    return 0;
}