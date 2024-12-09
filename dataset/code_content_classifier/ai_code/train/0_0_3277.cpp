#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    int n;
    
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        
        vector<int> combatPower(n);
        int total = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> combatPower[i];
            total += combatPower[i];
        }
        
        vector<bool> possible(total + 1, false);
        possible[0] = true;
        
        for (int i = 0; i < n; i++) {
            for (int j = total; j >= combatPower[i]; j--) {
                if (possible[j - combatPower[i]]) {
                    possible[j] = true;
                }
            }
        }
        
        int minDiff = total;
        
        for (int i = 0; i <= total / 2; i++) {
            if (possible[i]) {
                minDiff = min(minDiff, total - 2 * i);
            }
        }
        
        cout << minDiff << endl;
    }
    
    return 0;
}