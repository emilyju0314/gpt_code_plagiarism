#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Bar {
    int red_length;
    int blue_length;
    int red_hanging;
    int blue_hanging;
};

int getWeight(const vector<Bar>& bars, int bar_index) {
    if (bars[bar_index].red_hanging == 0 && bars[bar_index].blue_hanging == 0) {
        return 1; // Weight has to have a positive integer weight
    }
    
    int red_weight = 0;
    int blue_weight = 0;
    
    if (bars[bar_index].red_hanging != 0) {
        red_weight = getWeight(bars, bars[bar_index].red_hanging - 1);
    }
    
    if (bars[bar_index].blue_hanging != 0) {
        blue_weight = getWeight(bars, bars[bar_index].blue_hanging - 1);
    }
    
    int total_weight = red_weight * bars[bar_index].red_length;
    int required_blue_weight = total_weight / bars[bar_index].blue_length;
    
    return max(blue_weight, required_blue_weight);
}

int main() {
    int n;
    
    while (true) {
        cin >> n;
        if (n == 0) {
            break;
        }
        
        vector<Bar> bars(n);
        
        for (int i = 0; i < n; i++) {
            cin >> bars[i].red_length >> bars[i].blue_length >> bars[i].red_hanging >> bars[i].blue_hanging;
        }
        
        int weight = getWeight(bars, 0);
        cout << weight << endl;
    }
    
    return 0;
}