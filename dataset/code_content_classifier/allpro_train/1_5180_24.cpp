#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    bool kawa=0;
    while(cin>>n,n){
        if(kawa)cout<<endl;
        string str[10];
        int num[10];
        for(int i=0,win,lose,draw;i<n;i++){
            cin>>str[i]>>win>>lose>>draw;
            num[i]=win*3+draw;
            str[i]+=',';
        }
        for(int i=0;i<n;i++){
            int ma=0;
            for(int j=0;j<n;j++)if(num[ma]<num[j])ma=j;
            cout<<str[ma]<<num[ma]<<endl;
            num[ma]=-1;
        }
        kawa=1;
    }
}