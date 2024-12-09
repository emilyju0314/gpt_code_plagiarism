#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n, m;
    
    while (cin >> n >> m) {
        if (n == 0 && m == 0) {
            break;
        }
        
        vector<int> multiples(m);
        
        for (int i = 0; i < m; i++) {
            cin >> multiples[i];
        }
        
        double total_possible_years = n - m;
        double sum = 0.0;
        
        for (int i = 1; i <= n; i++) {
            bool possible = true;
            
            for (int j = 0; j < m; j++) {
                if (i % multiples[j] == 0) {
                    possible = false;
                    break;
                }
            }
            
            if (possible) {
                sum += i;
            }
        }
        
        cout << fixed << setprecision(10) << sum / total_possible_years << endl;
    }
    
    return 0;
}