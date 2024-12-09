#include <iostream>
#include <string>

using namespace std;

const long long MOD = 1000000007;

int main() {
    string s;
    cin >> s;

    int n;
    cin >> n;

    for(int i = 0; i < n; i++) {
        char digit;
        string replacement;
        cin >> digit;
        cin.ignore();
        getline(cin, replacement);

        size_t found = s.find(digit);
        while(found != string::npos) {
            s.replace(found, 1, replacement);
            found = s.find(digit);
        }
    }

    long long result = 0;
    for(int i = 0; i < s.length(); i++) {
        result = (result * 10 + (s[i] - '0')) % MOD;
    }

    cout << result << endl;

    return 0;
}