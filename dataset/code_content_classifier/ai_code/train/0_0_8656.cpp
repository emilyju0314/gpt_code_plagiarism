#include <iostream>
#include <vector>

using namespace std;

int main() {
    int T, D, L;
    
    while (cin >> T >> D >> L) {
        
        if (T == 0 && D == 0 && L == 0) {
            break;
        }
        
        vector<int> x(T);
        // Read the x values
        for (int i = 0; i < T; i++) {
            cin >> x[i];
        }
        
        int lastWet = 0;
        int lastDry = -1 * D;
        
        for (int i = 0; i < T; i++) {
            if (x[i] >= L) {
                if (i - lastDry <= D) {
                    lastWet = i + 1;
                } else {
                    lastWet = i - (i - lastDry - D) + 1;
                }
                lastDry = i;
            }
        }
        
        cout << lastWet << endl;
    }
    
    return 0;
}