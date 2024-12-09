#include <iostream>
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int compute(int A,int K){
    int B = A%K;
    int C = 1 + (A - A%K)/K;
    if(B%C==0)
        return C-1;
    else{
        return(compute(A-C*(1+(B-B%C)/C),K));
    }


}


int main()
{
    int N;
    cin>>N;
    int A[N], K[N];
    int x = 0;
    for(int i=0; i<N; i++){
        cin>>A[i]>>K[i];
        x = (x ^ compute(A[i],K[i]));
    }
    if(x==0)
        cout<<"Aoki"<<endl;
    else
        cout<<"Takahashi"<<endl;
    return 0;
}
