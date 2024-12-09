#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        vector<pair<int, int>> swimmers; // pair of natural pace and planned laps for each swimmer
        
        for (int i = 0; i < n; i++) {
            int t, c;
            cin >> t >> c;
            swimmers.push_back(make_pair(t, c));
        }
        
        sort(swimmers.begin(), swimmers.end()); // sort swimmers by their natural pace
        
        int totalTime = 0;
        for (int i = 0; i < n; i++) {
            totalTime = max(totalTime, i * swimmers[i].first * swimmers[i].second); // calculate total time for all swimmers
        }
        
        cout << totalTime << endl; // output the total time required for all swimmers to finish their plans
    }
    
    return 0;
}