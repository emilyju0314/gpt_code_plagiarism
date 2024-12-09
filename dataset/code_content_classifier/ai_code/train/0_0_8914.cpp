#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, Q;
    cin >> N;
    
    vector<int> sequence(N);
    for(int i = 0; i < N; i++) {
        cin >> sequence[i];
    }
    
    cin >> Q;
    
    for(int i = 0; i < Q; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        
        l--; // adjust for 0-based indexing
        r--; // adjust for 0-based indexing
        
        bool isExact = true;
        for(int j = l, k = r; j <= r && k >= l; j++, k--) {
            if(sequence[j] != sequence[k]) {
                isExact = false;
                break;
            }
        }
        
        cout << (isExact ? 1 : 0) << endl;
    }
    
    return 0;
}