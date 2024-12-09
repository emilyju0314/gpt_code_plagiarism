#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
 
typedef long long ll;
 
using namespace std;
 
int main(){
    vector<int> vec;
    int n,in,last,c=1,ans=0,sum=0;
    
    scanf("%d",&n);
    
    scanf("%d",&in);
    last=in;
    
    for(int i=1;i<n;i++){
        scanf("%d",&in);
        if(last!=in){
            last=in;
            c++;
        }else{
            vec.push_back(c);
            c=1;
        }
    }
    
    vec.push_back(c);
    
    for(int i=0;i<vec.size();i++){
        sum+=vec[i];
        if(i>2)
            sum-=vec[i-3];
        ans=max(ans,sum);
    }
    
    printf("%d\n",ans);
    
    return 0;
}