#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> blocks(n);
    for(int i = 0; i < n; i++) {
        cin >> blocks[i];
    }
    
    vector<string> operations;
    operations.push_back(string(n, '1')); // all blocks are removed in the first operation
    
    for(int i = 0; i < n; i++) {
        string op = string(n, '0');
        for(int j = 0; j < blocks[i]; j++) {
            op[j] = '1';
        }
        operations.push_back(op);
    }
    
    cout << n + 1 << endl;
    for(string &op : operations) {
        cout << op << endl;
    }
    
    return 0;
}