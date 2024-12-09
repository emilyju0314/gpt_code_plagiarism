#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<vector<int>> photo(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        string line;
        cin >> line;
        for(int j = 0; j < m; j++) {
            photo[i][j] = line[j] - '0';
        }
    }
    
    int count = 0;
    for(int i1 = 0; i1 < n; i1++) {
        for(int j1 = 0; j1 < m; j1++) {
            for(int i2 = i1; i2 < n; i2++) {
                for(int j2 = j1; j2 < m; j2++) {
                    int stars = 0;
                    for(int i = i1; i <= i2; i++) {
                        for(int j = j1; j <= j2; j++) {
                            if(photo[i][j] == 1) {
                                bool isStar = true;
                                if(i > 0 && photo[i-1][j] == 0) {
                                    isStar = false;
                                }
                                if(j > 0 && photo[i][j-1] == 0) {
                                    isStar = false;
                                }
                                if(i < n-1 && photo[i+1][j] == 0) {
                                    isStar = false;
                                }
                                if(j < m-1 && photo[i][j+1] == 0) {
                                    isStar = false;
                                }
                                if(isStar) {
                                    stars++;
                                }
                            }
                        }
                    }
                    if(stars >= k) {
                        count++;
                    }
                }
            }
        }
    }
    
    cout << count << endl;
    
    return 0;
}