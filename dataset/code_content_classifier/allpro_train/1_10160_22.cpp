#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int arr[4];
        for(int i=0;i<4;i++)
            cin>>arr[i];
        int m,n;
        if(arr[0]>arr[1])
            m=arr[0];
        else m=arr[1];

         if(arr[2]>arr[3])
            n=arr[2];
        else n=arr[3];

      sort(arr,arr+4);

     if((m==arr[2]&& n==arr[3]) || (m==arr[3]&& n==arr[2]))
     cout<<"YES"<<endl;
     else cout<<"NO"<<endl;



















    }








}
