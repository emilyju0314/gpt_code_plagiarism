#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int grundy(ll n, ll m){
    if(n==1){
        return grundy(2,m) == 0;
    }
    ll l = m/2, r = m, cnt = 0, ev = m%2, od = (m+1)%2;
    while(l >= n){
        r = l;
        l >>= 1;
        cnt++;
        if(r%2){
            if(ev == 0){
                od = 1;
                ev = 2;
            }
            else if(ev == 1){
                od = 0;
                ev = 2;
            }
            else{
                od = 0;
                ev = 1;
            }
        }
        else{
            bool used[3]{};
            int pev = ev;
            used[pev] = true;
            used[od] = true;
            for(int i=0;i<3;i++){
                if(!used[i]){
                    ev = i;
                    break;
                }
            }
            fill(used, used+3, false);
            used[pev] = true;
            used[ev] = true;
            for(int i=0;i<3;i++){
                if(!used[i]){
                    od = i;
                    break;
                }
            }
        }
    }
    return (n%2 ? od : ev);
}

int main(){
    ll k, allxor = 0;
    cin >> k;

    for(int i=0;i<k;i++){
        ll n, m;
        cin >> n >> m;
        allxor ^= grundy(n, m);
    }
    if(allxor == 0){
        cout << "tubuann" << endl;
    }
    else{
        cout << "mo3tthi" << endl;
    }
    return 0;
}
