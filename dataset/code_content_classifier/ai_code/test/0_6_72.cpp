#include <iostream>

using namespace std;

int main() {
    int queries = 0; // Keep track of number of queries made
    
    // Find the enemy base by iteratively querying different squares
    // Start by checking the center of the grid
    cout << "? 500000000 500000000" << endl;
    cout.flush();
    
    int dist_center;
    cin >> dist_center;
    queries++;
    
    int lo = 1, hi = 1000000000;
    
    // Binary search to find the minimum x coordinate of the enemy base
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        cout << "? " << mid << " 500000000" << endl;
        cout.flush();
        
        int dist;
        cin >> dist;
        queries++;
        
        if (dist_center < dist) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    
    int x_min = lo;
    
    // Binary search to find the minimum y coordinate of the enemy base
    lo = 1;
    hi = 1000000000;
    
    while (lo < hi) {
        int mid = (lo + hi) / 2;
        cout << "? " << x_min << " " << mid << endl;
        cout.flush();
        
        int dist;
        cin >> dist;
        queries++;
        
        if (dist_center < dist) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    
    int y_min = lo;
    
    // Binary search to find the maximum x coordinate of the enemy base
    lo = x_min;
    hi = 1000000000;
    
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        cout << "? " << mid << " " << y_min << endl;
        cout.flush();
        
        int dist;
        cin >> dist;
        queries++;
        
        if (dist_center < dist) {
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }
    
    int x_max = lo;
    
    // Binary search to find the maximum y coordinate of the enemy base
    lo = y_min;
    hi = 1000000000;
    
    while (lo < hi) {
        int mid = (lo + hi + 1) / 2;
        cout << "? " << x_max << " " << mid << endl;
        cout.flush();
        
        int dist;
        cin >> dist;
        queries++;
        
        if (dist_center < dist) {
            hi = mid - 1;
        } else {
            lo = mid;
        }
    }
    
    int y_max = lo;
    
    // Output the coordinates of the enemy base
    cout << "! " << x_min << " " << y_min << " " << x_max << " " << y_max << endl;
    cout.flush();
    
    return 0;
}