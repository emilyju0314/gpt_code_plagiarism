#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+10;
int bit[2*N+1];
int sz;
int l[N],r[N];
vector<int> G[N];
int cnt;

void init(int n){
    cnt = 0;
    sz = 2*n + 1;
}

void dfs(int v){
    l[v] = ++cnt;
    for(int i=0;i<G[v].size();i++){
        int u = G[v][i];
        dfs(u);
    }
    r[v] = ++cnt;
}

void add(int i,int x){
    while(i<=sz){
        bit[i] += x;
        i += i&-i;
    }
}

int getSum(int i){
    int ans = 0;
    while(i>0){
        ans += bit[i];
        i -= i&-i;
    }
    return ans;
}


int main(){
    int n;
    while(cin>>n){
        init(n);
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            for(int j=0;j<k;j++){
                int child;
                cin>>child;
                G[i].push_back(child);
            }
        }
        dfs(0);
        int q;
        cin>>q;
        for(int i=0;i<q;i++){
            int op;
            cin>>op;
            if(op == 0){
                int v,w;
                cin>>v>>w;
                add(l[v],w);
                add(r[v],-w);
            }else{
                int v;
                cin>>v;
                cout<<getSum(r[v] - 1)<<endl;
            }
        }
    }

    return 0;
}

