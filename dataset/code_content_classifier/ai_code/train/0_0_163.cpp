#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;
    
    int mA1, mA2, mB1, mB2, mX;
    cin >> mA1 >> mA2 >> mB1 >> mB2 >> mX;
    
    vector<vector<char>> matrix(H, vector<char>(W));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> matrix[i][j];
        }
    }
    
    double totalMass = 0.0;
    double massOnCell = 0.0;
    
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (matrix[i][j] == 'A') {
                totalMass += (mA1 + mA2) / 2.0;
                massOnCell += (mA1 + mA2) / 2.0;
            } else if (matrix[i][j] == 'B') {
                totalMass += (mB1 + mB2) / 2.0;
                massOnCell += (mB1 + mB2) / 2.0;
            } else if (matrix[i][j] == 'X') {
                totalMass += mX;
                massOnCell += mX;
            }
        }
    }
    
    double probability = massOnCell / totalMass;
    cout << fixed << setprecision(13) << probability << endl;
    
    return 0;
}