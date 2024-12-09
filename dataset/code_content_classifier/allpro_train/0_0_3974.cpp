#include <iostream>
#include <vector>

using namespace std;

int main() {
    int W, H;

    while (true) {
        cin >> W >> H;

        if (W == 0 && H == 0) {
            break;
        }

        vector<vector<int>> panels(H, vector<int>(W));
        int num_scratched_panels = 0;

        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                cin >> panels[i][j];
                if (panels[i][j] == 1) {
                    num_scratched_panels++;
                }
            }
        }

        int min_carpets = 0;

        for (int i = 1; i <= 10; i++) {
            for (int j = 1; j <= 10; j++) {
                if (W % i == 0 && H % j == 0) {
                    int num_carpets = 0;

                    for (int k = 0; k < H; k += j) {
                        for (int l = 0; l < W; l += i) {
                            bool covered = false;

                            for (int m = k; m < k + j; m++) {
                                for (int n = l; n < l + i; n++) {
                                    if (panels[m][n] == 1) {
                                        covered = true;
                                        break;
                                    }
                                }
                                if (covered) {
                                    break;
                                }
                            }

                            if (covered) {
                                num_carpets++;
                            }
                        }
                    }

                    if (num_carpets < min_carpets || min_carpets == 0) {
                        min_carpets = num_carpets;
                    }
                }
            }
        }

        cout << min_carpets << endl;
    }

    return 0;
}