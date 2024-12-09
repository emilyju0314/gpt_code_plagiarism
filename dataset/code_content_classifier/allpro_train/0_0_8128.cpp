#include <iostream>
#include <vector>

using namespace std;

int main() {
    int K;
    
    while (true) {
        cin >> K;
        if (K == 0) {
            break;
        }
        
        vector<int> sales(K*(K-1)/2);
        int total_sales = 0;
        
        for (int i = 0; i < K*(K-1)/2; i++) {
            cin >> sales[i];
            total_sales += sales[i];
        }
        
        cout << total_sales << endl;
    }
    
    return 0;
}