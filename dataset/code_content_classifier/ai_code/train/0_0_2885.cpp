#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    int t;
    cin >> t;
    
    unordered_set<int> negIndices;
    for(int i = 0; i < t; i++) {
        int idx;
        cin >> idx;
        negIndices.insert(idx);
    }
    
    vector<int> x(n, 1);
    for(int i = 0; i < n; i++) {
        if(negIndices.count(i+1) > 0) {
            x[i] = -p[i];
        } else {
            x[i] = p[i];
        }
    }
    
    vector<int> stack;
    for(int i = 0; i < n; i++) {
        if(x[i] < 0) {
            if(stack.empty() || stack.back() != -x[i]) {
                cout << "NO" << endl;
                return 0;
            } else {
                stack.pop_back();
            }
        } else {
            stack.push_back(x[i]);
        }
    }
    
    if(!stack.empty()) {
        cout << "NO" << endl;
        return 0;
    }
    
    cout << "YES" << endl;
    for(int i = 0; i < n; i++) {
        cout << x[i] << " ";
    }
    
    return 0;
}