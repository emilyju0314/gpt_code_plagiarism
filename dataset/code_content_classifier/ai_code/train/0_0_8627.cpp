#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<vector<int>> prob(2*N, vector<int>(2*N));
    for (int i = 0; i < 2*N; i++) {
        for (int j = 0; j < 2*N; j++) {
            cin >> prob[i][j];
        }
    }

    vector<vector<double>> dp(N+1, vector<double>(1 << N, 0.0));
    
    // TODO: Continue with the implementation
}