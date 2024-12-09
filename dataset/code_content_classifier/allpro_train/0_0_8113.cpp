#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n;
    
    vector<pair<int, int>> chemForces(n);
    for(int i = 0; i < n; i++) {
        cin >> chemForces[i].first >> chemForces[i].second;
    }
    
    cin >> m;
    
    vector<pair<int, int>> topChemist(m);
    for(int i = 0; i < m; i++) {
        cin >> topChemist[i].first >> topChemist[i].second;
    }
    
    sort(chemForces.begin(), chemForces.end());
    sort(topChemist.begin(), topChemist.end());
    
    long long totalIncome = 0;
    
    for(int i = 0; i < n; i++) {
        totalIncome += chemForces[i].second;
    }
    
    for(int i = 0; i < m; i++) {
        totalIncome += topChemist[i].second;
    }
    
    if(n > 0 && m > 0) {
        totalIncome = max(totalIncome - chemForces[0].second, totalIncome - topChemist[0].second);
    }
    
    cout << totalIncome << endl;
    
    return 0;
}