#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    if (n % 2 == 0 && a % 2 == 0 && b % 2 == 0) {
        cout << -1 << endl;
        return 0;
    }

    vector<vector<int>> seats(a, vector<int>(b, 0));
    
    int parl_index = 1;
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            if ((i % 2 == 0 && j % 2 == 0) || (i % 2 == 1 && j % 2 == 1)) {
                if (parl_index <= n) {
                    seats[i][j] = parl_index;
                    parl_index += 2;
                }
            }
        }
    }

    for (int i = 0; i < a; i++) {
        for (int j = 0; j < b; j++) {
            cout << seats[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}