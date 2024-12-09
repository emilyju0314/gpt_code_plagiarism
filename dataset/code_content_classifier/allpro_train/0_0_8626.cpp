#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    vector<int> candies(n);
    for (int i = 0; i < n; i++) {
        cin >> candies[i];
    }
    
    int totalCandies = 0;
    int daysNeeded = 0;
    for (int i = 0; i < n; i++) {
        totalCandies += candies[i];
        daysNeeded++;
        if (totalCandies >= k) {
            break;
        }
        totalCandies = min(totalCandies, 8);
    }
    
    if (totalCandies >= k) {
        cout << daysNeeded << endl;
    } else {
        cout << -1 << endl;
    }
    
    return 0;
}