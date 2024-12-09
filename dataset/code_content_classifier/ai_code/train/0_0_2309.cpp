#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    int n, k, m, a;
    cin >> n >> k >> m >> a;
    
    vector<int> candidates(n, 0);
    for (int i = 0; i < a; i++) {
        int vote;
        cin >> vote;
        candidates[vote-1]++;
    }
    
    vector<int> remaining_votes(m-a, 0);
    for (int i = 0; i < m-a; i++) {
        int vote;
        cin >> vote;
        remaining_votes[vote-1]++;
    }
    
    vector<int> result(n, 0);
    for (int i = 0; i < n; i++) {
        if (candidates[i] + remaining_votes[i] > (m/k)) {
            result[i] = 1;
        } else if (candidates[i] < (m/k)) {
            result[i] = 3;
        } else {
            result[i] = 2;
        }
    }
    
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    
    return 0;
}