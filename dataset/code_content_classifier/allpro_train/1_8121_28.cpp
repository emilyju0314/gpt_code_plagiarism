#include<iostream>
using namespace std;
int main()
{
char N[10];
cin>>N;
if(N[0]==N[1] && N[1]==N[2] || N[1]==N[2] && N[2]==N[3])cout<<"Yes"<<endl;
else
cout<<"No"<<endl;
return 0;
}