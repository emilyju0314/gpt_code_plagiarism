#include <iostream>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    for (int x = 0; x <= n/a; x++) {
        if ((n - x*a) % b == 0) {
            cout << "YES" << endl;
            cout << x << " " << (n - x*a) / b << endl;
            return 0;
        }
    }
    
    cout << "NO" << endl;

    return 0;
}