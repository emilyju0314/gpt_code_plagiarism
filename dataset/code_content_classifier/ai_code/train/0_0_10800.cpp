#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    
    vector<pair<int, int>> flags(N);
    for(int i = 0; i < N; i++) {
        cin >> flags[i].first >> flags[i].second;
    }
    
    sort(flags.begin(), flags.end());
    
    if(flags[N-1].first - flags[0].first < D) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
        for(int i = 0; i < N; i++) {
            cout << flags[i].first << endl;
        }
    }
    
    return 0;
}