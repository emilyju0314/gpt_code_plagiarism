#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> cloth(10, vector<int>(10, 0));

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> cloth[i][j];
        }
    }

    int drops = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (cloth[i][j] > 0) {
                drops++;
                cout << i << " " << j << " " << cloth[i][j] << endl;
            }
            if (drops == n) {
                return 0;
            }
        }
    }

    return 0;
}