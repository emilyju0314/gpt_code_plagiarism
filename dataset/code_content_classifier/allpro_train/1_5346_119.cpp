#include<bits/stdc++.h>
using namespace std;
const int mxN=1e3+10;
int n,m,a,b,k;
int vis[mxN],pai[mxN];
vector<int>adj[mxN];
vector<int>resp;

void bfs(int x){
    queue<int>fila;
    fila.push(x);
    vis[x]=1;

    while(!fila.empty()){
        int u=fila.front();
        fila.pop();
        for(int v:adj[u])   {
            if(!vis[v]){
                vis[v]=1;
                pai[v]=u;
                fila.push(v);

            }
            if(v==x){
                vector<int>ans;
                while(u!=v){
                    ans.push_back(u);
                    u=pai[u];
                }
                ans.push_back(v);
                if(resp.size()==0 || ans.size()< resp.size())resp=ans;
                return;
            }
        }

    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>a>>b;
        adj[a].push_back(b);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            pai[j]=-1;
            vis[j]=0;            
        }
        bfs(i);       
    }
    if(resp.size()){
        cout<<resp.size()<<"\n";
        for(auto x:resp){
            cout<<x<<"\n";
        }
        return 0;
    }
    cout<<-1<<"\n";

     

}