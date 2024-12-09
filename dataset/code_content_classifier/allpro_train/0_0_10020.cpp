#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n % 2 == 0) {
        cout << "-1" << endl;
    } else {
        for (int i = 2; i <= n; i++) {
            cout << "1 " << i << endl;
        }
    }

    for (int i = 2; i <= n; i++) {
        cout << "1 " << i << endl;
    }

    return 0;
}