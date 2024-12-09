#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> pegs(n);
    for(int i = 0; i < n; i++) {
        cin >> pegs[i];
    }
    
    while(m--) {
        int a, l;
        cin >> a >> l;
        
        int leftmost = pegs[a-1] - l;
        int rightmost = pegs[a-1] + l;
        
        int leftpeg = a-1, rightpeg = a-1;
        
        for(int i = 0; i < n; i++) {
            if(pegs[i] < leftmost) {
                leftpeg = i;
            }
            if(pegs[i] > rightmost) {
                rightpeg = i;
                break;
            }
        }
        
        if(abs(pegs[leftpeg] - leftmost) >= abs(pegs[rightpeg] - rightmost)) {
            cout << leftpeg + 1 << endl;
        } else {
            cout << rightpeg + 1 << endl;
        }
    }
    
    return 0;
}