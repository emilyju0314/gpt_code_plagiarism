#include<bits/stdc++.h>
using namespace std;

using ld=long double;
struct Match{
    int lhs,rhs;
    int lhsp,rhsp;
};

void debug(Match x){
    //cerr<<x.lhs<<"vs"<<x.rhs<<" "<<x.lhsp<<"-"<<x.rhsp<<endl;
}
void debug(vector<Match> x){
    //cerr<<"#These are match"<<endl;
    for(int i=0;i<x.size();i++){
        debug(x[i]);
    }
}
ld winner(const vector<Match> &match,int tar,int place){
    vector<int> pt(4);
    vector<int> gd(4);
    vector<int> sc(4);
    for(auto &m:match){
        pt[m.lhs]++;
        pt[m.rhs]++;
        if(m.lhsp<m.rhsp) pt[m.rhs]+=300;
        else if(m.lhsp>m.rhsp) pt[m.lhs]+=300;
        else pt[m.rhs]+=100,pt[m.lhs]+=100;
        gd[m.lhs]+=m.lhsp-m.rhsp;
        gd[m.rhs]+=m.rhsp-m.lhsp;
        sc[m.lhs]+=m.lhsp;
        sc[m.rhs]+=m.rhsp;
    }
    vector<int> rs(4);
    for(int i=0;i<4;i++) rs[i]=pt[i]*1e5+gd[i]*1e3+sc[i];
    int x=*max_element(rs.begin(),rs.end());
    if(rs[tar]==x){
        if(count(rs.begin(),rs.end(),x)==1) return 1;
        vector<Match> next;
        for(auto &m:match){
            if(rs[m.lhs]==x && rs[m.rhs]==x) next.push_back(m);
        }
        //cerr<<"#"<<next.size()<<endl;
        if(match.size()==next.size()){
            int cnt=count(rs.begin(),rs.end(),x);
            if(cnt==1) return 1;
            else return ld(place)/cnt;
        }
        else return winner(next,tar,place);
    }
    if(place<=count(rs.begin(),rs.end(),x)) return 0;
    int sndmax=0;
    for(int i=0;i<4;i++){
        if(rs[i]!=x) sndmax=max(sndmax,rs[i]);
    }
    if(rs[tar]==sndmax){
        if(count(rs.begin(),rs.end(),sndmax)==1) return 1;
        vector<Match> next;
        for(auto &m:match){
            if(rs[m.lhs]==sndmax && rs[m.rhs]==sndmax) next.push_back(m);
        }
        return winner(next,tar,1);
    }
    return 0;
}
ld pos(int point){
    ld res=1;
    for(int i=0;i<8;i++) res*=(i+1);
    for(int i=0;i<point;i++) res*=0.25/(i+1);
    for(int i=0;i<8-point;i++) res*=0.75/(i+1);
    return res;
}
int cnt=0;
ld dfs(int idx,vector<Match> &match,ld p,int tar){
    if(idx==match.size()){
        ld x=winner(match,tar,2);
        cnt++;
        debug(match);
        //cerr<<x<<endl;
        return p*x;
    }
    ld res=0;
    if(match[idx].lhsp==-1){
        for(int i=0;i<=8;i++){
            for(int j=0;j<=8;j++){
                match[idx].lhsp=i;
                match[idx].rhsp=j;
                res+=dfs(idx+1,match,p*pos(i)*pos(j),tar);
                match[idx].lhsp=-1;
                match[idx].rhsp=-1;
            }
        }
    }
    else{
        return dfs(idx+1,match,p,tar);
    }
    return res;
}
ld solve(){
    array<string,5> table;
    for(int i=0;i<5;i++) cin>>table[i];
    int tar=0;
    for(int i=0;i<4;i++){
        if(table[i+1][0]=='*') tar=i;
    }
    const int WIDTH=5;
    const int LHS=1;
    const int RHS=3;
    vector<Match> match;
    for(int i=0;i<4;i++){
        for(int j=0;j<i;j++){
            char lhsp=table[j+1][WIDTH*(i+1)+LHS];
            char rhsp=table[j+1][WIDTH*(i+1)+RHS];
            if(isdigit(lhsp)){
                assert(isdigit(rhsp));
                match.push_back(Match{j,i,lhsp-'0',rhsp-'0'});
            }
            else{
                match.push_back(Match{j,i,-1,-1});
            }
        }
    }
    assert(match.size()==6);
    return dfs(0,match,1,tar);
}
int main(){
    int n;
    cin>>n;
    cout<<setprecision(10)<<fixed;
    for(int i=0;i<n;i++){
        cout<<solve()<<endl;    
    }

    return 0;
}
