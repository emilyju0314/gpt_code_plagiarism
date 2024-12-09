#include <iostream>
using namespace std;

int main() {
    // Initialize arrays to store the first 500 tetrahedral and odd tetrahedral numbers
    long long tet[501];
    long long odd_tet[501];

    tet[1] = 1;
    for(int i = 2; i <= 500; i++) {
        tet[i] = i*(i+1)*(i+2) / 6;
    }

    odd_tet[1] = 1;
    for(int i = 2; i <= 500; i++) {
        odd_tet[i] = i * (i+1) / 2 * (2*i+1);
    }

    int n;
    while(cin >> n && n != 0) {
        int tet_count = 1;
        int odd_tet_count = 1;

        // Find the least number of tetrahedral numbers to represent the input integer
        while(tet[tet_count] < n) {
            tet_count++;
        }

        // Find the least number of odd tetrahedral numbers to represent the input integer
        while(odd_tet[odd_tet_count] < n) {
            odd_tet_count++;
        }

        cout << tet_count << " " << odd_tet_count << endl;
    }

    return 0;
}