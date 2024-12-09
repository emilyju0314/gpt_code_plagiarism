#include <iostream>
#include <vector>

using namespace std;

long long kthElement(long long N, long long K) {
    if (K > N) {
        return -1;
    }
    
    long long current = 1;
    while (true) {
        if (current % N != 0 && current % K != 0) {
            if (--K == 0) {
                return current;
            }
        }
        
        current++;
    }
}

int main() {
    int C;
    cin >> C;
    
    while (C--) {
        long long N, K;
        cin >> N >> K;
        
        cout << kthElement(N, K) << endl;
    }
    
    return 0;
}