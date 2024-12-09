#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    if (k == 2) {
        cout << "2" << endl;
        vector<int> colors;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                colors.push_back(i - j);
            }
        }
        for (int color : colors) {
            cout << color << " ";
        }
    } else {
        cout << "3" << endl;
        vector<int> colors;
        for (int i = 3; i <= n; i++) {
            for (int j = 2; j < i; j++) {
                colors.push_back(i - j);
            }
        }
        for (int color : colors) {
            cout << color << " ";
        }
    }

    return 0;
}