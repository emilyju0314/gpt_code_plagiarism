#include <iostream>
#include <cmath>

using namespace std;

long long countPairs(int L) {
    long long count = 0;
    
    for (int i = 1; i <= sqrt(L); i++) {
        if (L % i == 0) {
            int j = L / i;
            if (i <= j) {
                count++;
                if (i != j) {
                    count++;
                }
            }
        }
    }
    
    return count;
}

int main() {
    int L;
    
    while (true) {
        cin >> L;
        
        if (L == 0) {
            break;
        }
        
        cout << countPairs(L) << endl;
    }
    
    return 0;
}