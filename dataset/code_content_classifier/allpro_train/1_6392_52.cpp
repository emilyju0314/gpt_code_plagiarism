#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;
int n,m;
int s,t;
pii ps[101];
// »ê¼êÌÀW©çêÔß¢RrjÖÌ£
int dists[101][101];
const int INF=1000000000;
pii cand[101];
bool used[101][101];
bool noSet[101][101];

const int dy[2][6]={{-1,-1,0,1,1,0},{-1,-1,0,1,1,0}};
const int dx[2][6]={{-1,0,1,0,-1,-1},{0,1,1,1,0,-1}};

int updateMinDist(int sx,int sy,bool isSearch=true){
    memset(used,0,sizeof(used));
    queue<pii> q[2];
    int cur=0;
    int nxt=1;
    int cnt=0;
    pii sp=pii(sy,sx);
    used[sy][sx]=true;
    dists[sy][sx]=0;
    int res=1;
    q[cur].push(sp);
    while(q[cur].size()){
        while(q[cur].size()){
            pii p=q[cur].front();q[cur].pop();
            for(int i=0;i<6;i++){
                int ny=dy[p.first%2][i]+p.first;
                int nx=dx[p.first%2][i]+p.second;
                if(ny>=0&&nx>=0&&ny<n&&nx<m&&!used[ny][nx]){
                    used[ny][nx]=true;
                    q[nxt].push(pii(ny,nx));
                    if(isSearch)dists[ny][nx]=min(dists[ny][nx],cnt+1);
                    else if(dists[ny][nx]>cnt+1)res++;
                }
            }
        }
        cnt++;
        swap(cur,nxt);
    }
    return res;
}

int main(){
    while(cin>>m>>n&&(m|n)){
        memset(noSet,0,sizeof(noSet));
        cin>>s;
        for(int i=0;i<101;i++)for(int j=0;j<101;j++)dists[i][j]=INF;
        for(int i=0;i<s;i++){
            cin>>ps[i].second>>ps[i].first;
            ps[i].second--;
            ps[i].first--;
            noSet[ps[i].first][ps[i].second]=true;
        }
        for(int k=0;k<s;k++)updateMinDist(ps[k].second,ps[k].first);
        cin>>t;
        for(int i=0;i<t;i++){
            cin>>cand[i].second>>cand[i].first;
            cand[i].second--;
            cand[i].first--;
        }
        int res=0;
        for(int i=0;i<t;i++){
            int cnt=0;
            cnt=updateMinDist(cand[i].second,cand[i].first,false);
            res=max(res,cnt);
        }
        cout<<res<<endl;
    }
    return 0;
}