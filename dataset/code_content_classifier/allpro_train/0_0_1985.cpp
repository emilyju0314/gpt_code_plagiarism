#include <iostream>
#include <vector>

using namespace std;

int main() {
    int levels;
    cin >> levels;

    for (int l = 0; l < levels; l++) {
        int NY, NX;
        cin >> NY >> NX;

        vector<string> grid(NY);
        for (int i = 0; i < NY; i++) {
            cin >> grid[i];
        }

        int snowmans = 0;
        for (int i = 0; i < NY; i++) {
            for (int j = 0; j < NX; j++) {
                if (grid[i][j] == '^') {
                    // Check if snowman needed on left
                    if (j > 0 && grid[i][j-1] == '_') {
                        snowmans++;
                        grid[i][j-1] = '#';
                    }
                    // Check if snowman needed on right
                    if (j < NX-1 && grid[i][j+1] == '_') {
                        snowmans++;
                        grid[i][j+1] = '#';
                    }
                    // Check if snowman needed above
                    if (i > 0 && grid[i-1][j] == '_') {
                        snowmans++;
                        grid[i-1][j] = '#';
                    }
                    // Check if snowman needed below
                    if (i < NY-1 && grid[i+1][j] == '_') {
                        snowmans++;
                        grid[i+1][j] = '#';
                    }
                }
            }
        }

        cout << snowmans << endl;
    }

    return 0;
}