#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N; // taking input for N

    int h, n, w;
    
    for (h = 1; h <= 3500; h++) {
        for (n = 1; n <= 3500; n++) {
            for (w = 1; w <= 3500; w++) {
                if (4*N == h*n*w && (1.0/h + 1.0/n + 1.0/w == 4.0/N)) {
                    cout << h << " " << n << " " << w << endl;
                    return 0; // printing the solution and exiting the loop
                }
            }
        }
    }

    return 0;
}