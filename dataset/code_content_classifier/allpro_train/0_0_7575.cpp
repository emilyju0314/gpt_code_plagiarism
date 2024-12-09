#include <iostream>
#include <vector>

using namespace std;

bool canEqualizeBids(vector<int>& bids) {
    int n = bids.size();
    
    for(int i=0; i<n; i++) {
        while(bids[i] % 2 == 0) {
            bids[i] /= 2;
        }
        while(bids[i] % 3 == 0) {
            bids[i] /= 3;
        }
    }
    
    for(int i=1; i<n; i++) {
        if(bids[i] != bids[0]) {
            return false;
        }
    }
    
    return true;
}

int main() {
    int n;
    cin >> n;
    
    vector<int> bids(n);
    for(int i=0; i<n; i++) {
        cin >> bids[i];
    }
    
    if(canEqualizeBids(bids)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}