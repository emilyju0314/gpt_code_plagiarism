#include <iostream>
#include <vector>

using namespace std;

vector<int> findQuadraticSubset(int n) {
    vector<int> subset;
    
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            subset.push_back(i);
        }
    }
    
    return subset;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> subset = findQuadraticSubset(n);
    
    cout << subset.size() << endl;
    
    for (int i = 0; i < subset.size(); i++) {
        cout << subset[i] << " ";
    }
    
    return 0;
}