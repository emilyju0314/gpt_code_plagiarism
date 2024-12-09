#include <bits/stdc++.h>
using namespace std;
//#define int long long

struct Point{
    multiset<pair<int,int> > l,r;

    Point(){};
};

vector<int> ans;
int n,m;
int INF=INT32_MAX;

void f(Point chet){
    multiset<pair<int,int>,greater<pair<int,int> > > chet2;
    for(auto i:chet.r){
        chet2.insert(i);
    }
    auto it=chet2.begin();

    while(it!=chet2.end()){
        pair<int,int> v=*it;
        it++;
        pair<int,int> v2;
        if(chet.l.lower_bound(v)!=chet.l.end()){
            v2=*chet.l.lower_bound(v);
        }else{
            v2={INF,INF};
        }

        int res2=(v2.first-v.first)/2;

        if(v2.first!=INF){
            chet.r.erase(chet.r.find(v));
            chet.l.erase(chet.l.find(v2));
            ans[v.second]=res2;
            ans[v2.second]=res2;
        }
    }

    while(chet.l.size()>=2){
        pair<int,int> v=*chet.l.begin();
        chet.l.erase(chet.l.begin());
        pair<int,int> v1=*chet.l.begin();

        int res1=((v1.first)+(v.first))/2;

        chet.l.erase(chet.l.find(v1));
        ans[v.second]=res1;
        ans[v1.second]=res1;
    }

    while(chet.r.size()>=2){
        pair<int,int> v=*chet.r.rbegin();
        chet.r.erase(chet.r.find(v));
        pair<int,int> v1=*chet.r.rbegin();

        int res1=((m-v1.first)+(m-v.first))/2;

        chet.r.erase(chet.r.find(v1));
        ans[v.second]=res1;
        ans[v1.second]=res1;
    }

    if(chet.r.size()==1&&chet.l.size()==1){
        pair<int,int> v=*chet.r.begin();
        chet.r.erase(chet.r.begin());
        pair<int,int> v2=*chet.l.begin();
        chet.l.erase(chet.l.begin());

        int res=(v2.first+(m-v.first)+m)/2;
        ans[v.second]=res;
        ans[v2.second]=res;

    }

}

signed main() {
    ios::ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin>>t;

    for(int _i=0;_i<t;_i++){
        cin>>n>>m;

        vector<pair<int,char> > a(n);

        for(int i=0;i<n;i++){
            cin>>a[i].first;
        }

        for(int i=0;i<n;i++){
            cin>>a[i].second;
        }

        Point chet,nechet;
        for(int i=0;i<n;i++){
            if(a[i].first%2==0){
                if(a[i].second=='R'){
                    chet.r.insert({a[i].first,i});
                }else{
                    chet.l.insert({a[i].first,i});
                }
            }else{
                if(a[i].second=='R'){
                    nechet.r.insert({a[i].first,i});
                }else{
                    nechet.l.insert({a[i].first,i});
                }
            }
        }

//        chet.r.insert({INF,INF});
//        chet.l.insert({INF,INF});
//        nechet.r.insert({INF,INF});
//        nechet.l.insert({INF,INF});

//        sort(chet.r.begin(),chet.r.end());
//        sort(chet.l.begin(),chet.l.end());
//        sort(nechet.r.begin(),nechet.r.end());
//        sort(nechet.l.begin(),nechet.l.end());

        ans.assign(n,-1);

        f(chet);
        f(nechet);


        for(auto i:ans){
            cout<<i<<" ";
        }
        cout<<endl;
    }


}