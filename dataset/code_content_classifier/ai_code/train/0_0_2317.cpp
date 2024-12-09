#include <iostream>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    // Fill in the grid with all 1's to maximize oddness
    for (int i = 0; i < (1 << N) - 1; i++) {
        for (int j = 0; j < (1 << M) - 1; j++) {
            cout << "1";
        }
        cout << endl;
    }
    
    return 0;
}