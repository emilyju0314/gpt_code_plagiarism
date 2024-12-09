#include <iostream>

using namespace std;

int main() {
    int time[5], wrongSubmissions[5], successfulHacks, unsuccessfulHacks;
    
    for(int i = 0; i < 5; i++) {
        cin >> time[i];
    }
    
    for(int i = 0; i < 5; i++) {
        cin >> wrongSubmissions[i];
    }
    
    cin >> successfulHacks >> unsuccessfulHacks;
    
    int totalScore = 0;
    
    int maxPoints[5] = {500, 1000, 1500, 2000, 2500};
    for(int i = 0; i < 5; i++) {
        int score = (250 - wrongSubmissions[i]) * maxPoints[i] / 250 - 50 * wrongSubmissions[i] + 100;
        totalScore += score;
    }
    
    totalScore += 100 * successfulHacks - 50 * unsuccessfulHacks;
    
    cout << totalScore << endl;
    
    return 0;
}