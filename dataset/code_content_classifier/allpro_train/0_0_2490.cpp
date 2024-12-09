#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> font_sizes(n);
    vector<int> rent_costs(n);
    
    for(int i = 0; i < n; i++) {
        cin >> font_sizes[i];
    }
    
    for(int i = 0; i < n; i++) {
        cin >> rent_costs[i];
    }
    
    int min_cost = -1;
    
    for(int j = 1; j < n-1; j++) {
        int min_cost_j = -1;
        
        for(int i = 0; i < j; i++) {
            if(font_sizes[i] < font_sizes[j]) {
                if(min_cost_j == -1 || rent_costs[i] < rent_costs[min_cost_j]) {
                    min_cost_j = i;
                }
            }
        }
        
        int min_cost_k = -1;
        
        for(int k = j+1; k < n; k++) {
            if(font_sizes[j] < font_sizes[k]) {
                if(min_cost_k == -1 || rent_costs[k] < rent_costs[min_cost_k]) {
                    min_cost_k = k;
                }
            }
        }
        
        if(min_cost_j != -1 && min_cost_k != -1) {
            int total_cost = rent_costs[min_cost_j] + rent_costs[j] + rent_costs[min_cost_k];
            if(min_cost == -1 || total_cost < min_cost) {
                min_cost = total_cost;
            }
        }
    }
    
    cout << min_cost << endl;

    return 0;
}