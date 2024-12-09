#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>
#include<cstdio>
#include <string>
using namespace std;
 
int main(){
   int n;
   while(cin>>n){
       int ans;
       ans=n%39;
if(ans==0) ans=39;
       if(ans<10) cout<<"3C0"<<ans<<endl;
       else cout<<"3C"<<ans<<endl;
   }
    return 0;
}
