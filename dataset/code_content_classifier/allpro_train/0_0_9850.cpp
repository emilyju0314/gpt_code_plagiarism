#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool areMapsIdentical(vector<string>& map1, vector<string>& map2, int N) {
    if(map1 == map2) {
        return true;
    }
    
    for(int i = 0; i < 3; i++) {
        // Rotate map1 by 90 degrees
        vector<string> rotatedMap = map1;
        for(int row = 0; row < N; row++) {
            for(int col = 0; col < N; col++) {
                rotatedMap[col][N-1-row] = map1[row][col];
            }
        }
        map1 = rotatedMap;
        
        if(map1 == map2) {
            return true;
        }
    }
    
    // Flip map1 along the vertical axis
    reverse(map1.begin(), map1.end());
    
    if(map1 == map2) {
        return true;
    }
    
    return false;
}

int main() {
    int N;
    cin >> N;
    
    vector<string> map1(N);
    vector<string> map2(N);
    
    for(int i = 0; i < N; i++) {
        cin >> map1[i];
    }
    
    for(int i = 0; i < N; i++) {
        cin >> map2[i];
    }
    
    if(areMapsIdentical(map1, map2, N)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}