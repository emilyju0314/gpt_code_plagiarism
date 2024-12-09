#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n, m, k, r, c;
    cin >> n >> m >> k >> r >> c;

    int ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;

    vector<vector<int>> matrix(n, vector<int>(m));

    // Calculate the number of possible color combinations for each subrectangle pattern
    long long patterns = 1;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            patterns = (patterns * k) % MOD;
        }
    }

    // Output the answer modulo 10^9 + 7
    cout << patterns << endl;

    return 0;
}