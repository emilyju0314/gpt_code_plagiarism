#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string a, b;
    cin >> a >> b;
    
    int q; // number of queries
    cin >> q;
    
    // precompute the Hamming distances for all prefixes of a and b
    vector<int> hamming_a(a.size() + 1, 0);
    vector<int> hamming_b(b.size() + 1, 0);
    
    for(int i = 1; i <= a.size(); i++) {
        hamming_a[i] = hamming_a[i - 1] + (a[i - 1] != b[i - 1]);
    }
    
    for(int i = 1; i <= b.size(); i++) {
        hamming_b[i] = hamming_b[i - 1] + (a[i - 1] != b[i - 1]);
    }
    
    // answer the queries
    for(int i = 0; i < q; i++) {
        int p1, p2, len;
        cin >> p1 >> p2 >> len;
        
        int dist = hamming_b[p2 + len] - hamming_b[p2] + hamming_a[p1 + len] - hamming_a[p1];
        cout << dist << endl;
    }
    
    return 0;
}