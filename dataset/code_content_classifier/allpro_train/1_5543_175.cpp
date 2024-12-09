#include <iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int main(){

    int n,q;
    cin>>n>>q;
    
    queue<int> Q[n];
    while(q>0){
        
        int a,b;
        cin>>a>>b;
        if(a==0){
            int c;
            cin>>c;
            Q[b].push(c);
        }else if(a==1){
            if(!Q[b].empty())cout<<Q[b].front()<<endl;
        }else{
            if(!Q[b].empty())Q[b].pop();
        }
        
        
        q--;
    }
    
return 0;
}

