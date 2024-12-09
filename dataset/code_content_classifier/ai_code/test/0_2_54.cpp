#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n, m;
        cin >> n >> m;
        
        vector<int> valid(n+1, -1);
        
        unordered_map<int, int> imposterCount, crewmateCount;
        
        bool contradiction = false;
        
        while(m--) {
            int i, j;
            string c;
            cin >> i >> j >> c;
            
            if(valid[i] == -1 && valid[j] == -1) {
                if(c == "imposter") {
                    valid[i] = 1;
                    imposterCount[i]++;
                    valid[j] = 0;
                    crewmateCount[j]++;
                } else {
                    valid[i] = 0;
                    crewmateCount[i]++;
                    valid[j] = 1;
                    imposterCount[j]++;
                }
            } else if(valid[i] == -1) {
                if(c == "imposter") {
                    valid[i] = 1;
                    imposterCount[i]++;
                } else {
                    valid[i] = 0;
                    crewmateCount[i]++;
                }
            } else if(valid[j] == -1) {
                if(c == "imposter") {
                    valid[j] = 1;
                    imposterCount[j]++;
                } else {
                    valid[j] = 0;
                    crewmateCount[j]++;
                }
            } else {
                contradiction = true;
            }
        }
        
        if(contradiction) {
            cout << -1 << endl;
        } else {
            int maxImposters = 0;
            for(int i = 1; i <= n; i++) {
                if(imposterCount[i] > crewmateCount[i]) {
                    maxImposters++;
                }
            }
            cout << maxImposters << endl;
        }
    }
    
    return 0;
}