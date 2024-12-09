#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int AN, BN;
    double R;
    
    while (cin >> AN >> BN >> R) {
        if (AN == 0 && BN == 0) {
            break;
        }
        
        vector<pair<int, int>> combatPlanes(AN);
        vector<pair<int, int>> energyBullets(BN);
        
        for (int i = 0; i < AN; i++) {
            cin >> combatPlanes[i].first >> combatPlanes[i].second;
        }
        
        for (int i = 0; i < BN; i++) {
            cin >> energyBullets[i].first >> energyBullets[i].second;
        }
        
        int totalFightingPower = 0;
        
        for (int i = 0; i < AN; i++) {
            for (int j = 0; j < BN; j++) {
                double distance = sqrt(pow(combatPlanes[i].first - energyBullets[j].first, 2) + pow(combatPlanes[i].second - energyBullets[j].second, 2));
                if (distance <= 2*R) {
                    totalFightingPower++;
                }
            }
        }
        
        cout << totalFightingPower << endl;
    }
    
    return 0;
}