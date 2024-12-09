#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<pair<int, int>> weights; // pairs of weight and index
    for(int i = 0; i < N; i++) {
        int weight;
        cin >> weight;
        weights.push_back({weight, i});
    }
    
    string S;
    cin >> S;
    
    sort(weights.begin(), weights.end()); // sort the weights
    
    int leftSum = 0, rightSum = 0;
    
    for(int i = 0; i < N; i++) {
        int weight = weights[i].first;
        int idx = weights[i].second;
        
        if(S[idx] == 'L') {
            cout << weight << " L" << endl;
            leftSum += weight;
        } else {
            cout << weight << " R" << endl;
            rightSum += weight;
        }
    }
    
    if(leftSum != rightSum) {
        cout << -1 << endl;
    }
    
    return 0;
}