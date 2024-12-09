#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        int a = 1, b = 2;
        while (a * b <= n) {
            b++;
            if (n % (a * b) == 0) {
                cout << a << " " << a * b << " " << n / (a * b) << endl;
                break;
            }
        }
    }

    return 0;
}