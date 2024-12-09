#include <iostream>

using namespace std;

int main(){

    int a,b,c,d,e,na,nb,nc;
    while(cin>>a>>b>>c>>d>>e,a&&b&&c&&d&&e){
    cin>>na>>nb>>nc;
        if(na+nb+nc>=d){
            if(nc>=d){
                cout<<min(a*na+b*nb+(nc)*e,a*na+b*nb+c*nc)<<endl;
            }else if(nc+nb>=d){
                cout<<min(a*na+b*(nb-(d-nc))+(nc+(d-nc))*e,a*na+b*nb+c*nc)<<endl;
            }else if(nc+nb+na>=d){
                cout<<min(a*(na-(d-nc-nb))+(nc+nb+(d-nc-nb))*e,a*na+b*nb+c*nc)<<endl;
            }
            
        }else{
            cout<<min(d*e,a*na+b*nb+c*nc)<<endl;
        }
    }

}

