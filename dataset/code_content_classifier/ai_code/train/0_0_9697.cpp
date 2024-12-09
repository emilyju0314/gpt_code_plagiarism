#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N, L;
    
    while (true) {
        cin >> N >> L;
        
        if (N == 0 && L == 0) {
            break;
        }
        
        double minSpeed = 0;
        double currTank = L;
        
        for (int i = 0; i < N; i++) {
            int s, t, u;
            cin >> s >> t >> u;
            
            minSpeed = max(minSpeed, (double)u);
            
            currTank += (s - (i == 0 ? 0 : t)) * minSpeed;
            currTank = min(currTank, (double)L);
        }
        
        cout << fixed << setprecision(6) << minSpeed << endl;
    }
    
    return 0;
}