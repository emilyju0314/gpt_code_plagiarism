#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    cout << 1 << endl;
    if (n == 1) {
        cout << "lea ebx, [eax]" << endl;
    } else {
        int k;
        if (n == 2) {
            k = 1;
        } else if (n == 4) {
            k = 2;
        } else {
            k = 8;
        }
        cout << "lea ebx, [" << k << "*eax]" << endl;
    }

    return 0;
}