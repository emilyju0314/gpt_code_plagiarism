#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) {
            break;
        }
        
        vector<int> capacities(n);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            cin >> capacities[i];
            sum += capacities[i];
        }
        
        int max_capacity = *max_element(capacities.begin(), capacities.end());
        
        if (max_capacity <= (sum - max_capacity)) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}