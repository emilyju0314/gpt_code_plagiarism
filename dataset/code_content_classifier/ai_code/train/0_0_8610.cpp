#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> heights(n);

    for(int i = 0; i < n; i++) {
        cin >> heights[i];
    }

    int energy = 0;
    int minMoney = 0;

    for(int i = 0; i < n; i++) {
        int neededEnergy = heights[i] - heights[i+1];
        if(energy + neededEnergy < 0) {
            minMoney += abs(neededEnergy);
            energy = 0;
        } else {
            energy += neededEnergy;
        }
    }

    cout << minMoney << endl;

    return 0;
}