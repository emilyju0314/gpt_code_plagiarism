#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    while (true) {
        cin >> N;
        if (N == 0) {
            break;
        }
        
        int maxAccess = 0;
        for (int i = 0; i < N; i++) {
            int d, t;
            cin >> d >> t;
            vector<int> access(d);
            for (int j = 0; j < d; j++) {
                cin >> access[j];
            }
            
            int sum = 0;
            for (int j = 0; j < d; j++) {
                int idx = (t + j) % d;
                sum += access[idx];
                if (sum > maxAccess) {
                    maxAccess = sum;
                }
                if (sum < 0) {
                    sum = 0;
                }
            }
        }
        
        cout << maxAccess << endl;
    }
    return 0;
}