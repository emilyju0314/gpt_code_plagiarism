#include <bits/stdc++.h>
using namespace std;

int main(){
   
    string S;
    int N;
    cin>>S>>N;
    for(int i=0;i<S.size();i+=N){
        cout<<S[i];
    }
    cout<<endl;
}
