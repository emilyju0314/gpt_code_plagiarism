#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> V(N);
    for(int i = 0; i < N; i++) {
        cin >> V[i];
    }
    
    sort(V.begin(), V.end(), greater<int>());
    
    long long total_joy = 0;
    for(int i = 0; i < N; i++) {
        total_joy += V[i] - i - 1;
    }
    
    cout << total_joy << endl;
    
    return 0;
}