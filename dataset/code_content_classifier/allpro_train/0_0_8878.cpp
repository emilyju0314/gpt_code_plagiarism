#include <iostream>
#include <string>

using namespace std;

int main() {
    string x;
    cin >> x;
    
    string a, b;
    bool decimalPointSeen = false;
    
    for (int i = 0; i < x.length(); i++) {
        if (x[i] == '.') {
            decimalPointSeen = true;
        } else if (x[i] != '0' || decimalPointSeen) {
            if (!decimalPointSeen) {
                a += x[i];
            } else {
                b += x[i];
            }
        }
    }
    
    if (b.empty()) {
        cout << a << endl;
    } else {
        cout << a << "E" << b.length() << endl;
    }
    
    return 0;
}