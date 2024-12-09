#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    
    vector<int> hotels(n);
    for(int i = 0; i < n; i++) {
        cin >> hotels[i];
    }
    
    int count = 2; // Initialize count with 2 to consider the cities on the left and right of the first and last hotel
    
    for(int i = 1; i < n; i++) {
        int distance = hotels[i] - hotels[i-1];
        if(distance >= 2*d) {
            count += 2; // Count the cities on the left and right of the current pair of hotels
            if(distance > 2*d) {
                count += (distance - 2*d) / d; // Count the cities between the current pair of hotels
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}