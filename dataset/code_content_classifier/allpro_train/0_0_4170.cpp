#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        int a, b;
        cin >> a >> b;

        int diff = abs(a - b);
        int count = diff / 5;
        diff %= 5;
        count += diff / 2;
        diff %= 2;
        count += diff;

        cout << count << endl;
    }

    return 0;
}