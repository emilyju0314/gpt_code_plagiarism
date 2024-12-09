#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int count = 0;
    for (int A = 1; A * A <= N; A++) {
        if (N % A == 0) {
            int B = N / A - 1;
            if (B >= 1 && N % B == 0) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}