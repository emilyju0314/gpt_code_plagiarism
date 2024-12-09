#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;

    int diff = 0;
    string x = "", y = "";

    if (k == 0) {
        if (b == 0) {
            cout << "Yes" << endl;
            x = string(a, '0');
            y = x;
        } else {
            cout << "No" << endl;
        }
    } else {
        if (a == 0 || b == 0 || a + b < 2) {
            cout << "No" << endl;
        } else {
            diff = k - 1;
            x = "1";
            y = "1";
            b--;

            for (int i = 0; i < a; i++) {
                x += "0";
                y += "0";
            }

            for (int i = 0; i < b; i++) {
                x += "1";
                y += "1";
            }

            y[b - diff] = '0';
            
            cout << "Yes" << endl;
            cout << x << endl;
            cout << y << endl;
        }
    }
    
    return 0;
}