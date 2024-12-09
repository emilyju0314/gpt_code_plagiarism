#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    map<int, int> boxes;
    int k, a;
    for(int i = 0; i < n; i++) {
        cin >> k >> a;
        boxes[k] = a;
    }
    
    int p = 0;
    int total = 0;
    for(auto it = boxes.rbegin(); it != boxes.rend(); it++) {
        total += it->second;
        if(total > (1 << p)) {
            p++;
        }
    }
    
    cout << p << endl;
    
    return 0;
}