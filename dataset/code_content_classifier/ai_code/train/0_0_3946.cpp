#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;

    vector<string> columns(R);
    for(int i = 0; i < R; i++) {
        cin >> columns[i];
    }

    int segments = 0;
    bool inSegment = false;

    for(int c = 0; c < C; c++) {
        bool hasBrick = false;
        for(int r = 0; r < R; r++) {
            if(columns[r][c] == 'B') {
                hasBrick = true;
                break;
            }
        }
        if(hasBrick) {
            if(!inSegment) {
                segments++;
                inSegment = true;
            }
        } else {
            inSegment = false;
        }
    }

    cout << segments << endl;

    return 0;
}