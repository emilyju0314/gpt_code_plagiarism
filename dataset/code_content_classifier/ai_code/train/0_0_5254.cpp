#include <iostream>

using namespace std;

int main() {
    long long n, q;
    cin >> n >> q;

    for(int i = 0; i < q; i++) {
        long long x;
        cin >> x;

        if(x % 2 == 1) {
            cout << (x + 1) / 2 << endl;
        } else {
            cout << (n + 1) / 2 + (n - x) / 2 << endl;
        }
    }

    return 0;
}