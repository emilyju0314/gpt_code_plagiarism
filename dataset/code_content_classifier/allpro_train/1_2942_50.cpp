#include <bits/stdc++.h>
#define rep(i,a,b) for (int i = (a); i < (b); i++)
#define REP(i,n) rep(i,0,n)
using namespace std;

int main()
{
    int n;cin>>n;
    bitset<64>mask[n];
    REP(i,n)
    {
        int k;cin>>k;
        REP(j,k)
        {
            int64_t x;
            cin>>x;
            mask[i].set(x);
        }
    }
    int q;cin>>q;
    bitset<64>a;
    REP(i,q){
        int comm,m;cin>>comm>>m;
        switch (comm){
            case 0:
                cout<<a.test(m)<<endl;
            break;
            case 1:
                a|=mask[m];
            break;
            case 2:
                a&=~mask[m];
            break;
            case 3:
                a^=mask[m];
            break;
            case 4:
                cout<<((a&mask[m])==mask[m])<<endl;
                
            break;
            case 5:
                cout<<(a&mask[m]).any()<<endl;
            break;
            case 6:
                cout<<(a&mask[m]).none()<<endl;
            break;
            case 7:
                cout<<(a&mask[m]).count()<<endl;
            break;
            case 8:
                cout<<(a&mask[m]).to_ullong()<<endl;
            break;
    }
    }
}

