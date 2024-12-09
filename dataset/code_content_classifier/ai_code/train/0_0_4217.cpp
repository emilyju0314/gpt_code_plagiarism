#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << "1" << endl;
    if (n % 4 == 0) {
        cout << "lea ebx, [" << n << "*eax]" << endl;
    } else {
        int k = 1;
        while (n % k != 0) {
            k *= 2;
        }
        if (k == n) {
            cout << "lea ebx, [eax + eax]" << endl;
        } else {
            cout << "lea ebx, [eax + " << n/k << "*eax]" << endl;
            cout << "lea ecx, [eax + " << k << "*ebx]" << endl;
        }
    }

    return 0;
}