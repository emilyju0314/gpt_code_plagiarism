#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool isCyclicShift(vector<int>& p, vector<int>& subseq) {
    if(p.size() != subseq.size()) {
        return false;
    }
    
    int n = p.size();
    for(int i = 0; i < n; i++) {
        vector<int> shifted(n);
        for(int j = 0; j < n; j++) {
            shifted[j] = subseq[(j+i)%n];
        }
        
        if(p == shifted) {
            return true;
        }
    }
    
    return false;
}

int main() {
    int n, m, q;
    cin >> n >> m >> q;
    
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i];
    }
    
    vector<int> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }
    
    string result = "";
    for(int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        
        vector<int> subseq(a.begin() + l - 1, a.begin() + r);
        if(isCyclicShift(p, subseq)) {
            result += "1";
        } else {
            result += "0";
        }
    }
    
    cout << result << endl;
    
    return 0;
}