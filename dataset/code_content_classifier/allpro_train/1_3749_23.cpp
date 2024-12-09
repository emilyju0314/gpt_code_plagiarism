
#include<bits/stdc++.h>
using namespace std;

bool check(int t){
    int p = sqrt(t);

    if(p*p == t){
        return false;
    }
    return true;
}

void perfect(){
    int n;
    int temp=0,mul=1,flag=1;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>temp;
        if(check(temp)){
            flag=0;

        }
    }

    if(flag==0){

        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }


}
int main(){
    int t;
    cin>>t;
    for(int tt=0;tt<t;tt++){
        perfect();
    }

}