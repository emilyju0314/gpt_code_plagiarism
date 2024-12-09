#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> compartments(n);
    for(int i = 0; i < n; i++) {
        cin >> compartments[i];
    }
    
    int total_swaps = 0;

    for(int i = 0; i < n; i++) {
        if(compartments[i] == 1) {
            if(i < n-1 && compartments[i+1] == 1) {
                compartments[i]++;
                compartments[i+1]++;
                total_swaps += 2;
            } else if(i < n-1 && compartments[i+1] == 2) {
                compartments[i]++;
                compartments[i+1]--;
                total_swaps++;
            } else if(i > 0 && compartments[i-1] == 2) {
                compartments[i]++;
                compartments[i-1]--;
                total_swaps++;
            }
        } else if(compartments[i] == 2) {
            if(i < n-1 && compartments[i+1] == 2) {
                compartments[i] += 2;
                compartments[i+1] -= 2;
                total_swaps += 2;
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        if(compartments[i] == 3) {
            total_swaps++;
        } else if(compartments[i] == 4) {
            // Do nothing
        } else {
            cout << "-1" << endl;
            return 0;
        }
    }
    
    cout << total_swaps << endl;
    
    return 0;
}