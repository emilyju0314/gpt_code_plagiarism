#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<int(n);++i)
#define FOR(i,l,r) for(int i=l;i<int(r);++i)
typedef long long ll;

#define M 500

ll a[250020],b[M];
bool same[M];

void update(int j){
    same[j] = true;
    ll first = a[j*M] + b[j];
    rep(i,M) same[j] &= (a[i+j*M]+b[j] == first);
}

// [l,r) 
void add(int l,int r,int x){
    if(l/M == r/M){
        FOR(i,l,r) a[i] += x;
        update(l/M);
        return;
    }

    FOR(j,l/M+1,r/M) b[j] += x;

    FOR(i,l,l-l%M+M) a[i] += x;
    update(l/M);

    FOR(i,r-r%M,r) a[i] += x;
    update(r/M);
}

int main(void){
    int N,Q;
    cin>>N;
    vector<int> s(N);
    rep(i,N) cin>>s[i];
    rep(i,N/2) a[i] = s[i]-s[N-1-i];
    rep(j,M) update(j);

    cin>>Q;
    while(Q--){
        int l,r,x;
        cin>>l>>r>>x;
        l--,r--;
        if(l<N/2 && N/2<=r){
            if(l<N-1-r) add(l,N-1-r,x);
            else add(N-1-r,l,-x);
        }
        if(r<N/2) add(l,r+1,x);
        if(N/2<=l) add(N-1-r,N-l,-x);

        bool allZero = true;
        rep(j,M){
            allZero &= (same[j] && a[j*M]+b[j]==0);
        }
        cout<<allZero<<endl;
    }
    return 0;
}