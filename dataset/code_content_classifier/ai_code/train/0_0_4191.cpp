#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }
    
    long long prefix_sum = 0, suffix_sum = 0, total_sum = 0, max_sum = 0;
    
    for (int i = 0; i < n; i++) {
        total_sum += sequence[i];
        
        if (prefix_sum + sequence[i] > 0) {
            prefix_sum += sequence[i];
        } else {
            prefix_sum = 0;
        }
        
        max_sum = max(max_sum, prefix_sum);
    }
    
    for (int i = n - 1; i >= 0; i--) {
        if (suffix_sum + sequence[i] > 0) {
            suffix_sum += sequence[i];
        } else {
            suffix_sum = 0;
        }
    }
    
    cout << total_sum + max_sum + suffix_sum << endl;
    
    return 0;
}