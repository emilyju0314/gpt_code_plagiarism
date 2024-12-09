#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<int> itinerary(M);
    for(int i = 0; i < M; i++) {
        cin >> itinerary[i];
    }
    
    vector<vector<int>> fares(N-1, vector<int>(3));
    for(int i = 0; i < N-1; i++) {
        cin >> fares[i][0] >> fares[i][1] >> fares[i][2];
    }
    
    vector<int> min_cost(N-1, 0);
    long long total_cost = 0;
    
    for(int i = 0; i < M-1; i++) {
        int start = min(itinerary[i], itinerary[i+1]);
        int end = max(itinerary[i], itinerary[i+1]);
        
        int paper_ticket_cost = 0;
        int ic_card_cost = 0;
        
        for(int j = start-1; j < end-1; j++) {
            paper_ticket_cost += fares[j][0];
            ic_card_cost += min(fares[j][0], fares[j][1]);
        }
        
        for(int j = start; j < end; j++) {
            min_cost[j-1] = min(min_cost[j-1], fares[j-1][2]);
        }
        
        total_cost += min(paper_ticket_cost, ic_card_cost);
    }
    
    for(int i = 0; i < N-1; i++) {
        total_cost += min_cost[i];
    }
    
    cout << total_cost << endl;
    
    return 0;
}