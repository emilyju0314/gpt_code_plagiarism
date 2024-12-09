#include <iostream>
using namespace std;

int main() {
    long long a, b, x;
    cin >> a >> b >> x;

    long long count = x;
    while (x >= a) {
        count += x / a * b;
        x = x / a * b + x % a;
    }
    
    cout << count % 1000000007 << endl;

    return 0;
}