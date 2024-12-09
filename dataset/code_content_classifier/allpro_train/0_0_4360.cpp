#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long ans = (pow(2, n) + 1) % 1000000007;
    cout << ans << endl;

    return 0;
}