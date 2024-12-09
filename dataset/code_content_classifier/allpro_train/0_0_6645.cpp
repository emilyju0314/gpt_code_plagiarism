#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> X(M);
    for (int i = 0; i < M; i++) {
        cin >> X[i];
    }
    
    sort(X.begin(), X.end());
    
    vector<int> dists;
    for (int i = 0; i < M-1; i++) {
        dists.push_back(abs(X[i] - X[i+1]));
    }
    
    sort(dists.begin(), dists.end(), greater<int>());
    
    int total_moves = 0;
    for (int i = N-1; i < dists.size(); i++) {
        total_moves += dists[i];
    }
    
    cout << total_moves << endl;
    
    return 0;
}