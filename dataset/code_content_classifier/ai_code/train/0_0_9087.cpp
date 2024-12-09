#include <iostream>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    int x, y;
    cin >> x >> y;
    
    int result = 0;
    
    if (x - k >= 0) result++;
    if (x + k < n) result++;
    if (y - k >= 0) result++;
    if (y + k < m) result++;
    
    cout << result << endl;
    
    return 0;
}