#include <iostream>
using namespace std;

int main() {
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    
    int gcd = __gcd(x, y);
    x /= gcd;
    y /= gcd;
    
    int maxFactor = min(a / x, b / y);
    
    cout << x * maxFactor << " " << y * maxFactor << endl;
    
    return 0;
}