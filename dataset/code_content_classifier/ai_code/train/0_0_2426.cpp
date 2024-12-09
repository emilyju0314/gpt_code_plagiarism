#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> a(m+1);
    vector<int> b(m);
    
    for(int i=0; i<=m; i++) {
        cin >> a[i];
    }
    for(int i=0; i<m; i++) {
        cin >> b[i];
    }
    
    int changes = 0;
    int last_rank = 2*n;
    
    for(int i=0; i<m; i++) {
        int teams = a[i+1] - a[i];
        int max_rank = 0;
        
        for(int j=0; j<teams; j++) {
            max_rank = max(max_rank, last_rank - b[i] - j);
        }
        
        changes += max_rank - (last_rank - b[i]);
        last_rank += teams;
    }
    
    cout << changes << endl;

    return 0;
}