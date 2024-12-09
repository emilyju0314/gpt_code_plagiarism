#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<pair<int, int>> rooks(N);
    map<int, int> rows, cols;
    
    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        rooks[i] = {x, y};
        rows[x]++;
        cols[y]++;
    }
    
    int max_moves = 0;
    
    for (int i = 0; i < N; i++) {
        int x = rooks[i].first;
        int y = rooks[i].second;
        
        int moves = max(rows[x], cols[y]) - 1;
        cout << moves << endl;
    }

    return 0;
}