#include <iostream>
using namespace std;

int a,b,c;

int main(){
    cin>>a>>b>>c;

    int x = min(a-b,c);
    cout<<c-x<<endl;
}