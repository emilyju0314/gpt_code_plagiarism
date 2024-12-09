#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int D,N;
    cin>>D>>N;

    cout<<static_cast<int>(pow(100,D)*(N+(N>=100)))<<endl;

    return 0;
}