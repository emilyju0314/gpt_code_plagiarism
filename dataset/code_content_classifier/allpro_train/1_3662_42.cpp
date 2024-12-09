#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int px,py;
        cin>>px>>py;
        string str;
        cin>>str;
        unordered_map <char,int> mp;
        for(int i=0;i<str.size();i++){
            mp[str[i]]++;
        }

        bool tmp1,tmp2;
        if(px < 0){
            if(mp['L'] >= -1*px)
                tmp1 = true;
            else
                tmp1  = false;
        }
        else{
            if(mp['R'] >= px)
                tmp1 = true;
            else
                tmp1 = false;
        }

        if(py < 0){
            if(mp['D'] >= -1*py)
                tmp2 = true;
            else
                tmp2  = false;
        }
        else{
            if(mp['U'] >= py)
                tmp2 = true;
            else
                tmp2 = false;
        }

        if(tmp1 && tmp2)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}