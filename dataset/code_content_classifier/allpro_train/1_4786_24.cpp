#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define endl "\n"


bool pal(string s){
    int  i = 0, j = s.size()-1;
    
    
    while(i<=j){
        if(s[i++]!=s[j--]){
            return false;
        }
    }
    
    return true;
}

void solve(){
    string s;
    cin>>s;
    int n = (int)s.size();
    bool same = true;
    
    for(int i = 1;i<n;i++){
        if(s[i] != s[i-1]) {
            same = false;
            break;
        }
    }
    
    
    if(pal(s)){
        
        if(s[0] == 'a' && same)
            cout<<"NO\n";
        else {
            cout<<"YES\n";
            s+="a";
            cout<<s<<endl;
        }
    }else{
        cout<<"YES\n";
        string ans;
        int m  = (int)s.find("a");
        int last_oc = (int)s.rfind("a");
        
        if(m==0 && last_oc == n-1){
            if(!pal(s+"a")) {
                s+="a";
                cout<<s<<endl;
            }
            else{
                ans = "a"+s;
                cout<<ans<<endl;
            }
        }
        else if(m==0){
            ans = "a" + s;
            cout<<ans<<endl;
            
        }else {
            s+="a";
            cout<<s<<endl;
        }
        
    }
}

int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}

