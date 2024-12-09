#include<bits/stdc++.h>
using namespace std;
#define ll long long 
void solve(){
    
  ll a=0,b=0,c=0,d=0,e=0,f=0;
cin>>a>>b;
vector<string> v;
vector<string> lost;
string s;
for(ll i=0;i<a;i++){
    
    cin>>s;
    v.push_back(s);
}
for(ll i=0;i<a-1;i++){
    cin>>s;
    lost.push_back(s);
}
s.clear();
vector<string> v1;
while(c<b){
    for(ll i=0;i<v.size();i++){
        s+=v[i][c];
    }
    v1.push_back(s);
    c++;
    s.clear();
}
vector<string> lost1;
c=0;
while(c<b){
    for(ll i=0;i<lost.size();i++){
        s+=lost[i][c];
    }
    lost1.push_back(s);
    c++;
    s.clear();
}
//cout<<"gh"<<endl;
string s1="";string s2="";string ans="";
for(ll i=0;i<v1.size();i++){
s1=v1[i];
s2=lost1[i];
sort(s1.begin(),s1.end());
sort(s2.begin(),s2.end());
for(ll j=0;j<s2.size();j++){
   if(s1[j]!=s2[j]){ans+=s1[j];e=1;break;}
}
if(e==0){
    ans+=s1[a-1];
}
else{e=0;}
}
cout<<ans<<endl;
 
     
 }
 
    
  
 
int main(){
    long long   t;
    cin>>t;
    while(t--){
      solve();
}
}