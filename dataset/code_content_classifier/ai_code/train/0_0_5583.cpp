#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "YES" << endl;
        cout << "1" << endl;
    } else if (n == 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << "1" << endl;
        cout << "3" << endl;
        cout << "2" << endl;

        for (int i = 4; i <= n; i++) {
            cout << i << endl;
        }
    }

    return 0;
}