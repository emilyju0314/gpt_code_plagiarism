#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int N, Q;
    cin >> N >> Q;
    
    vector<int> row(N, N-2);
    vector<int> col(N, N-2);
    unordered_set<int> whites;
    
    long long black_stones = (N-2) * (N-2);
    
    while (Q--) {
        int query, x;
        cin >> query >> x;
        
        if (query == 1) {
            while (whites.find(x) == whites.end()) {
                black_stones -= row[x];
                col[row[x]] = x-1;
                row[x]--;
            }
        } else {
            while (whites.find(x) == whites.end()) {
                black_stones -= col[x];
                row[col[x]] = x-1;
                col[x]--;
            }
        }
        whites.insert(x);
    }
    
    cout << black_stones << endl;
    
    return 0;
}