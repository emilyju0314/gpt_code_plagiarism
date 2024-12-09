#include <iostream>
using namespace std;
int ab[10000],bc[10000],ac[10000],ans=6000,na,nb,nc,L,R;
string a,b,c;
bool ch(char a,char b){
    return (a==b||a=='?'||b=='?');
}
int main(void){
    cin>>a>>b>>c;
    na=a.size();
    nb=b.size();
    nc=c.size();
    for(int i=0;i<na;i++){
        for(int j=0;j<nb;j++){
            if(!ch(a[i],b[j]))ab[i-j+5000]=1;
        }
    }
    for(int i=0;i<na;i++){
        for(int j=0;j<nc;j++){
            if(!ch(a[i],c[j]))ac[i-j+5000]=1;
        }
    }
    for(int i=0;i<nb;i++){
        for(int j=0;j<nc;j++){
            if(!ch(b[i],c[j]))bc[i-j+5000]=1;
        }
    }
    for(int i=-4000;i<=4000;i++){
        for(int j=-4000;j<=4000;j++){
            if(ab[i+5000]==0&&ac[j+5000]==0&&bc[j-i+5000]==0){
                L=min(0,min(i,j));
                R=max(na,max(i+nb,j+nc));
                //cout<<ans<<" "<<R<<L<<endl;
                ans=min(ans,R-L);
            }
        }
    }
    cout<<ans<<endl;
}
