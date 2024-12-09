#include <iostream>
#include <vector>
using namespace std;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<char>> field(h, vector<char>(w));
    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            cin >> field[i][j];
        }
    }

    for(int i=0; i<h; i++) {
        for(int j=0; j<w; j++) {
            char color = field[i][j];

            // Check horizontally
            int cnt = 1;
            for(int k=j+1; k<w; k++) {
                if(field[i][k] == color) {
                    cnt++;
                } else {
                    break;
                }
            }
            if(cnt >= n) {
                cout << "YES" << endl;
                return 0;
            }

            // Check vertically
            cnt = 1;
            for(int k=i+1; k<h; k++) {
                if(field[k][j] == color) {
                    cnt++;
                } else {
                    break;
                }
            }
            if(cnt >= n) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;
    return 0;
}