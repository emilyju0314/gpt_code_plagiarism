#include <iostream>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

int m;
int n;

map<string,int> msi[2][201];

int dfs(string s,int isUsed,int pos){
    if(msi[isUsed][pos].find(s)!=msi[isUsed][pos].end())return msi[isUsed][pos][s];
    int cnt=0;
    for(int i=0;i<s.size();i++)if(s[i]=='B')cnt++;
    if(cnt==s.size()||cnt==0)return msi[isUsed][pos][s]=cnt;
    int res=0;
    {
        int npos=(pos+n-1)%s.size();
        string nstr=s;
        nstr.erase(nstr.begin()+npos);
        res=max(res,dfs(nstr,isUsed,npos));
    }
    if(!isUsed){
        int npos=(pos+n)%s.size();
        string nstr=s;
        nstr.erase(nstr.begin()+npos);
        res=max(res,dfs(nstr,!isUsed,npos));
    }
    return msi[isUsed][pos][s]=res;
}

int main(){

    cin>>m;
    while(m--){
        for(int i=0;i<2;i++)for(int j=0;j<201;j++)msi[i][j].clear();
        string s;
        cin>>n>>s;
        int res=dfs(s,0,0);
        cout<<res<<endl;
    }

    return 0;
}