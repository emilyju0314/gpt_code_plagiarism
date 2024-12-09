#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> planks(n);
    unordered_map<int, int> count;
    
    for(int i = 0; i < n; i++) {
        cin >> planks[i];
        count[planks[i]]++;
    }
    
    int q;
    cin >> q;
    
    int rect_count = 0, square_count = 0;
    
    for(int i = 0; i < q; i++) {
        char op;
        int x;
        cin >> op >> x;
        
        if(op == '+') {
            count[x]++;
        } else {
            count[x]--;
        }
        
        rect_count = 0;
        square_count = 0;
        
        for(auto& it: count) {
            rect_count += it.second / 2;
            square_count += it.second / 4;
        }
        
        if(rect_count >= 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
    return 0;
}