#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> field(n);
    for(int i = 0; i < n; i++) {
        cin >> field[i];
    }

    long long count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(field[i][j] == '*') {
                for(int k = j+1; k < m; k++) {
                    if(field[i][k] == '*') {
                        for(int l = i+1; l < n; l++) {
                            if(field[l][j] == '*' && field[l][k] == '*') {
                                count++;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}