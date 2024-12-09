#include <iostream>
using namespace std;

int main() {
    int a, b, n;
    cin >> a >> b >> n;

    long long ways = 1;
    for (int i = 1; i <= b; i++) {
        ways *= a + i;
        if (ways >= n) {
            if (i % 2 == 1) {
                cout << "Stas" << endl;
            } else {
                cout << "Masha" << endl;
            }
            return 0;
        }
    }

    cout << "Missing" << endl;

    return 0;
}