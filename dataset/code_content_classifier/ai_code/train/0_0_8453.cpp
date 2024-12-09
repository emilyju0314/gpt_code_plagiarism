#include <iostream>
using namespace std;

int main() {
    int n, m, k, t;
    cin >> n >> m >> k >> t;

    int field[n+1][m+1] = {0};
    string crops[n+1][m+1];

    for(int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        field[a][b] = -1; // Mark waste cell
    }

    int cycle_length = 3;
    string crop_types[cycle_length] = {"Carrots", "Kiwis", "Grapes"};

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(field[i][j] != -1) {
                int cell_number = (i-1) * m + j;
                int crop_type_index = (cell_number - k - 1) % cycle_length;
                crops[i][j] = crop_types[crop_type_index];
            }
        }
    }

    for(int i = 0; i < t; i++) {
        int query_i, query_j;
        cin >> query_i >> query_j;

        if(field[query_i][query_j] == -1) {
            cout << "Waste" << endl;
        } else {
            cout << crops[query_i][query_j] << endl;
        }
    }

    return 0;
}