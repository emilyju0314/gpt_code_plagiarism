#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> p(n);
    vector<int> q(n);
    vector<int> pos_p(n+1);
    vector<int> pos_q(n+1);
    
    for(int i=0; i<n; i++) {
        cin >> p[i];
        pos_p[p[i]] = i;
    }
    
    for(int i=0; i<n; i++) {
        cin >> q[i];
        pos_q[q[i]] = i;
    }
    
    int m;
    cin >> m;
    
    int x = 0;
    
    while(m--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        
        int l1 = min((pos_p[(a-1+x)%n+1]), (pos_p[(b-1+x)%n+1]));
        int r1 = max((pos_p[(a-1+x)%n+1]), (pos_p[(b-1+x)%n+1]));
        int l2 = min((pos_q[(c-1+x)%n+1]), (pos_q[(d-1+x)%n+1]));
        int r2 = max((pos_q[(c-1+x)%n+1]), (pos_q[(d-1+x)%n+1]));
        
        int count = 0;
        
        for(int i=l1; i<=r1; i++) {
            if(l2 <= pos_q[p[i]] && pos_q[p[i]] <= r2) {
                count++;
            }
        }
        
        cout << count << endl;
        
        x = count;
    }
    
    return 0;
}