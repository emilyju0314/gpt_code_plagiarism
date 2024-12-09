#include <iostream>
using namespace std;
int main(void){
    int n,m,a[100],i,j,sum,ave;
    while(1){
        cin >> n >> m ;
        if(n==0 && m==0) break;
        ave=m/n;
        sum=0;
        for(i=0;i<n;i++) cin >> a[i] ;
        for(j=0;j<n;j++){
            if(a[j]>=ave) sum+=ave;
            else if(a[j]>0) sum+=a[j];
        }
        cout << sum << endl;
    }
    
}

