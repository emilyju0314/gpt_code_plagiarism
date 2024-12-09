#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N, D;
    cin >> N >> D;
    
    vector<vector<int>> hotels(N, vector<int>(D));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < D; j++) {
            cin >> hotels[i][j];
        }
    }
    
    vector<int> min_costs(D, 0);
    vector<int> min_trips(D, 0);
    
    for(int j = 0; j < D; j++) {
        min_costs[j] = hotels[0][j];
    }
    
    for(int i = 1; i < N; i++) {
        vector<int> cur_costs(D, 0);
        vector<int> cur_trips(D, 0);
        
        for(int j = 0; j < D; j++) {
            cur_costs[j] = min_costs[j] + hotels[i][j];
            
            if(j > 0 && cur_costs[j-1] < cur_costs[j]) {
                cur_costs[j] = cur_costs[j-1];
                cur_trips[j] = cur_trips[j-1] + 1;
            } else {
                cur_trips[j] = min_trips[j];
            }
        }
        
        min_costs = cur_costs;
        min_trips = cur_trips;
    }
    
    int min_cost = min_costs[D-1];
    int min_trip = min_trips[D-1];
    
    cout << min_cost << " " << min_trip << endl;
    
    // Backtrack to get the hotels to stay
    vector<int> optimal_hotels(D);
    int prev_hotel = min_distance[D-1];
    optimal_hotels[D-1] = prev_hotel;
    
    for(int j = D-2; j >= 0; j--) {
        if(hotels[prev_hotel][j] + min_costs[j] == min_costs[j+1]) {
            optimal_hotels[j] = prev_hotel;
        } else {
            for(int i = 0; i < N; i++) {
                if(hotels[i][j] + min_costs[j] == min_costs[j+1] && min_trips[j] < min_trip) {
                    optimal_hotels[j] = i;
                    prev_hotel = i;
                    break;
                }
            }
        }
    }
    
    for(int i = 0; i < D; i++) {
        cout << optimal_hotels[i] + 1 << endl;
    }
    
    return 0;
}