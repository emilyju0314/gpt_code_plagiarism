#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int findMaxSteps(int n, vector<int>& planks) {
    sort(planks.begin(), planks.end(), greater<int>());
    
    int maxSteps = 0;
    for(int i = 0; i < n-2; i++) {
        if(planks[i] >= i+1 && planks[i+1] >= i+1) {
            maxSteps = i+1;
        }
    }
    
    return maxSteps;
}

int main() {
    int T;
    cin >> T;
    
    while(T--) {
        int n;
        cin >> n;
        
        vector<int> planks(n);
        for(int i = 0; i < n; i++) {
            cin >> planks[i];
        }
        
        int maxSteps = findMaxSteps(n, planks);
        cout << maxSteps << endl;
    }
    
    return 0;
}