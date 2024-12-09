#include <iostream>
#include <string>

using namespace std;

string bitwiseAnd(string x, string y) {
    string result = "";
    for (int i = 0; i < min(x.length(), y.length()); i++) {
        if (x[i] == '1' && y[i] == '1') {
            result += '1';
        } else {
            result += '0';
        }
    }
    return result;
}

string addBinary(string a, string b) {
    string result = "";
    int carry = 0;
    int i = a.length() - 1, j = b.length() - 1;

    while (i >= 0 || j >= 0 || carry > 0) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0';
        if (j >= 0) sum += b[j--] - '0';

        result = to_string(sum % 2) + result;
        carry = sum / 2;
    }

    return result;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    string s, t;
    cin >> s >> t;

    string takahashi = s;
    string aoki = t;

    for (int i = 0; i < k; i++) {
        string z = bitwiseAnd(takahashi, aoki);
        takahashi = addBinary(takahashi, z);
        aoki = addBinary(aoki, z);
    }

    cout << takahashi << endl;
    cout << aoki << endl;

    return 0;
}