#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    cout << n / 2 << endl;
    for (int i = 1; i <= n / 2; i++) {
        cout << i << " " << n - i << endl;
    }

    return 0;
}