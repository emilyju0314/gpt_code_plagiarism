#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    if (n == 1) {
        cout << 0 << endl;
    } else {
        cout << min(a, b) + min(c, a+b) * (n-2) << endl;
    }

    return 0;
}