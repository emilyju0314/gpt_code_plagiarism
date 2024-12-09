#include<bits/stdc++.h>
using namespace std;
int main(){
	int xi;
 	cin>>xi;
  	int pos = ceil(xi/1.08);
  	if (floor(pos*1.08)==xi) cout<<pos;
  else cout<<":(";
}