#include <iostream>
#include <string>

using namespace std;

string solve(string a, string s) {
    int n = a.size();
    int m = s.size();

    if (n > m) {
        return "-1";
    }

    string b = "";
    for (int i = 0; i < m - n; i++) {
        b += '0';
    }

    for (int i = n-1; i >= 0; i--) {
        int digit_a = a[i] - '0';
        int digit_s = s[i + m - n] - '0';
        int sum = digit_s - digit_a;
        if (sum < 0 || sum % 10 != 0) {
            return "-1";
        }
        b = to_string(sum/10) + b;
    }

    return b;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        string a, s;
        cin >> a >> s;

        string result = solve(a, s);
        cout << result << endl;
    }

    return 0;
}