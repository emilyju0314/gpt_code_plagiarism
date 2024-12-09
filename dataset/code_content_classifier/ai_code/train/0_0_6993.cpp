#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long a, b;
    cin >> a >> b;

    long long diff = b - a;

    // Calculate the number of possible candidates of the value of Nukes's integer
    long long result = pow(2, 63 - __builtin_clzll(diff + 1)) - 1;

    cout << result << endl;

    return 0;
}