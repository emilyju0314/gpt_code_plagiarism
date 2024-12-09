#include <iostream>
#include <string>

using namespace std;

string subtract(string a, string b) {
    while (a.size() > 1 && a[0] == '0') a.erase(0,1);
    while (b.size() > 1 && b[0] == '0') b.erase(0,1);

    if (a == b) return "0";

    bool sign = false;
    if (a.size() < b.size() || (a.size() == b.size() && a < b)) {
        swap(a,b);
        sign = true;
    }

    string res = "";
    int carry = 0;
    int n = a.size();
    int m = b.size();
    
    for (int i = 0; i < n; i++) {
        int c = a[n-i-1] - '0' - carry;
        if (i < m) c -= b[m-i-1] - '0';
        
        if (c < 0) {
            c += 10;
            carry = 1;
        } else {
            carry = 0;
        }

        res = to_string(c) + res;
    }

    while (res.size() > 1 && res[0] == '0') res.erase(0,1);
    
    if (sign) res = "-" + res;

    return res;
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << subtract(a, b) << endl;

    return 0;
}