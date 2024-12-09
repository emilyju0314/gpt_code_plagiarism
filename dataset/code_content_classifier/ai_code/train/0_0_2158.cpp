#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int w, d;
    
    while (cin >> w >> d) {
        if (w == 0 && d == 0) {
            break;
        }
        
        vector<int> front(w);
        vector<int> side(d);
        
        for (int i = 0; i < w; i++) {
            cin >> front[i];
        }
        
        for (int i = 0; i < d; i++) {
            cin >> side[i];
        }
        
        vector<int> heights(w * d, 0);
        
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < front[i]; j++) {
                heights[j * w + i] = 1;
            }
        }
        
        for (int i = 0; i < d; i++) {
            for (int j = 0; j < side[i]; j++) {
                heights[i * w + j] = max(heights[i * w + j], 1);
            }
        }
        
        int cubes = 0;
        
        for (int i = 0; i < w * d; i++) {
            if (heights[i] == 0) {
                cubes++;
            }
        }
        
        cout << cubes << endl;
    }
    
    return 0;
}