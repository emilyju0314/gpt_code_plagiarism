#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> grid(H);
    for(int i = 0; i < H; i++) {
        cin >> grid[i];
    }

    int robots = 0;
    for(int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++) {
            if(grid[i][j] == 'o') robots++;
        }
    }

    cout << robots << endl;

    return 0;
}