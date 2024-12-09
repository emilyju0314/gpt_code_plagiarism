#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int k2, k3, k5, k6;
    cin >> k2 >> k3 >> k5 >> k6;

    int twos = min(k2, min(k5, k6));
    int sum = twos * 256;
    k2 -= twos;
    k5 -= twos;
    k6 -= twos;

    int threes = min(k2, k3);
    sum += threes * 32;

    cout << sum << endl;

    return 0;
}