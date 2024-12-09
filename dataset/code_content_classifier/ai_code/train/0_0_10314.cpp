#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    if (n == 1 || m == 1) {
        cout << 0 << endl;
    } else {
        cout << (n*m) - max(n, m)*2 << endl;
    }

    return 0;
}