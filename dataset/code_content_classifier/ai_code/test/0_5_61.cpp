#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        unordered_map<int, int> topics, difficulties;
        vector<pair<int, int>> problems(n);
        
        for(int i = 0; i < n; i++) {
            int topic, difficulty;
            cin >> topic >> difficulty;
            topics[topic]++;
            difficulties[difficulty]++;
            problems[i] = {topic, difficulty};
        }
        
        long long count = 0;
        
        for(auto& p : problems) {
            count += (n - topics[p.first]) * (n - difficulties[p.second]);
        }
        
        cout << count << endl;
    }
    
    return 0;
}