#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<vector<long long>> roads(N, vector<long long>(N, 0));
    
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            roads[i][j] = roads[j][i] = (i + j) * (long long)(i != j);
        }
    }
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << roads[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}