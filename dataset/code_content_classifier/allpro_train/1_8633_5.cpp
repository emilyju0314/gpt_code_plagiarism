#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define int ll
typedef long long ll;
const int N=2e5+5;
ll ma[N*4];
int n,q;

void update(int l,int r,int id,int i,int v){
    if(l==r){
        ma[id]=v;
        return;
    }
    int mid=(l+r)>>1;
    ma[id]=0;
    if(i<=mid)update(l,mid,id*2,i,v);
    else update(mid+1,r,id*2+1,i,v);
    if(ma)
    ma[id]=max(ma[id*2],ma[id*2+1]);
}
/*
ll query_mi(int l,int r,int ql,int v,int id){
    if(r<ql)return -1;
    if(l==r){
        if(ma[id]>=v)return l;
        else return -1;
    }
    int mid=(l+r)>>1;
    int ans=-1;
    if(ql<mid)ans=query_mi(l,mid,ql,v,id*2);
    if(ans!=-1)return ans;
    ans=query_mi(mid+1,r,ql,v,id*2+1);
    return ans;
}
*/vector<int> a;
ll mi(int x,int v){
    for(int i=x;i<=n;i++){
        if(a[i]>=v)return i;
    }
    return n+1;
}

ll query_ma(int l,int r,int ql,int qr,int id){
    if(l>=ql&&r<=qr)return ma[id];
    int mid=(l+r)>>1;
    int a=0,b=0;
    if(ql<=mid)a=query_ma(l,mid,ql,qr,id*2);
    if(qr>mid)b=query_ma(mid+1,r,ql,qr,id*2+1);
    return max(a,b);
}

/*
ll query_ma(int l,int r,int ql,int qr,int id){
    if(l>=ql&&r<=qr)return ma[id];
    int mid=(l+r)>>1;

    if(qr<=mid){
        return query_ma(l,mid,ql,qr,id*2);
    }
    else if(ql>=mid+1){
        return query_ma(mid+1,r,ql,qr,id*2+1);
    }
    else{
        int a=query_ma(l,mid,ql,qr,id*2),b=query_ma(mid+1,r,ql,qr,id*2+1);
        return max(a,b);
    }
}
*/
signed main(){
    ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);

    cin>>n>>q;
    a.resize(n+1);
    for(int i=1;i<=n;i++){
        int x;cin>>x;
        a[i]=x;
        update(1,n,1,i,x);
    }
    while(q--){
        int mode,x,y;cin>>mode>>x>>y;
        if(mode==1){
            update(1,n,1,x,y);
            a[x]=y;
        }
        else if(mode==2){
            cout<<query_ma(1,n,x,y,1)<<endl;
        }
        else if(mode==3){
            /*
            ll ans=query_mi(1,n,x,y,1);
            if(ans==-1)cout<<n+1<<endl;
            else cout<<ans<<endl;
            */
            cout<<mi(x,y)<<endl;
        }
    }
}
