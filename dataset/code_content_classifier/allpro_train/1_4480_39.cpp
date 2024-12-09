#include<bits/stdc++.h>
using namespace std;
int mygcd(int64_t a,int64_t b){
    if(a%b==0) return b;
    else return (mygcd(b,a%b));
}
int main(){
    int64_t A,B,C,D;
    cin>>A>>B>>C>>D;
    cout<<B-(B/C)-(B/D)+B/((C*D)/mygcd(C,D))-((A-1)-(A-1)/C-(A-1)/D+(A-1)/((C*D)/mygcd(C,D)))<<endl;
}