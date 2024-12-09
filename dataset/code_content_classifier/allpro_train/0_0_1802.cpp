#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int count = 0;
    
    while (A%2 == 0 && B%2 == 0 && C%2 == 0) {
        int newA = B/2 + C/2;
        int newB = A/2 + C/2;
        int newC = A/2 + B/2;
        A = newA;
        B = newB;
        C = newC;
        count++;
        
        // Check for infinity
        if (A == B && B == C) {
            cout << -1 << endl;
            return 0;
        }
    }

    cout << count << endl;

    return 0;
}