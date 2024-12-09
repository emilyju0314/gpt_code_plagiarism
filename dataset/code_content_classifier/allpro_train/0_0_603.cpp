#include <iostream>
#include <algorithm>

using namespace std;

int numGroups(int A, int B, int C) {
    int count = 0;
    for (int a = 1; a <= A; a++) {
        for (int b = a; b <= B; b++) {
            int c_min = max(b, (int)ceil((double)(A * B * C) / (a * b)));
            int c_max = min(C, (int)sqrt((double)(A * B * C) / (a * b)));
            count += max(0, c_max - c_min + 1);
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int A, B, C;
        cin >> A >> B >> C;
        
        cout << numGroups(A, B, C) << endl;
    }
    
    return 0;
}