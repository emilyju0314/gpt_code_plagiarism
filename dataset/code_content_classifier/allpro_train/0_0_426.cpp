#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int MOD = 1e9 + 7;

int stringToInt(string s) {
    int result = 0;
    for (char c : s) {
        result = result * 10 + (c - '0');
    }
    return result;
}

int main() {
    string S, T;
    cin >> S >> T;

    long long sum = 0;

    int count = 1;
    for (char c : T) {
        if (c == '?') {
            count *= 10;
        }
    }

    for (int i = 0; i < 10; i++) {
        string temp = T;
        for (int j = 0; j < temp.size(); j++) {
            if (temp[j] == '?') {
                temp[j] = i + '0';
            }
        }
        if (stringToInt(temp) <= stringToInt(S)) {
            sum += stringToInt(temp);
        }
    }

    cout << sum % MOD << endl;

    return 0;
}