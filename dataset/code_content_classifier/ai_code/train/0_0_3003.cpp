#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> X(N), Y(N);
    vector<char> U(N);
    
    map<pair<int, int>, int> positions; // Store position of each airplane
    
    for(int i = 0; i < N; i++) {
        cin >> X[i] >> Y[i] >> U[i];
        positions[{X[i], Y[i]}] = i; // Store position of airplane
    }
    
    for(int i = 0; i < N; i++) {
        if(U[i] == 'U') {
            for(int j = Y[i] + 1; j <= 200000; j++) {
                if(positions.count({X[i], j})) { // Check if there is a collision
                    int other = positions[{X[i], j}];
                    if(U[other] == 'D') {
                        cout << (j - Y[i]) * 10 << endl; // Print time of collision
                        return 0;
                    }
                }
            }
        }
        else if(U[i] == 'R') {
            for(int j = X[i] + 1; j <= 200000; j++) {
                if(positions.count({j, Y[i]})) { // Check if there is a collision
                    int other = positions[{j, Y[i]}];
                    if(U[other] == 'L') {
                        cout << (j - X[i]) * 10 << endl; // Print time of collision
                        return 0;
                    }
                }
            }
        }
    }
    
    cout << "SAFE\n"; // If no collision is found
    
    return 0;
}