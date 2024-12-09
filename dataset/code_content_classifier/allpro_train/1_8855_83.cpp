#include <bits/stdc++.h>

using namespace std;
#define REPEAT(i,n) for(int (i) = 0; (i) < (n); ++(i))


int main()
{
   int t;
   cin>>t;
   string s;
    char chars[26];
   REPEAT(i,26){
        chars[i]='a'+i;
    }
   while(t--){
       
       cin>>s;
       int n=s.size();
       string ans="Yes";
       vector<bool> contains(n,0);
       for(char c:s){
           contains[c-'a']=1;
       }
       for(int i=0;i<n;i++){
           if(contains[i]!=1){
               ans="No";
           }
       }
       for(int i=1;i<n-1;i++){
           if(s[i]>s[i-1]&&s[i]>s[i+1]){
               ans="No";
           }
       }
       
       

       
       cout<<ans<<endl;
   }

    return 0;
}
