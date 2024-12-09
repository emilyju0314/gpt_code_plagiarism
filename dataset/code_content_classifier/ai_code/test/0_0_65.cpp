#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> weights; // Pair of weight and index
    for(int i = 0; i < N; i++) {
        int weight;
        cin >> weight;
        weights.push_back({weight, i});
    }
    
    string rules;
    cin >> rules;
    
    sort(weights.begin(), weights.end());
    
    int left_sum = 0, right_sum = 0;
    for(int i = 0; i < N; i++) {
        if(rules[i] == 'L') {
            cout << weights[i].first << " L" << endl;
            left_sum += weights[i].first;
        } else {
            cout << weights[i].first << " R" << endl;
            right_sum += weights[i].first;
        }
    }
    
    if(left_sum == right_sum) {
        return 0;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}