#include <iostream>
using namespace std;

int main() {
    long long n;
    cin >> n;

    // Calculate the number of plants that point "upwards" after n years
    long long res = 1;
    for (int i = 1; i <= n; i++) {
        res = (3 * res + res) % 1000000007;
    }

    cout << res << endl;

    return 0;
}