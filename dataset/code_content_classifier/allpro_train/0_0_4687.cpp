#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int b, p, f;
        cin >> b >> p >> f;
        
        int h, c;
        cin >> h >> c;
        
        int max_profit = 0;
        
        for (int i = 0; i <= p; i++) {
            for (int j = 0; j <= f; j++) {
                if (i * 2 + j <= b) {
                    max_profit = max(max_profit, i * h + j * c);
                }
            }
        }
        
        cout << max_profit << endl;
    }
    
    return 0;
}