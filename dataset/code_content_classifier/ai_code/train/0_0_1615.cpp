#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int r, d, n;
    cin >> r >> d;
    
    cin >> n;
    
    int count = 0;
    for(int i = 0; i < n; i++) {
        int xi, yi, ri;
        cin >> xi >> yi >> ri;
        
        double dist = sqrt(xi*xi + yi*yi);
        double outer_radius = dist + ri;
        double inner_radius = dist - ri;
        
        if(outer_radius <= r && inner_radius >= r-d) {
            count++;
        }
    }
    
    cout << count << endl;
    
    return 0;
}