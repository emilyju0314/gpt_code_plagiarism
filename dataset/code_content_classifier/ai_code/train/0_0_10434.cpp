#include <iostream>
#include <vector>

using namespace std;

int main() {
    int k;
    cin >> k;

    if (k % 2 == 0) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        cout << "3 3" << endl;
        cout << "1 2" << endl;
        cout << "2 3" << endl;
        cout << "3 1" << endl;
    }

    return 0;
}