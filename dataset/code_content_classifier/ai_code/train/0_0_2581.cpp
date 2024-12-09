#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define MOD 998244353

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int,int>> points(N);
    for(int i=0; i<N; i++) {
        cin >> points[i].first >> points[i].second;
    }
    
    long long answer = 0;
    
    for(int mask=1; mask<(1<<N); mask++) {
        vector<pair<int,int>> currentPoints;
        for(int i=0; i<N; i++) {
            if(mask & (1<<i)) {
                currentPoints.push_back(points[i]);
            }
        }
        
        int n = currentPoints.size();
        
        bool valid = true;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    pair<int,int> p1 = currentPoints[i];
                    pair<int,int> p2 = currentPoints[j];
                    pair<int,int> p3 = currentPoints[k];
                    int crossProduct = (p2.first - p1.first) * (p3.second - p1.second) - (p2.second - p1.second) * (p3.first - p1.first);
                    if(crossProduct == 0) {
                        valid = false;
                    }
                }
            }
        }
        
        if(valid) {
            long long score = pow(2, n) % MOD;
            if(__builtin_popcount(mask) % 2 == 1) {
                answer = (answer + score) % MOD;
            } else {
                answer = (answer - score + MOD) % MOD;
            }
        }
    }
    
    cout << answer << endl;
    
    return 0;
}