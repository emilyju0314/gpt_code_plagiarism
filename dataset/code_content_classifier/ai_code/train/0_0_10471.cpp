#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        
        vector<int> initial(n);
        vector<int> target(n);
        
        for (int i = 0; i < n; i++) {
            cin >> initial[i];
        }
        
        for (int i = 0; i < n; i++) {
            cin >> target[i];
        }
        
        int operations = 0;
        
        for (int i = 0; i < n; i++) {
            int diff = target[i] - initial[i];
            if (diff < 0) {
                diff += m;
            }
            operations += diff;
        }
        
        cout << operations << endl;
    }
    
    return 0;
}