#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int NA, NB, W;
    cin >> NA >> NB >> W;
    
    vector<pair<int, int>> maleCats;
    vector<pair<int, int>> femaleCats;
    
    for(int i=0; i<NA; i++) {
        int mA, cA;
        cin >> mA >> cA;
        maleCats.push_back(make_pair(mA, cA));
    }
    
    for(int i=0; i<NB; i++) {
        int mB, cB;
        cin >> mB >> cB;
        femaleCats.push_back(make_pair(mB, cB));
    }
    
    sort(maleCats.begin(), maleCats.end());
    sort(femaleCats.begin(), femaleCats.end());
    
    int minUnCute = 1e9;
    
    for(int i=1; i<=maleCats.size(); i++) {
        for(int j=1; j<=femaleCats.size(); j++) {
            if(maleCats[i-1].first + femaleCats[j-1].first <= W) {
                int maleCuteMax = 0;
                int maleCuteMin = 1e9;
                
                for(int k=0; k<i; k++) {
                    maleCuteMax = max(maleCuteMax, maleCats[k].second);
                    maleCuteMin = min(maleCuteMin, maleCats[k].second);
                }
                
                int femaleCuteMax = 0;
                int femaleCuteMin = 1e9;
                
                for(int k=0; k<j; k++) {
                    femaleCuteMax = max(femaleCuteMax, femaleCats[k].second);
                    femaleCuteMin = min(femaleCuteMin, femaleCats[k].second);
                }
                
                minUnCute = min(minUnCute, max(maleCuteMax - maleCuteMin, femaleCuteMax - femaleCuteMin));
            }
        }
    }
    
    cout << minUnCute << endl;
    
    return 0;
}