#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;
    
    vector<int> p(n);
    unordered_set<int> nums;
    for(int i = 0; i < n; i++) {
        cin >> p[i];
        nums.insert(p[i]);
    }
    
    unordered_set<int> setA, setB;
    bool possible = true;
    
    for(int i = 0; i < n; i++) {
        int x = p[i];
        if(nums.find(a - x) != nums.end()) {
            setA.insert(x);
            setA.insert(a - x);
        } else if (nums.find(b - x) != nums.end()) {
            setB.insert(x);
            setB.insert(b - x);
        } else {
            possible = false;
            break;
        }
    }
    
    if(possible) {
        cout << "YES" << endl;
        for(int i = 0; i < n; i++) {
            if(setA.find(p[i]) != setA.end()) {
                cout << "0 ";
            } else {
                cout << "1 ";
            }
        }
    } else {
        cout << "NO" << endl;
    }
    
    return 0;
}