#include <iostream>
using namespace std;

int query(int x, int y) {
    cout << "? " << x << " " << y << endl;
    cout.flush();
    
    int dist;
    cin >> dist;
    
    return dist;
}

int main() {
    int n = 1000000000;
    int x1, y1, x2, y2;
    
    // Find the smallest x coordinate
    int left = 1, right = n;
    while(left < right) {
        int mid = (left + right) / 2;
        int dist = query(mid, 1);
        
        if(dist == 0)
            right = mid;
        else
            left = mid + 1;
    }
    
    x1 = left;
    
    // Find the smallest y coordinate
    left = 1, right = n;
    while(left < right) {
        int mid = (left + right) / 2;
        int dist = query(1, mid);
        
        if(dist == 0)
            right = mid;
        else
            left = mid + 1;
    }
    
    y1 = left;
    
    // Find the largest x coordinate
    left = 1, right = n;
    while(left < right) {
        int mid = (left + right + 1) / 2;
        int dist = query(mid, n);
        
        if(dist == 0)
            left = mid;
        else
            right = mid - 1;
    }
    
    x2 = left;
    
    // Find the largest y coordinate
    left = 1, right = n;
    while(left < right) {
        int mid = (left + right + 1) / 2;
        int dist = query(n, mid);
        
        if(dist == 0)
            left = mid;
        else
            right = mid - 1;
    }
    
    y2 = left;
    
    // Output the result
    cout << "! " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    cout.flush();
    
    return 0;
}