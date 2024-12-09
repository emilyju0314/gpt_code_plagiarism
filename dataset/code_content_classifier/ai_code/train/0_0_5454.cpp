#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

double physicalStrengthRequired(int T, int N, vector<pair<int, pair<int, int>>> &rings) {
    double ans = 0.0;
    
    for (int i = 0; i < N; i++) {
        int Xi = rings[i].first;
        int Li = rings[i].second.first;
        int Hi = rings[i].second.second;
        
        // Calculate the minimum time required to pass through the ring
        double time = sqrt(2 * (double) Hi);
        ans = max(ans, (double) (Xi - 0) + time);
    }
    
    return ans;
}

int main() {
    int T, N;
    cin >> T >> N;
    
    vector<pair<int, pair<int, int>>> rings(N);
    for (int i = 0; i < N; i++) {
        int Xi, Li, Hi;
        cin >> Xi >> Li >> Hi;
        rings[i] = {Xi, {Li, Hi}};
    }
    
    double result = physicalStrengthRequired(T, N, rings);
    
    cout << fixed << setprecision(10) << result << endl;
    
    return 0;
}