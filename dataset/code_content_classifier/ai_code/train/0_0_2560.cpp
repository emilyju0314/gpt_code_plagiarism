#include <iostream>
#include <vector>

using namespace std;

int calculatePoints(int time, int maxScore) {
    if (time == 0) {
        return maxScore;
    } else if (time < 0) {
        return maxScore + 50;
    } else {
        return maxScore - 2*min(time, 50);
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> times(n, vector<int>(3));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> times[i][j];
        }
    }
    
    vector<int> options = {0, 1};
    int bestPlace = n;
    
    for (int option : options) {
        int myScore = 0;
        
        for (int i = 0; i < n; i++) {
            int score = 0;
            
            for (int j = 0; j < 3; j++) {
                if (times[i][j] > 0 && (option == 1 || i == 0)) {
                    score += calculatePoints(times[i][j], 500);
                }
            }
            
            if (i != 0) {
                myScore += max(0, score);
            } else {
                myScore += score;
            }
        }
        
        int place = 1;
        
        for (int i = 0; i < n; i++) {
            int otherScore = 0;
            
            for (int j = 0; j < 3; j++) {
                if (times[i][j] > 0) {
                    otherScore += calculatePoints(times[i][j], 500);
                }
            }
            
            if (otherScore > myScore) {
                place++;
            }
        }
        
        bestPlace = min(bestPlace, place);
    }
    
    cout << bestPlace << endl;
    
    return 0;
}