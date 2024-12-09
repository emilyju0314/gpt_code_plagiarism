// C++ program to find cells damaged by bomber at least K times

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M, K, L;
    cin >> N >> M >> K >> L;

    // Read the bombing pattern
    vector<string> bombs(N);
    for(int i=0; i<N; i++){
        cin >> bombs[i];
    }

    // Read the moving pattern
    string moves;
    cin >> moves;

    // Initialize the grid to track damaged cells
    vector<vector<int>> grid(M, vector<int>(M, 0));

    // Initialize the bomber position
    int br = 1, bc = 1;

    // Initialize the count of damaged cells
    int damagedCount = 0;

    // Simulate the bomber's movement and bombing
    for(int i=0; i<L; i++){
        // Drop bomb at current position
        for(int x=0; x<N; x++){
            for(int y=0; y<N; y++){
                if(br + x - 1 >= 1 && br + x - 1 <= M && bc + y - 1 >= 1 && bc + y - 1 <= M){
                    if(bombs[x][y] == 'X'){
                        grid[br + x - 1][bc + y - 1]++;
                        if(grid[br + x - 1][bc + y - 1] == K){
                            damagedCount++;
                        }
                    }
                }
            }
        }

        // Move the bomber
        if(moves[i] == 'U'){
            br--;
        } else if(moves[i] == 'D'){
            br++;
        } else if(moves[i] == 'L'){
            bc--;
        } else if(moves[i] == 'R'){
            bc++;
        }
    }

    // Output the number of cells damaged at least K times
    cout << damagedCount << endl;

    return 0;
}