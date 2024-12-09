#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if(n <= 9) {
        cout << "1" << endl;
        cout << n << endl;
    } else {
        int k = n / 9;
        int remainder = n % 9;

        cout << k + (remainder != 0) << endl;

        for(int i = 0; i < k; i++) {
            cout << "9 ";
        }

        if(remainder != 0) {
            cout << remainder << endl;
        }
    }

    return 0;
}