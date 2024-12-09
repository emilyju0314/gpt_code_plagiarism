#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int n;
        cin >> n;

        vector<int> sociability(n);
        vector<pair<int, int>> pairs;

        for(int i = 0; i < n; i++) {
            cin >> sociability[i];
        }

        int max_talks = 0;

        for(int i = 0; i < n; i++) {
            if(sociability[i] == 0) continue;
            
            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                
                pairs.push_back({i+1, j+1});
                max_talks++;

                sociability[i]--;
                sociability[j]--;

                if(sociability[i] == 0) break;
            }
        }

        cout << max_talks << endl;
        for(auto p : pairs) {
            cout << p.first << " " << p.second << endl;
        }
    }

    return 0;
}