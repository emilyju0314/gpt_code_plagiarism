#include <iostream>
using namespace std;
bool flag[10000001];

int main(){
    int n;
    for(int i=0;i <= 10000000;i++){
        if(i<=1)flag[i]=false;
        else flag[i]=true;
    }
    for(int i=2;i * i <= 10000000 ;i++){
        if(flag[i]==true){
            for(int j=i*2 ; j<=10000000 ; j=j+i){
                flag[j] = false;
            }
        }
    }
    while(cin>>n,n){
        for(int i=n;i!=0;i--){
            if(flag[i]&&flag[i-2]&&flag[i-6]&&flag[i-8]){
                cout<<i<<endl;
                break;
            }
        }
    }
}