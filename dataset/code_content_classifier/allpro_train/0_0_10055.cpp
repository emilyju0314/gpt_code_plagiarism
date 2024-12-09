#include <iostream>
using namespace std;

int main() {
    int n, k, a, b;
    cin >> n >> k >> a >> b;

    // Calculate minimum number of stops
    int x = max((a == 0 && n > 1) ? k : 0, a + b);
    
    // Calculate maximum number of stops
    int y = min(k - a, (n-1) * k - a + k - b);

    cout << x << " " << y << endl;

    return 0;
}