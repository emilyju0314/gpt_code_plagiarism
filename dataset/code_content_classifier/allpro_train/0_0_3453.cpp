#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, m, k;
    
    while (true) {
        cin >> n >> m >> k;
        
        if (n == 0 && m == 0 && k == 0) {
            break;
        }
        
        double expected = 0.0;
        
        for (int i = 1; i <= m; i++) {
            double prob = 1.0 / m;
            double sum = i;
            
            for (int j = 1; j < n; j++) {
                sum += min(m, max(1, k - sum + 1));
                prob *= 1.0 / m;
            }
            
            expected += prob * sum;
        }
        
        cout << fixed << setprecision(9) << expected << endl;
    }
    
    return 0;
}