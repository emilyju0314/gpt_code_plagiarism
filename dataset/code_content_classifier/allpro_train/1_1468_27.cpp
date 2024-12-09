#include<bits/stdc++.h>
using namespace std;


vector<int>a;

int N;
bool prime[2000];


void mul(int x){
    int up=0;
    for(int i=0;i<a.size()-1;i++){
        a[i]=a[i]*x+up;
        up=a[i]/10;
        a[i]%=10;
    }
}

void add(int x){
    int up=x;
    for(int i=0;i<a.size();i++){
        a[i]+=up;
        up=a[i]/10;
        a[i]%=10;
    }
}

void print(){
    int pos=0;
    for(int i=0;i<a.size();i++)if(a[i])pos=i;
    for(int i=pos;i>=0;i--)cout<<a[i];cout<<endl;
}

int main(){
    scanf("%d",&N);
    a.resize(5000,0);
    a[0]=1;

    fill_n(prime,2000,true);
    prime[0]=prime[1]=false;
    for(int i=2;i<2000;i++){
        if(!prime[i])continue;
        for(int j=i*2;j<2000;j+=i)prime[j]=false;
    }

    for(int i=2;i<2000;i++)if(prime[i])mul(i);

    add(2);
    print();

    for(int i=2;i<N+2;i++){
        for(int j=2;j<=i;j++)if(i%j==0){
            cout<<j<<endl;
            break;
        }
    }
    return 0;
}