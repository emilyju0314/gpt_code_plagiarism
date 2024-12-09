#include <iostream>

using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    int maxPillows = min(m - 1, n - k) + 1;
    
    if (n > 1) {
        int diff = maxPillows - 1;
        int remainingPillows = m - maxPillows;
        int equalPillows = remainingPillows / (n - 1);
        
        if (diff < equalPillows) {
            maxPillows -= equalPillows;
        } else {
            maxPillows -= diff;
        }
    }
    
    cout << maxPillows << endl;

    return 0;
}