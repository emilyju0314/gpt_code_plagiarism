#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << "YES" << endl << "1" << endl;
    } else if (n == 4) {
        cout << "YES" << endl << "1" << endl << "3" << endl << "2" << endl << "4" << endl;
    } else if (n < 4) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << "1" << endl << "4" << endl << "3" << endl << "6" << endl << "5" << endl << "2" << endl;

        for (int i = 7; i <= n; i++) {
            cout << i << endl;
        }
    }

    return 0;
}