#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, S;
    
    while (true) {
        cin >> n >> S;
        
        if (n == 0 && S == 0) {
            break;
        }
        
        vector<int> powers(n);
        for (int i = 0; i < n; i++) {
            cin >> powers[i];
        }
        
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (powers[i] + powers[j] > S) {
                    count++;
                }
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}