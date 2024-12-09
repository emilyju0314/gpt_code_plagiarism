#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    cout << n + m - 1 << endl;
    for(int i = 0; i < n; i++) {
        cout << i << " " << (n + m - 1 - i) << endl;
    }

    return 0;
}