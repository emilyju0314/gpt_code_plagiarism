#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> monsters(n);
        for(int i=0;i<n;i++){
            cin>>monsters[i];
        }
        int m;
        cin>>m;
        vector<pair<int,int>> heroes(m);
        for(int i=0;i<m;i++){
            cin>>heroes[i].first>>heroes[i].second;
        }
        sort(monsters.begin(),monsters.end());
        sort(heroes.begin(),heroes.end(),greater<pair<int,int>>());
        int ans = 0;
        int cnt = 0;
        int i = 0, j = 0;
        while(i < n && j < m){
            int power = heroes[j].first;
            int endurance = heroes[j].second;
            while(i < n && power >= monsters[i]){
                cnt++;
                i++;
                if(cnt == endurance){
                    cnt = 0;
                    j++;
                }
            }
            ans++;
        }
        if(i < n){
            cout<<-1<<endl;
        }else{
            cout<<ans<<endl;
        }
    }
    return 0;
}