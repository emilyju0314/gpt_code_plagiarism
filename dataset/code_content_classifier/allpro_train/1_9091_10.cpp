#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<int,int> P;
#define Mod 1000000007
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<int>; using VVI = vector<VI>; using VVVI = vector<VVI>;
#define INF 123456789012

#define MAX_V 202020

int V;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];

void  addedge(int from,int to){
    G[from].push_back(to);
    rG[to].push_back(from);
}
 
void dfs(int v){
    used[v]=true;
    for(int i=0;i<G[v].size();i++){
        if(!used[G[v][i]]) dfs(G[v][i]);
    }
    vs.push_back(v);
}
 
void rdfs(int v,int k){
    used[v]=true;
    cmp[v]=k;
    for(int i=0;i<rG[v].size();i++){
        if(!used[rG[v][i]]) rdfs(rG[v][i],k);
    }
}
 
int scc(){
    memset(used,0,sizeof(used));
    vs.clear();
    for(int v=0;v<V;v++){
        if(!used[v]) dfs(v);
    }
    memset(used,0,sizeof(used));
    int k=0;
    for(int i=vs.size()-1;i>=0;i--){
        if(!used[vs[i]]) rdfs(vs[i],k++);
    }
    return k;
}

int m;

void yaj(int i,int j){
    addedge(i,j);
    addedge((j+m)%V,(i+m)%V);
}



int main(){
    int i,j;
    int n,x,a,o;
    cin>>n>>x>>a>>o;
    m=1<<(n+1);
    V=2*m;

    for(i=0;i<m;i++){
        for(j=i;j<m;j++){
            if(((i^j)==x)||((i&j)==a)||((i|j)==o)){
                yaj(i,j+m);
                yaj(j,i+m);
                //cout<<i<<" "<<j<<endl;
            }
        }
    }
    for(i=0;i<m;i++){
        j=i^x;
        yaj(i+m,j);
    }

    scc();

    vector<int> ans;
    for(i=0;i<m;i++){
        if(cmp[i]==cmp[i+m]) {
            cout<<"No"<<endl;
            return 0;
        }
        else if(cmp[i]>cmp[i+m]){
            ans.pb(i);
            //cout<<i<<endl;
        }
    }

    cout<<"Yes"<<endl;
    for(i=0;i<ans.size();i++){
        if(i!=0) cout<<" ";
        cout<<ans[i];
    }
    cout<<endl;

    return 0;
}
