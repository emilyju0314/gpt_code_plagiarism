#include <iostream>
using namespace std;

int main() {
    int a00, a01, a10, a11;
    cin >> a00 >> a01 >> a10 >> a11;
    
    if (a00 == 0 && a11 == 0) {
        if (a01 == 0 && a10 == 0) {
            cout << "0" << endl;
        } else {
            cout << "Impossible" << endl;
        }
    } else if (a01 * a10 != a00 * a11) {
        cout << "Impossible" << endl;
    } else {
        string s = "";
        if (a00 > 0) {
            s += "0";
            a00--;
        } else if (a11 > 0) {
            s += "1";
            a11--;
        }
        
        while (a01 > 0 && a10 > 0) {
            if (a01 <= a10) {
                s += "0";
                s += "1";
                a01--;
                a10--;
            } else {
                s += "1";
                s += "0";
                a01--;
                a10--;
            }
        }
        
        while (a01 > 0) {
            s += "1";
            a01--;
        }
        
        while (a10 > 0) {
            s += "0";
            a10--;
        }
        
        cout << s << endl;
    }
    
    return 0;
}