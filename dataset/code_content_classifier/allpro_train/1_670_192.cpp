#include<bits/stdc++.h>
using namespace std;
char a[50][50];
int c,d,b[55][55];
int main(){
    cin>>c>>d;
    for(int i=0;i<c;i++)
    cin>>a[i];
    for(int i=0;i<c;i++)
    for(int j=0;j<d;j++)
    if(a[i][j]=='#')
    b[i][j]++,b[i][j+1]++,b[i][j+2]++,
    b[i+1][j]++,b[i+1][j+1]++,b[i+1][j+2]++,
    b[i+2][j]++,b[i+2][j+1]++,b[i+2][j+2]++;
    for(int i=0;i<c;i++){
        for(int j=0;j<d;j++)if(a[i][j]=='#') cout<<'#';else cout<<b[i+1][j+1];cout<<endl;
    }
}