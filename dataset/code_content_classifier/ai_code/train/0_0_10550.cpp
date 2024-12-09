#include <iostream>
#include <vector>
using namespace std;

bool checkAchievable(vector<vector<int>>& original, vector<vector<int>>& target) {
    for (int i = 0; i <= original.size() - 3; i++) {
        for (int j = 0; j <= original[0].size() - 3; j++) {
            vector<int> rotated;
            for (int k = 0; k < 3; k++) {
                for (int l = 0; l < 3; l++) {
                    rotated.push_back(original[i+k][j+l]);
                }
            }
            reverse(rotated.begin(), rotated.end());
            if (rotated == target[0] || rotated == target[1] || rotated == target[2]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int N;
    cin >> N;
    
    vector<vector<int>> original(3, vector<int>(N));
    vector<vector<int>> target(3, vector<int>(N));
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            cin >> original[i][j];
        }
    }
    
    // Generating the target matrix
    int count = 1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            target[i][j] = count++;
        }
    }
    
    if (checkAchievable(original, target)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}