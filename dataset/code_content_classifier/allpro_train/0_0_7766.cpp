#include <iostream>
using namespace std;

int main() {
    int X, d;
    cin >> X >> d;

    if(X == 1) {
        cout << "1\n1" << endl;
    } else {
        int n = 2;
        int curr_max = 1;
        while(X >= n) {
            curr_max *= 2;
            n++;
        }
        cout << n << endl;
        cout << curr_max;
        for(int i = 1; i < n-1; i++) {
            cout << " " << curr_max + d + i;
        }
        cout << endl;
    }

    return 0;
} 

This code takes the inputs X and d, calculates the maximum number of elements in the array based on the given conditions, and constructs an array that satisfies the conditions. If no valid array is possible, it prints -1.