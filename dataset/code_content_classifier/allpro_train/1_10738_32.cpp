#include<iostream>
#include<algorithm>
using namespace std;
int cost[100005],n,k;

bool check(int P){
    int i=1,temp;
    for(int j=1;j<=k;j++){
        temp=0;
        while(i<=n&&temp+cost[i]<=P){
            temp+=cost[i];
            i++;
            if(i>n)return true;
        }
    }
    return false;
}

int main(){
    int i,Left=0,Right=0,Mid;
    cin>>n>>k;
    for(i=1;i<=n;i++){
        cin>>cost[i];
        Right+=cost[i];
    }
    while(Left<Right){
        Mid=(Left+Right)>>1;
        if(check(Mid)){
            Right=Mid;
        }
        else Left=Mid+1;
    }
    cout<<Right<<endl;
    return 0;
}
