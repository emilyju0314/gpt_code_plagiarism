#include <iostream>

using namespace std;

int field[5][5];
int largest[5][5];

bool fill(int sy, int sx, int gy, int gx) {
    bool ret = true;
    for (int i = sy; i <= gy; i++) {
        for (int j = sx; j <= gx; j++) {
            if (field[i][j] == 0) {
                ret = false;
                break;
            }
        }
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    while (n--) {
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                cin >> field[i][j];
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                int max_rectangle = 0;
                for (int k = i; k < 5; k++) {
                    for (int l = j; l < 5; l++) {
                        if (fill(i, j, k, l)) {
                            int count = (k-i+1)*(l-j+1); 
                            if (max_rectangle < count) {
                                max_rectangle = count;
                            }
                        }
                    }
                }
                largest[i][j] = max_rectangle;
            }
        }
        int max_rectangle = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
//                cout << largest[i][j] << ' ';
                if (max_rectangle < largest[i][j]) {
                    max_rectangle = largest[i][j];
                }
            }
//            cout << endl;
        }

        cout << max_rectangle << endl;

    }
    return 0;
}