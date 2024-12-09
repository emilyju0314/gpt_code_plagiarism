#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int points[50];
    for (int i = 0; i < n; i++) {
        cin >> points[i];
    }
    
    int prizes[5];
    for (int i = 0; i < 5; i++) {
        cin >> prizes[i];
    }
    
    int numPrizes[5] = {0};
    int remainingPoints = 0;
    int currentPoints = 0;
    
    for (int i = 0; i < n; i++) {
        currentPoints += points[i];
        
        for (int j = 4; j >= 0; j--) {
            int numAvailablePrizes = currentPoints / prizes[j];
            numPrizes[j] += numAvailablePrizes;
            currentPoints = currentPoints - numAvailablePrizes * prizes[j];
        }
        
        remainingPoints = currentPoints;
    }
    
    for (int i = 0; i < 5; i++) {
        cout << numPrizes[i] << " ";
    }
    cout << endl;
    cout << remainingPoints << endl;
    
    return 0;
}