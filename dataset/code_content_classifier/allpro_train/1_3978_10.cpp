#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define EPS (1e-10)
#define EQ(a,b) (abs((a)-(b))<EPS)

const double PI=4*atan(1.0);

int main(){

    double r;
    while(cin>>r&&!EQ(r,0)){
        bool f=false;
        for(int i = 1; ; i++){
            for(int j = i*2; !(((double)j/i)>PI+r+EPS); j++){
                if(EQ(abs(((double)j/i)-PI),r)||abs(((double)j/i)-PI)<r){
                    f=true;
                    cout<<j<<"/"<<i<<endl;
                    break;
                }
            }
            if(f)
                break;
        }
    }
    return 0;
}