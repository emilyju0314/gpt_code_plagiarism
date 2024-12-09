#include <iostream>
using namespace std;

int main() {
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;

    int count = 0;
    for (int i = 1; i <= n; i++) {
        int x = i + b - c;
        int y = i + a - d;
        int z = i + a + b - c - d;

        if (x >= 1 && x <= n && y >=1 && y <= n && z >= 1 && z <= n) {
            count += n;
        }
    }

    cout << count << endl;

    return 0;
}