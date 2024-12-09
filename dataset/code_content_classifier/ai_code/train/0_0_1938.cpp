#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<string> grid(n);
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }
    
    vector<string> operations;
    int k = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                if ((i+j) % 2 == 0) {
                    operations.push_back("B " + to_string(i+1) + " " + to_string(j+1));
                    k++;
                } else {
                    operations.push_back("R " + to_string(i+1) + " " + to_string(j+1));
                    k++;
                }
            }
        }
    }
    
    cout << k << endl;
    for (auto op : operations) {
        cout << op << endl;
    }
    
    return 0;
}