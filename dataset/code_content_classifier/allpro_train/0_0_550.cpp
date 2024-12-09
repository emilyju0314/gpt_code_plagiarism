#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    
    int x, y, n;
    cin >> x >> y >> n;
    
    int ans = x;
    if (ans <= a) {
        ans = a;
    } else if (ans + n > b) {
        ans = b;
    } else {
        ans += n;
    }
    
    cout << ans * y << endl;
    
    return 0;
}