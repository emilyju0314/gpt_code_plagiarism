#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
	string a[101];
	int n,L;
    cin>>n>>L;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)cout<<a[i];
}