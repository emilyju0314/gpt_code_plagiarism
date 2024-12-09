#include <iostream>
#include <string>

using namespace std;

string bitwiseXOR(string l, string r) {
    string result = "";
    for (int i = 0; i < l.length(); i++) {
        if (l[i] == r[i]) {
            result += "0";
        } else {
            result += "1";
        }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    
    string l, r;
    cin >> l >> r;

    string result = bitwiseXOR(l, r);
    for (int i = 0; i < n; i++) {
        if (result[i] == '0') {
            result[i] = '1';
            break;
        }
    }

    cout << result << endl;

    return 0;
}