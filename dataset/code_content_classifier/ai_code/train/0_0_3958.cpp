#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> holes(14);
    
    for (int i = 0; i < 14; i++) {
        cin >> holes[i];
    }
    
    int maxScore = 0;
    
    for (int i = 0; i < 14; i++) {
        if (holes[i] == 0) continue;
        
        vector<int> tempHoles = holes;
        int stones = tempHoles[i];
        tempHoles[i] = 0;
        
        for (int j = 0; j < 14; j++) {
            tempHoles[j] += stones / 14;
        }
        
        stones %= 14;
        int idx = i + 1;
        
        while (stones > 0) {
            tempHoles[idx % 14]++;
            stones--;
            idx++;
        }
        
        int score = 0;
        
        for (int k = 0; k < 14; k++) {
            if (tempHoles[k] % 2 == 0) {
                score += tempHoles[k];
            }
        }
        
        maxScore = max(maxScore, score);
    }
    
    cout << maxScore << endl;
    
    return 0;
}