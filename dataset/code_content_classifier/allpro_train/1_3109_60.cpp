#include<bits/stdc++.h>
using namespace std;

using Oct=array<int,8>;
void rotateA(Oct& o){
    Oct tmp=o;
    for(int i=0;i<4;i++){
        o[i]=tmp[(i+1)%4];
        o[i+4]=tmp[(i+1)%4+4];
    }
}
void rotateB(Oct& oct){
    Oct tmp=oct;
    oct[0]=tmp[4];
    oct[1]=tmp[5];
    oct[2]=tmp[1];
    oct[3]=tmp[0];
    oct[4]=tmp[7];
    oct[5]=tmp[6];
    oct[6]=tmp[2];
    oct[7]=tmp[3];
}

bool check(Oct oct,set<Oct> &s){
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            for(int k=0;k<4;k++){
                if(s.count(oct)) return false;             
                rotateA(oct);
            }
            rotateB(oct);
        }
        rotateA(oct);
    }
    return true;
}
int dfs(int x,const vector<int>& v,set<Oct>& s,Oct& oct){
    if(x==8){
        assert(count(oct.begin(),oct.end(),-1)==0);
        if(!check(oct,s)) return 0;
        s.insert(oct);
        return 1;
    }
    int res=0;
    for(int i=0;i<oct.size();i++){
        if(oct[i]==-1){
            oct[i]=v[x];
            res+=dfs(x+1,v,s,oct);
            oct[i]=-1;
        }
    }
    return res;
}
int main(){
    vector<string> color(8);
    while(cin>>color[0]){
        for(int i=1;i<8;i++) cin>>color[i];
        map<string,int> mp;
        for(int i=0;i<8;i++) mp[color[i]]++;
        vector<int> v;
        int idx=0;
        for(auto &e:mp){
            for(int i=0;i<e.second;i++) v.push_back(idx);
            idx++;
        }
        set<Oct> s;
        Oct oct;
        fill(oct.begin(),oct.end(),-1);
        cout<<dfs(0,v,s,oct)<<endl;
    }
    return 0;
}
