#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    string gameField;
    cin >> gameField;
    
    vector<int> packmenPos;
    vector<int> asterisksPos;
    
    for(int i = 0; i < n; i++) {
        if(gameField[i] == 'P') {
            packmenPos.push_back(i);
        } else if(gameField[i] == '*') {
            asterisksPos.push_back(i);
        }
    }
    
    int numAsterisks = asterisksPos.size();
    
    int minTime = n; // Initialize minTime to maximum possible value
    
    for(int i = 0; i < packmenPos.size(); i++) {
        if(i == 0) {
            minTime = min(minTime, max(asterisksPos.back() - packmenPos[i], packmenPos[i] - asterisksPos[0]));
        } else {
            minTime = min(minTime, max(asterisksPos.back() - packmenPos[i], packmenPos[i] - asterisksPos[0]));
        }
    }
    
    cout << numAsterisks << " " << minTime << endl;
    
    return 0;
}