#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second
typedef vector<int>vint;
typedef pair<int,int>pint;
typedef vector<pint>vpint;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

signed main(){
    int N,Q;
    cin>>N>>Q;

    set<pint>st;
    st.insert({0ll,20000000000000ll+1});
    st.insert({N,0});

    while(Q--){
        int a,b;
        scanf("%lld%lld",&a,&b);

        while(b){

            auto it=st.lower_bound({a,-1});
            int r,c;
            tie(r,c)=*it;

            if(r!=a){
                st.erase(it);
                st.insert({a,c});
                st.insert({r,c});
                continue;
            }

            it--;
            int rr,cc;
            tie(rr,cc)=*it;

            if(b>=(cc-c)*(r-rr)){
                b-=(cc-c)*(r-rr);
                st.erase({r,c});
                st.erase({rr,cc});
                st.insert({r,cc});
            }
            else{
                st.erase({r,c});
                if(b%(r-rr))st.insert({rr+b%(r-rr),c+b/(r-rr)+1});
                st.insert({r,c+b/(r-rr)});
                b=0;
            }
        }
    }


    int pre=0;
    for(auto &p:st){
        for(;pre<p.fi;pre++)cout<<p.se<<endl;
    }
}
