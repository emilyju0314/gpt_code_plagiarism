#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> permutation(N);
    
    for (int i = 0; i < N; i++) {
        cin >> permutation[i];
    }
    
    int operations = 0;
    bool sorted = false;
    
    while (!sorted) {
        vector<int> high, low;
        
        for (int i = 0; i < N; i++) {
            if (*max_element(permutation.begin(), permutation.begin() + i + 1) == permutation[i]) {
                high.push_back(permutation[i]);
            } else {
                low.push_back(permutation[i]);
            }
        }
        
        permutation.clear();
        permutation.insert(permutation.end(), low.begin(), low.end());
        permutation.insert(permutation.end(), high.begin(), high.end());
        
        operations++;
        sorted = is_sorted(permutation.begin(), permutation.end());
    }
    
    cout << operations << endl;
    
    return 0;
}