#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    int totalTiles = (a + b + c - 2) * (a + b + c - 1) / 2;

    cout << totalTiles << endl;

    return 0;
}