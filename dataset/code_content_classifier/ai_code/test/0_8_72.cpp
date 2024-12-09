#include <iostream>
using namespace std;

int main() {
    int queries = 0;
    
    // Find the lower boundary of the rectangle
    int lowerX = -1, lowerY = -1;
    for (int i = 1; i <= 1000; i += 4) {
        for (int j = 1; j <= 1000; j += 4) {
            cout << "? " << i << " " << j << endl;
            cin >> queries;
            if (queries != -1) {
                lowerX = i;
                lowerY = j;
                break;
            }
        }
        if (lowerX != -1) break;
    }
    
    // Find the upper boundary of the rectangle
    int upperX = -1, upperY = -1;
    for (int i = 3; i <= 1000; i += 4) {
        for (int j = 3; j <= 1000; j += 4) {
            cout << "? " << i << " " << j << endl;
            cin >> queries;
            if (queries != -1) {
                upperX = i;
                upperY = j;
                break;
            }
        }
        if (upperX != -1) break;
    }
    
    // Print the results
    cout << "! " << lowerX << " " << lowerY << " " << upperX << " " << upperY << endl;
    
    return 0;
}