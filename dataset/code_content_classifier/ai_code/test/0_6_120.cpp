#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int l, r;
        cin >> l >> r;
        
        int highestBit = 0;
        while((1 << highestBit) <= r) {
            highestBit++;
        }
        
        highestBit--;
        
        int ans = 0;
        for(int i = highestBit; i >= 0; i--) {
            if((l & (1 << i)) && (r & (1 << i))) {
                break;
            } else if(!(l & (1 << i)) && (r & (1 << i))) {
                ans |= (1 << i);
            }
        }
        
        cout << ans << endl;
    }
    
    return 0;
}