#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        // Find the factors of n
        int a = 1, b, c;
        while(n % a == 0) {
            a++;
        }
        b = a + 1;
        while(n % (a * b) == 0 || b % a == 0) {
            b++;
        }
        c = n / (a * b);

        cout << a << " " << b << " " << c << endl;
    }

    return 0;
}