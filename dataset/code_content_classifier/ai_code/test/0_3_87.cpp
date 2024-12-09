#include <iostream>
#include <vector>

using namespace std;

int min_operations(vector<int>& sequence) {
    int operations = 0;
    int n = sequence.size();
    
    for(int i = 1; i < n; i++) {
        if(sequence[i] > i+1) {
            operations += sequence[i] - (i+1);
            sequence[i] = i+1;
        }
    }
    
    return operations;
}

int main() {
    int t;
    cin >> t;
    
    while(t--) {
        int n;
        cin >> n;
        
        vector<int> sequence(n);
        for(int i = 0; i < n; i++) {
            cin >> sequence[i];
        }
        
        int min_ops = min_operations(sequence);
        cout << min_ops << endl;
    }
    
    return 0;
}