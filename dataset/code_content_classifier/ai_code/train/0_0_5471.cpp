#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<string> matrix(n);
    for(int i = 0; i < n; i++) {
        cin >> matrix[i];
    }
    
    long long result = 0;
    
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            int count = 0;
            for(int k = 0; k < n; k++) {
                if (k != i && k != j && matrix[i][k/4] & (1 << (k % 4)) && matrix[j][k/4] & (1 << (k % 4))) {
                    count++;
                }
            }
            
            result += (n-1-count)*count;
        }
    }
    
    cout << result * 2 << endl;
    
    return 0;
}