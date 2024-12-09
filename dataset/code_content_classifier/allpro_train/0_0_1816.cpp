#include <iostream>
using namespace std;

int main() {
    int rows, columns;
    cin >> rows >> columns;

    int maxOverlap = 0;
    for(int i=0; i<rows; i++) {
        for(int j=0; j<columns; j++) {
            int num;
            cin >> num;
            maxOverlap = max(maxOverlap, num);
        }
    }

    cout << maxOverlap;

    return 0;
}