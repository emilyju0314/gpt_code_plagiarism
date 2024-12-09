#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int na, ma, nb, mb;
    cin >> na >> ma;

    vector<string> table1(na);
    for (int i = 0; i < na; i++) {
        cin >> table1[i];
    }

    cin >> nb >> mb;

    vector<string> table2(nb);
    for (int i = 0; i < nb; i++) {
        cin >> table2[i];
    }

    int maxOverlap = 0;
    int shiftX = 0, shiftY = 0;

    for (int i = 0; i <= nb - na; i++) {
        for (int j = 0; j <= mb - ma; j++) {
            int overlap = 0;
            for (int a = 0; a < na; a++) {
                for (int b = 0; b < ma; b++) {
                    if (a + i < nb && b + j < mb && table1[a][b] == '1' && table2[a + i][b + j] == '1') {
                        overlap++;
                    }
                }
            }

            if (overlap > maxOverlap) {
                maxOverlap = overlap;
                shiftX = i;
                shiftY = j;
            }
        }
    }

    cout << shiftX << " " << shiftY << endl;

    return 0;
}