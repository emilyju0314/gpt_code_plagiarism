#include <iostream>
#include <vector>

using namespace std;

// Function to calculate the number of swaps needed to sort the balls
int calculateSwaps(vector<pair<int, int>>& balls) {
    int swaps = 0;
    
    for (int i = 0; i < balls.size(); i++) {
        for (int j = balls.size()-1; j > i; j--) {
            if (balls[j].first == i+1 && balls[j].second == i+1) {
                swap(balls[j], balls[j-1]);
                swaps++;
            }
        }
    }
    
    return swaps;
}

int main() {
    int n;
    
    while (cin >> n && n != 0) {
        vector<pair<int, int>> balls(n);
        
        for (int i = 0; i < n; i++) {
            cin >> balls[i].first >> balls[i].second;
        }
        
        int swaps = calculateSwaps(balls);
        cout << swaps << endl;
    }
    
    return 0;
}