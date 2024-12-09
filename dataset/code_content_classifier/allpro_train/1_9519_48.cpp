#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define len(v) (int)(v.size())
#define ll long long
#define fi first
#define se second

using namespace std;

using psl = pair<string,ll>;

typedef tuple<string,int,int> tup;

struct edge{
	int to,cost;
    string buf;
};

vector<map<int, string> > mp;
bool flag;
vector<vector<edge> > G;

void dijkstra(int n,int s,int val)
{
	priority_queue<tup,vector<tup>,greater<tup> > que;
	mp[s][0] = "";
	que.push(tup("",0,s));
	while(!que.empty()){
		tup t = que.top();
		que.pop();
		string ss = get<0>(t);
		int l = get<1>(t);
		int v = get<2>(t);
		if(mp[v][l] < ss) continue;
		for(auto w : G[v]){
			int nagasa = l+w.cost;
			string hoge = ss+w.buf;
			if(nagasa <= val*(n-1) && (mp[w.to].find(nagasa) == mp[w.to].end() || mp[w.to][nagasa] > hoge)){
				mp[w.to][nagasa] = hoge;
				que.push(tup(hoge,nagasa,w.to));
			}
		}
	}
}

//
// void shortest_path(int n,int m,int s,int val,int hoge)
// {
//     if(!flag){
//         flag = true;
//         mp[s][0] = "";
//     }
// 	int cnt = 0;
// 	while(cnt < hoge){
//         bool update=false;
// 		rep(i,m){
// 			edge& e = es[i];
// 			for(auto& it : mp[e.from]){
//                 if(it.fi+e.leng <= val*(n-1)){
//                     string t = it.se+e.buf;
//                     if((mp[e.to].find(len(t)) == mp[e.to].end()) || (t < mp[e.to][len(t)])){
//                         update = true;
//                         mp[e.to][len(t)] = t;
//                     }
//                 }
//             }
// 		}
//         if(!update) break;
//         cnt++;
// 	}
// }

int main()
{
    // cin.tie(0);
    // ios::sync_with_stdio(false);
    while(1){
        int n,a,s,g;
        cin >> n >> a >> s >> g;
        if(n + a + s + g == 0){
            break;
        }
        flag = false;
        G.resize(n),mp.resize(n);
        rep(i,n){
            G[i].clear();
        }
        rep(i,n){
            mp[i].clear();
        }
        rep(i,a){
            int u,v;
            string ss;
            cin >> u >> v >> ss;
            G[u].push_back((edge){v,len(ss),ss});
        }
        dijkstra(n,s,30);
        if(len(mp[g]) == 0){
            cout << "NO\n";
            continue;
        }
        vector<string> vec;
        for(auto&it : mp[g]){
            vec.push_back(it.se);
        }
        // for(auto&it : mp[1]){
        //     cout << it.fi << " " << it.se << "\n";
        // }
        sort(vec.begin(),vec.end());
        string r1 = vec[0];
        // cout << r1 << "\n";
        // dijkstra(n,s,20);
        // for(auto&it : mp[2]){
        //     cout << it.fi << " " << it.se << "\n";
        // }
        // vec.clear();
        // for(auto&it : mp[g]){
        //     vec.push_back(it.se);
        // }
        // sort(vec.begin(),vec.end());
        // string r2 = vec[0];
        if(len(r1) <= 6*(n-1)){
            cout << r1 << "\n";
        }else{
            cout << "NO\n";
        }
    }
}