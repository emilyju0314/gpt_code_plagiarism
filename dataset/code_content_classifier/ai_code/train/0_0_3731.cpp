#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    map<int, vector<int>> candidates;
    
    for(int i = 0; i < n; i++) {
        int s, r;
        cin >> s >> r;
        candidates[s].push_back(r);
    }
    
    int minSkill = INT_MAX;
    long long totalSum = 0;
    
    for(auto it = candidates.begin(); it != candidates.end(); it++) {
        minSkill = min(minSkill, (int)it->second.size());
        long long sum = 0;
        for(int r : it->second) {
            sum += r;
        }
        totalSum += sum;
    }
    
    if(minSkill == 0) {
        cout << 0 << endl;
    } else {
        cout << totalSum / minSkill * m << endl;
    }
    
    return 0;
}