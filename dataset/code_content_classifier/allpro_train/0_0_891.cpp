#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> tableA(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> tableA[i][j];
        }
    }
    
    vector<vector<int>> tableB(n, vector<int>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> tableB[i][j];
        }
    }
    
    vector<int> sortingSequence;
    
    for(int j = 0; j < m; j++) {
        vector<int> columnA;
        vector<int> columnB;
        
        for(int i = 0; i < n; i++) {
            columnA.push_back(tableA[i][j]);
            columnB.push_back(tableB[i][j]);
        }
        
        sort(columnA.begin(), columnA.end());
        sort(columnB.begin(), columnB.end());
        
        if(columnA != columnB) {
            cout << "-1" << endl;
            return 0;
        }
        
        for(int i = 0; i < n; i++) {
            if(tableA[i][j] != tableB[i][j]) {
                sortingSequence.push_back(j+1);
                break;
            }
        }
    }
    
    cout << sortingSequence.size() << endl;
    for(int i = 0; i < sortingSequence.size(); i++) {
        cout << sortingSequence[i] << " ";
    }
    
    return 0;
}