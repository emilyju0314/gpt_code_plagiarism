#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    while (cin >> n) {
        vector<int> antennas(n);
        for (int i = 0; i < n; i++) {
            cin >> antennas[i];
        }

        // 在這裡實現UVa1228的解題邏輯

        // 輸出答案
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                cout << " ";
            }
            cout << antennas[i];  // 這裡應該替換為正確的結果
        }
        cout << endl;
    }

    return 0;
}
