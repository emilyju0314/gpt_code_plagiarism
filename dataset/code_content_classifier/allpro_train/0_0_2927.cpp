#include <iostream>
using namespace std;

int main() {
    int q1, b, c1, c2, q2;
    
    while (true) {
        cin >> q1;
        if (q1 == 0) {
            break;
        }
        
        cin >> b >> c1 >> c2 >> q2;
        
        int aizuChicken = q1;
        int regularChicken = 0;
        int remainingBudget = b - (q1 * c1);
        
        if (remainingBudget < 0) {
            cout << "NA" << endl;
        } else {
            int maxAizuChicken = min(remainingBudget / c1, q2);
            aizuChicken = maxAizuChicken;
            regularChicken = min((remainingBudget - (aizuChicken * c1)) / c2, remainingBudget / c2);
            
            cout << aizuChicken << " " << regularChicken << endl;
        }
    }
    
    return 0;
}