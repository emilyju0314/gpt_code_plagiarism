#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Arrow {
    int start;
    int end;
    int score;
};

int main() {
    int V, E, K;
    cin >> V >> E >> K;

    vector<Arrow> arrows(E);
    for(int i = 0; i < E; i++) {
        cin >> arrows[i].start >> arrows[i].end >> arrows[i].score;
    }

    int min_arrows = INT_MAX;
    vector<int> optimal_path;

    for(int i = 0; i < E; i++) {
        vector<int> path;
        int current_score = 0;
        int arrows_taken = 0;
        int current_cone = arrows[i].start;
        path.push_back(current_cone);
        
        while(arrows_taken <= 100) {
            bool found = false;
            for(int j = 0; j < E; j++) {
                if(arrows[j].start == current_cone && current_score + arrows[j].score >= K) {
                    current_cone = arrows[j].end;
                    current_score += arrows[j].score;
                    arrows_taken++;
                    path.push_back(current_cone);
                    found = true;
                    break;
                }
            }
            if(!found) break;
        }

        if(current_score >= K && arrows_taken < min_arrows) {
            min_arrows = arrows_taken;
            optimal_path = path;
        }
    }

    if(min_arrows == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << min_arrows << endl;
        for(int i = 0; i < optimal_path.size(); i++) {
            cout << optimal_path[i] << " ";
        }
        cout << endl;
    }

    return 0;
}