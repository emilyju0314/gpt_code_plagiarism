#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> piles(N);
    for(int i = 0; i < N; i++) {
        cin >> piles[i];
    }
    
    vector<pair<int, int>> sorted_piles;
    for(int i = 0; i < N; i++) {
        sorted_piles.push_back({-piles[i], i+1});
    }
    
    sort(sorted_piles.begin(), sorted_piles.end());
    
    vector<int> occurrences(N, 0);
    
    for(auto pile: sorted_piles) {
        int index = pile.second;
        for(int i = 0; i < piles[index-1]; i++) {
            occurrences[index-1 + i]++;
        }
    }
    
    for(int i = 0; i < N; i++) {
        cout << occurrences[i] << endl;
    }
    
    return 0;
}