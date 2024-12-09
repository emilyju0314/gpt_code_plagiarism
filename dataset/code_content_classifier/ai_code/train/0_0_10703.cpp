#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> table(n, vector<int>(m));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> table[i][j];
        }
    }

    int k;
    cin >> k;

    for(int t=0; t<k; t++) {
        int l, r;
        cin >> l >> r;

        bool sorted = false;
        for(int j=0; j<m; j++) {
            bool is_sorted = true;
            for(int i=l-1; i<r; i++) {
                if(i > 0 && table[i][j] < table[i-1][j]) {
                    is_sorted = false;
                    break;
                }
            }
            if(is_sorted) {
                sorted = true;
                break;
            }
        }

        if(sorted) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}