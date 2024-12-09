#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> goodCars;
    
    // Read the matrix A
    vector<vector<int>> A(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    
    // Check which cars are good
    for(int i = 0; i < n; i++) {
        bool isGood = true;
        for(int j = 0; j < n; j++) {
            if(i != j && A[i][j] != 0) {
                isGood = false;
                break;
            }
        }
        if(isGood) {
            goodCars.push_back(i+1);
        }
    }
    
    // Print the number of good cars and their indices
    cout << goodCars.size() << endl;
    for(int i = 0; i < goodCars.size(); i++) {
        cout << goodCars[i] << " ";
    }
    
    return 0;
}