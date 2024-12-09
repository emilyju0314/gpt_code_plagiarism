#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n, q;
    priority_queue<int> Q[1010];
    cin >> n >> q;
    for(int i=0; i<q; i++){
        int a, t, x;
        cin >> a;
        if(a==0){
            cin >> t >> x;
            Q[t].push(x);
        }
        else if(a==1){
            cin >> t;
            if(Q[t].size()>0)
                cout << Q[t].top() << "\n";
        }
        else {
            cin >> t;
            if(Q[t].size()>0)
                Q[t].pop();
        }
    }
    
    
    return 0;
}

