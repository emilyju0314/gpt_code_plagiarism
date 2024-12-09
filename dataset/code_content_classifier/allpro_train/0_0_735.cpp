#include <iostream>
using namespace std;

int main() {
    long long n, a, b, c;
    cin >> n >> a >> b >> c;

    long long maxLiters = n / a; // Maximum number of liters that can be bought with plastic bottles
    long long remainingMoney = n - maxLiters * a; // Money left after buying with plastic bottles

    if (remainingMoney >= (b - c)) {
        maxLiters += (remainingMoney - (b - c)) / (b - c); // Additional liters that can be bought with glass bottles using the money left
    }

    cout << maxLiters << endl;

    return 0;
}