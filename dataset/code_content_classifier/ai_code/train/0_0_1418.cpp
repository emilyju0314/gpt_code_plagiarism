#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    
    string colors;
    cin >> colors;
    
    int repaints = 0;
    for (int i = 0; i < n - 1; i++) {
        if (colors[i] == colors[i + 1]) {
            repaints++;
            for (char c = 'A'; c <= 'A' + k - 1; c++) {
                if (c != colors[i] && (i == 0 || c != colors[i - 1]) && (c != colors[i + 1] || (i + 2 < n && c != colors[i + 2]))) {
                    colors[i + 1] = c;
                    break;
                }
            }
        }
    }
    
    cout << repaints << endl;
    cout << colors << endl;
    
    return 0;
}