#include <iostream>

using namespace std;

int main() {
    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;

        if (n % 2 == 0) {
            cout << n/2 << endl;
        } else {
            cout << (n-1)/2 << endl;
        }
    }

    return 0;
}