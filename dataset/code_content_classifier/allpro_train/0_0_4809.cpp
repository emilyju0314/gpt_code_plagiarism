#include <iostream>
using namespace std;

int main() {
    long long n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;

    long long redTiles = n/a;
    long long blueTiles = n/b;
    
    long long redBlueTiles = n/(a*b);

    long long chocolates = (redTiles*p) + (blueTiles*q) - min(p, q)*redBlueTiles;

    cout << chocolates << endl;

    return 0;
}