#include<bits/stdc++.h>
#include<cstring>
#define   ll         long long
#define   ull        unsigned long long
#define   pb         push_back
#define   ff         first
#define   ss         second
#define   all(v)     (v.begin(), v.end())
#define   rall(v)    (v.rbegin(), v.rend())
#define   pi         acos(-1.0)
#define   FastRead   ios_base::sync_with_stdio(0);cin.tie(0); cout.tie(0);
#define   bug(a)     cerr << #a << " : " << a << endl
using namespace std;
const ll mod = 1e9+7;
//const ll mx = 2e6+10;

int posx[] = {1,-1, 0, 0};
int posy[] = {0, 0, 1,-1};
int depth[2000], arr[2000];
vector<int>tree[2000];
map<ll, bool>vis;

void rec(int l, int r, int root)
{
    if(l>r)return;
    int mx=arr[l], pos=l;
    for(int i=l; i<=r; i++){
            if(mx<arr[i]){
                    mx=arr[i];
                    pos=i;
            }
    }
    //cout << l << " " << r << " " << root << " " << mx << endl;
    tree[root].pb(mx);
    tree[mx].pb(root);
    rec(l, pos-1, mx);
    rec(pos+1, r, mx);
}

void Bfs(int src)
{
    queue<ll>q;
    q.push(src);
    vis[src] = true;
    while(!q.empty()){
                int u = q.front();
                q.pop();
                for(auto x: tree[u]){
                            if(!vis[x]){
                                      q.push(x);
                                      depth[x]+=depth[u]+1;
                                      vis[x] = true;
                            }
                }
    }

}

int main()
{
    FastRead

#ifdef Mfc_Tanzim
    freopen("input.txt","r", stdin);
    // freopen("output.txt","w", stdout);
#endif /// Mfc_Tanzim

    int t=1, n, k, m, a, b, c, d;
    cin >> t;

    while(t--){
            cin >> n;
            for(int i=1; i<=n; i++){
                    cin >> arr[i];
            }

            rec(1, n, 0);
            Bfs(0);

            for(int i=1; i<=n; i++){
                    cout << depth[arr[i]]-1 << " ";
            }
            cout << endl;

            for(int i=0; i<=n; i++){
                    tree[i].clear();
                    depth[i]=0;
            }
            vis.clear();
    }
    return 0;
}
