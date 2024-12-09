#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string S, T;
        cin >> S >> T;

        string SPrime = S;
        
        for (int i = 0; i < SPrime.length(); i++) {
            if (SPrime[i] == T[0]) {
                SPrime[i] = ' ';
            } else if (SPrime[i] == T[1] && count(SPrime.begin(), SPrime.end(), T[0]) < count(S.begin(), S.end(), T[0])) {
                SPrime[i] = ' ';
            } else if (SPrime[i] == T[2] && count(SPrime.begin(), SPrime.end(), T[0]) < count(S.begin(), S.end(), T[0]) && count(SPrime.begin(), SPrime.end(), T[1]) < count(S.begin(), S.end(), T[1])) {
                SPrime[i] = ' ';
            }
        }

        string result = "";
        for (int i = 0; i < SPrime.length(); i++) {
            if (SPrime[i] != ' ') {
                result += SPrime[i];
            }
        }

        cout << result << endl;
    }

    return 0;
}