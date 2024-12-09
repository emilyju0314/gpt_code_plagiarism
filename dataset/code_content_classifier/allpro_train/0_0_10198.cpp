#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    for (int X = 1; X <= 50000; X++) {
        if (X * 1.08 == N) {
            cout << X << endl;
            return 0;
        }
    }
    
    cout << ":(" << endl;
    return 0;
}