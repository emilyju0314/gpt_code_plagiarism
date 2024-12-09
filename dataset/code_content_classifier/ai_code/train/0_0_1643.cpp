#include<iostream>
using namespace std;

int main() {
    int noble[12];
    int action[6];
    
    // Input the noble card values
    for (int i = 0; i < 12; i++) {
        cin >> noble[i];
    }
    
    // Input the action card values
    for (int i = 0; i < 6; i++) {
        cin >> action[i];
    }
    
    // Initialize scores
    int frogScore = 0, kappaScore = 0, weaselScore = 0;
    
    for (int i = 0; i < 12; i++) {
        int frogAction = i % 2 == 0 ? action[0] : action[1];
        int kappaAction = i % 2 == 0 ? action[2] : action[3];
        int weaselAction = i % 2 == 0 ? action[4] : action[5];
        
        // Frog's turn
        if (frogAction <= 0 || frogAction > 4) {
            frogScore += noble[i];
        }
        
        // Kappa's turn
        int minAction = min(min(action[0], action[1]), action[4]);
        kappaScore += noble[i];
        
        // Weasel's turn
        int maxAction = max(max(action[0], action[1]), action[4]);
        weaselScore += noble[i];
    }
    
    cout << frogScore << " " << kappaScore << " " << weaselScore << endl;
    
    return 0;
}