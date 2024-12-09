#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Problem {
    int resources;
    int scientist;
};

bool compare(Problem p1, Problem p2) {
    return p1.resources < p2.resources;
}

int main() {
    int n;
    cin >> n;
    
    vector<vector<Problem>> problems(n);
    
    for (int i = 0; i < n; i++) {
        int k, a, x, y, m;
        cin >> k >> a >> x >> y >> m;
        
        for (int j = 1; j <= k; j++) {
            problems[i].push_back({a, i+1});
            a = (1LL * a * x + y) % m;
        }
    }
    
    int bad_pairs = 0;
    vector<Problem> order;
    
    for (int i = 0; i < n; i++) {
        sort(problems[i].begin(), problems[i].end(), compare);
        
        for (int j = 0; j < problems[i].size(); j++) {
            if (j > 0 && problems[i][j].resources < problems[i][j-1].resources) {
                bad_pairs++;
            }
            order.push_back(problems[i][j]);
        }
    }
    
    cout << bad_pairs << endl;
    
    for (int i = 0; i < order.size(); i++) {
        cout << order[i].resources << " " << order[i].scientist << endl;
    }
    
    return 0;
}