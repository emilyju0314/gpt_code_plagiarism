#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> ratings(n);
    
    for (int i = 0; i < n; i++) {
        cin >> ratings[i];
    }
    
    int target = *max_element(ratings.begin(), ratings.end());
    
    vector<vector<int>> matches;
    
    while (*max_element(ratings.begin(), ratings.end()) != target) {
        vector<int> match;
        
        for (int i = 0; i < n; i++) {
            if (ratings[i] == target) {
                match.push_back(i);
                ratings[i]--;
            } else if (match.size() < 5) {
                match.push_back(i);
                ratings[i]--;
            }
            
            if (match.size() == 5) {
                break;
            }
        }
        
        matches.push_back(match);
    }
    
    cout << target << endl;
    cout << matches.size() << endl;
    
    for (auto match : matches) {
        for (int i = 0; i < n; i++) {
            if (find(match.begin(), match.end(), i) != match.end()) {
                cout << "1";
            } else {
                cout << "0";
            }
        }
        cout << endl;
    }
    
    return 0;
}