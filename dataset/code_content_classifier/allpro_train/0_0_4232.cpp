#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int AW, AH, BW, BH;
    cin >> AW >> AH >> BW >> BH;

    vector<string> a(AH);
    for (int i = 0; i < AH; i++) {
        cin >> a[i];
    }

    vector<string> b(BH);
    for (int i = 0; i < BH; i++) {
        cin >> b[i];
    }

    int count = 0;
    for (int i = 0; i <= AH - BH; i++) {
        for (int j = 0; j <= AW - BW; j++) {
            bool match = true;
            for (int k = 0; k < BH; k++) {
                for (int l = 0; l < BW; l++) {
                    if (b[k][l] != '?' && b[k][l] != a[i + k][j + l]) {
                        match = false;
                        break;
                    }
                }
                if (!match) {
                    break;
                }
            }
            if (match) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}