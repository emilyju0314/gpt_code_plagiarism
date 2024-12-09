#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    vector<pair<int, int>> cards;
    
    // Input
    cin >> n;
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        cards.push_back({a, b});
    }
    
    // Calculate minimum cost
    long long cost = 0;
    for(int i=0; i<n-1; i++) {
        long long min_cost = LLONG_MAX;
        int min_idx = -1;
        for(int j=0; j<cards.size()-1; j++) {
            long long temp_cost = (long long)cards[j].first * cards[j+1].first * cards[j+1].second;
            if(temp_cost < min_cost) {
                min_cost = temp_cost;
                min_idx = j;
            }
        }
        cost += min_cost;
        cards[min_idx].first = cards[min_idx].second;
        cards.erase(cards.begin() + min_idx + 1);
    }
    
    // Output
    cout << cost << endl;
    
    return 0;
}