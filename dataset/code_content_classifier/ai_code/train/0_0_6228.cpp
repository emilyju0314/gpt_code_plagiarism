#include <iostream>
#include <vector>

using namespace std;

int main() {
    int D;
    cin >> D;
    
    vector<int> sequence(D);
    
    for(int i = 0; i < D; i++) {
        cin >> sequence[i];
    }
    
    int Q;
    cin >> Q;
    
    for(int i = 0; i < Q; i++) {
        int l, r, e;
        cin >> l >> r >> e;
        
        int a = min(sequence[l-1], sequence[r-1]);
        int b = max(sequence[l-1], sequence[r-1]);
        
        int count = 0;
        for(int j = l-1; j <= r-1; j++) {
            if(sequence[j] < a - e || sequence[j] > b + e) {
                count++;
            }
        }
        
        cout << count << endl;
    }
    
    return 0;
}