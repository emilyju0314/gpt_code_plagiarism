#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool canWin(double swimmingSpeed, double runningSpeed, double R, double S) {
    return (R/swimmingSpeed) < (S/runningSpeed);
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<double, double>> competitors;
    
    for(int i = 0; i < n; i++) {
        double swimmingSpeed, runningSpeed;
        cin >> swimmingSpeed >> runningSpeed;
        competitors.push_back({swimmingSpeed, runningSpeed});
    }
    
    vector<int> possibleWinners;
    
    for(int i = 0; i < n; i++) {
        bool isWinner = true;
        for(int j = 0; j < n; j++) {
            if(i != j) {
                if(canWin(competitors[j].first, competitors[j].second, competitors[i].second, competitors[i].first)) {
                    isWinner = false;
                    break;
                }
            }
        }
        if(isWinner) {
            possibleWinners.push_back(i+1);
        }
    }
    
    sort(possibleWinners.begin(), possibleWinners.end());
    
    for(int i = 0; i < possibleWinners.size(); i++) {
        cout << possibleWinners[i] << " ";
    }
    
    return 0;
}