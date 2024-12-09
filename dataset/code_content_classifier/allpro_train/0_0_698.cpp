#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b, mod;
    cin >> a >> b >> mod;

    if (a == 0) {
        cout << "2" << endl;
    } else {
        int x = 0;
        string s1;
        for (int i = 1; i < 10; i++) {
            int digit = (i * a) % 10;
            if (digit == 0 || digit == b) {
                x = i;
                break;
            }
        }

        if (x == 0) {
            cout << "2" << endl;
        } else {
            s1.append(to_string(x) + string(8, '0'));
            cout << "1 " << s1 << endl;
        }
    }

    return 0;
}