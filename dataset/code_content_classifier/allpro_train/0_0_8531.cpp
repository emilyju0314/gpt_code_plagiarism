#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    char country[3000][3000];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> country[i][j];
        }
    }

    int count = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(country[i][j] == 'z') {
                int k = 1;
                while(i+k < n && i-k >= 0 && j+k < m && j-k >= 0 &&
                      country[i+k][j] == 'z' && country[i-k][j] == 'z' &&
                      country[i][j+k] == 'z' && country[i][j-k] == 'z') {
                    count++;
                    k++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}