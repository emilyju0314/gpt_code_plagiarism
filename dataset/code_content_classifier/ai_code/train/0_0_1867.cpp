#include <iostream>
#include <vector>

using namespace std;

int query(int x1, int y1, int x2, int y2) {
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    cout.flush();
    
    int result;
    cin >> result;
    
    return result;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> rect1_x, rect1_y, rect2_x, rect2_y;
    
    // Find the first rectangle
    for (int i = 1; i < n; ++i) {
        if (query(1, 1, n, i) == 1) {
            rect1_x.push_back(1);
            rect1_y.push_back(i);
        }
    }
    
    for (int i = 1; i < n; ++i) {
        if (query(1, 1, i, n) == 1) {
            rect1_x.push_back(i);
            rect1_y.push_back(n);
        }
    }
    
    // Find the second rectangle
    for (int i = 1; i < n; ++i) {
        if (query(1, 1, n, i) == 2) {
            rect2_x.push_back(1);
            rect2_y.push_back(i);
        }
    }
    
    for (int i = 1; i < n; ++i) {
        if (query(1, 1, i, n) == 2) {
            rect2_x.push_back(i);
            rect2_y.push_back(n);
        }
    }
    
    // Output the result
    cout << "! " << rect1_x[0] << " " << rect1_y[0] << " " << rect1_x[1] << " " << rect1_y[1] << " " 
                  << rect2_x[0] << " " << rect2_y[0] << " " << rect2_x[1] << " " << rect2_y[1] << endl;
    cout.flush();
    
    return 0;
}