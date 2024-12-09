#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<vector<int>> friendPreferences(n, vector<int>(n));
    vector<int> alexanderPreferences(n);
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> friendPreferences[i][j];
        }
    }
    
    for(int i = 0; i < n; i++) {
        cin >> alexanderPreferences[i];
    }
    
    vector<int> result(n);
    
    for(int i = 0; i < n; i++) {
        int card = 0;
        for(int j = 0; j < n; j++) {
            if(alexanderPreferences[i] == friendPreferences[j][card]) {
                result[j] = i + 1;
                card = max(card, j);
            }
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    
    return 0;
}