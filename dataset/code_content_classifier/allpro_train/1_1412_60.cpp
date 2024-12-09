#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define mp make_pair

int main(){

ios_base::sync_with_stdio(false);cin.tie(NULL);
   
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif 

    int t;
    cin>>t;
    while(t--){
    long long n,x;
    cin>>n>>x;
    long long sum=0;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int check=0;
    long long sum1=0;
    for(int i=0;i<n;i++){
        if(arr[i]%x==0){
            if(check){
                sum1+=arr[i];
            }
            else
                sum+=arr[i]/x;
        }
        else{
            sum1+=arr[i];
            check=1;
        }
    }

    if(sum1%x==0)
        sum+=sum1/x;
    else
        sum+=(sum1/x)+1;
    
    cout<<sum<<" ";

    sum=0;
    for(int i=0;i<n;i++){
        if(arr[i]%x==0)
            sum+=arr[i]/x;
        else
            sum+=(arr[i]/x)+1;
    }
    cout<<sum<<endl;
   }

}