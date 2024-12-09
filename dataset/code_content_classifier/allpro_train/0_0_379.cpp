#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int cnt1, cnt2, x, y;
    cin >> cnt1 >> cnt2 >> x >> y;
    
    int low = max(x, y) + 1;
    int high = min(cnt1 + cnt2, max(x, y) * 2);
    
    while(low < high) {
        int mid = low + (high - low) / 2;
        int divisibleByX = mid / x;
        int divisibleByY = mid / y;
        
        if (mid - divisibleByX - divisibleByY >= cnt1 + cnt2) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }
    
    cout << low << endl;
    
    return 0;
}