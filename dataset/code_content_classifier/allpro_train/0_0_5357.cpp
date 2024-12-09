#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int scores[6];
    for(int i = 0; i < 6; i++) {
        cin >> scores[i];
    }
    
    int maxScore = 0;
    
    // Choose 3 subjects from physics, chemistry, biology, and earth science
    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 4; j++) {
            for(int k = j + 1; k < 4; k++) {
                int totalScore = scores[i] + scores[j] + scores[k];
                
                // Choose 1 subject from history and geography
                totalScore += max(scores[4], scores[5]);
                
                maxScore = max(maxScore, totalScore);
            }
        }
    }
    
    cout << maxScore << endl;
    
    return 0;
}