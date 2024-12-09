#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
int n;
int item[114514];
int main(){
    while(cin>>n){
        int cnt=0,can=0;
        if(n==0)break;
        for(int i=0;i<n;i++){
            cin>>item[i];
            if(item[i]>0)cnt++;
            if(item[i]>1)can=1;
        }
        if(can==1)cout<<cnt+1<<endl;
        else cout<<"NA"<<endl;
    }
return 0;
}