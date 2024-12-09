#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
int main(){
    int h,w;
    while(cin>>h>>w){
        if(h+w == 0)break;
        vector<string> v(h);
        map<char,pair<int,int>> mp;
        for(int i=0;i<h;i++)cin>>v[i];
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                mp[v[i][j]] = pair<int,int>(i,j);
            }
        }
        string s;
        cin>>s;
        pair<int,int> now = pair<int,int>(0,0);
        int ans=0;
        for(int i=0;i<s.size();i++){
            pair<int,int> next = mp[s[i]];
            ans += abs(now.first-next.first)+abs(now.second-next.second);
            now = next;
        }
        cout<<ans + s.size()<<endl;
    }
}
