#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        int height = 1; // initial height of the flower
        int consecutiveDaysWithoutWater = 0;
        
        for(int i = 0; i < n; i++) {
            int watered;
            cin >> watered;
            
            if(watered == 1) {
                if(consecutiveDaysWithoutWater == 1) {
                    height += 4; // grow by 5 cm
                } else {
                    height += 1; // grow by 1 cm
                }
                
                consecutiveDaysWithoutWater = 0;
            } else {
                consecutiveDaysWithoutWater++;
                
                if(consecutiveDaysWithoutWater >= 2) {
                    cout << -1 << endl; // flower dies
                    break;
                }
            }
        }
        
        if(consecutiveDaysWithoutWater < 2) {
            cout << height << endl;
        }
    }
    
    return 0;
}