#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;

    while (true) {
        cin >> n >> m;

        if (n == 0 && m == 0) break;
        
        vector<int> trays(n);
        
        for (int i = 0; i < n; i++) {
            cin >> trays[i];
        }
        
        int max_scones = 0;
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += trays[j];
                if (sum % m > max_scones) {
                    max_scones = sum % m;
                }
            }
        }
        
        cout << max_scones << endl;
    }

    return 0;
}