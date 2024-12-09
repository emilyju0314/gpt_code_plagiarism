#include <iostream>
#include <vector>

using namespace std;

int main() {
    int D, M;
    cin >> D;
    
    vector<int> c(26);
    for (int i = 0; i < 26; i++) {
        cin >> c[i];
    }
    
    vector<vector<int>> s(D, vector<int>(26));
    for (int i = 0; i < D; i++) {
        for (int j = 0; j < 26; j++) {
            cin >> s[i][j];
        }
    }
    
    vector<int> t(D);
    for (int i = 0; i < D; i++) {
        cin >> t[i];
    }
    
    cin >> M;
    
    int total_satisfaction = 0;
    for (int i = 0; i < D; i++) {
        total_satisfaction += s[i][t[i]-1];
    }
    
    for (int i = 0; i < M; i++) {
        int d, q;
        cin >> d >> q;
        
        total_satisfaction -= s[d-1][t[d-1]-1];
        t[d-1] = q;
        total_satisfaction += s[d-1][q-1];
        
        cout << total_satisfaction << endl;
    }
    
    return 0;
}