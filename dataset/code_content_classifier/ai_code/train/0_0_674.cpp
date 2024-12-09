#include <iostream>
#include <vector>

using namespace std;

// Function to toggle the lights in the adjacent photocells
void toggleLights(vector<vector<int>>& arr, int row, int col) {
    arr[row][col] = 1 - arr[row][col]; // Toggle the current cell
    if(row-1 >= 0) arr[row-1][col] = 1 - arr[row-1][col]; // Toggle cell above
    if(row+1 < 10) arr[row+1][col] = 1 - arr[row+1][col]; // Toggle cell below
    if(col-1 >= 0) arr[row][col-1] = 1 - arr[row][col-1]; // Toggle cell to the left
    if(col+1 < 10) arr[row][col+1] = 1 - arr[row][col+1]; // Toggle cell to the right
}

int main() {
    int n;
    cin >> n;

    for(int k = 0; k < n; k++) {
        vector<vector<int>> arr(10, vector<int>(10));
        
        // Input photocell status
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                cin >> arr[i][j];
            }
        }

        // Simulate passing the axion particles
        for(int i = 0; i < 10; i++) {
            if(arr[0][i] == 1) {
                toggleLights(arr, 0, i);
            }
        }

        // Output the final state
        for(int i = 0; i < 10; i++) {
            for(int j = 0; j < 10; j++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}