#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    int N, M;
    cin >> N;
    
    unordered_map<string, int> liquidDensity;
    
    for (int i = 0; i < N; i++) {
        string color;
        int density;
        cin >> color >> density;
        if (liquidDensity.find(color) == liquidDensity.end()) {
            liquidDensity[color] = density;
        } else {
            liquidDensity[color] = min(liquidDensity[color], density);
        }
    }
    
    cin >> M;
    vector<string> drinkRequest(M);
    
    for (int i = 0; i < M; i++) {
        cin >> drinkRequest[i];
    }
    
    int prevDensity = INT_MAX;
    bool canServe = true;
    
    for (int i = 0; i < M; i++) {
        if (liquidDensity.find(drinkRequest[i]) == liquidDensity.end() || liquidDensity[drinkRequest[i]] >= prevDensity) {
            canServe = false;
            break;
        }
        prevDensity = liquidDensity[drinkRequest[i]];
    }
    
    if (canServe) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}