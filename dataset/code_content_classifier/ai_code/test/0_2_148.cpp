#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        int w, h;
        cin >> w >> h;

        int x1, x2, x3, y1, y2, y3;
        
        // Reading the x coordinates on horizontal sides
        int k;
        cin >> k;
        vector<int> x_horizontal(k);
        for(int i=0; i<k; i++) {
            cin >> x_horizontal[i];
        }
        
        // Reading the y coordinates on vertical sides
        cin >> k;
        vector<int> y_vertical(k);
        for(int i=0; i<k; i++) {
            cin >> y_vertical[i];
        }

        // Choosing the points to form the triangle
        x1 = x_horizontal[0];
        x2 = w - x_horizontal[1];
        x3 = w - x_horizontal[0];
        y1 = y_vertical[0];
        y2 = h - y_vertical[1];
        y3 = h - y_vertical[0];

        // Calculating the doubled area of the triangle
        cout << max(x1*y2, max(x2*y3, x3*y1)) * 2 << endl;
    }

    return 0;
}