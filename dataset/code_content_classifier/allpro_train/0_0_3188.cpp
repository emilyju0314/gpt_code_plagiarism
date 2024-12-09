#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int main() {
    int n, m;
    
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        
        vector<char> chairs(n, '#');
        int aIndex = 0, bIndex = n - 1, cIndex = n / 2, dIndex = 0;
        
        for (int i = 0; i < m; i++) {
            char country;
            cin >> country;
            
            if (country == 'A') {
                while (chairs[aIndex] != '#') {
                    aIndex++;
                }
                chairs[aIndex] = 'A';
            } else if (country == 'B') {
                bool foundEmpty = false;
                while (!foundEmpty) {
                    if (bIndex - 1 >= 0 && chairs[bIndex - 1] == '#') {
                        bIndex--;
                        chairs[bIndex] = 'B';
                        foundEmpty = true;
                    } else if (aIndex + 1 < n && chairs[aIndex + 1] == '#') {
                        aIndex++;
                        chairs[aIndex] = 'B';
                        foundEmpty = true;
                    } else {
                        bIndex--;
                    }
                }
            } else if (country == 'C') {
                bool foundEmpty = false;
                for (int j = 0; j < n; j++) {
                    if (chairs[cIndex] == '#') {
                        chairs[cIndex] = 'C';
                        foundEmpty = true;
                        break;
                    } else if (cIndex + j < n && chairs[cIndex + j] == '#') {
                        chairs[cIndex + j] = 'C';
                        foundEmpty = true;
                        break;
                    } else if (cIndex - j >= 0 && chairs[cIndex - j] == '#') {
                        chairs[cIndex - j] = 'C';
                        foundEmpty = true;
                        break;
                    }
                }
                if (!foundEmpty) {
                    // Not ideal but the middle chair should always be empty for C
                    chairs[n / 2] = 'C';
                }
            } else if (country == 'D') {
                bool foundEmpty = false;
                for (int j = 0; j < n; j++) {
                    if (dIndex + j < n && chairs[dIndex + j] == '#') {
                        chairs[dIndex + j] = 'D';
                        foundEmpty = true;
                        break;
                    } else if (dIndex - j >= 0 && chairs[dIndex - j] == '#') {
                        chairs[dIndex - j] = 'D';
                        foundEmpty = true;
                        break;
                    }
                }
                if (!foundEmpty) {
                    chairs[0] = 'D';
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            cout << chairs[i];
        }
        cout << endl;
    }
    
    return 0;
}