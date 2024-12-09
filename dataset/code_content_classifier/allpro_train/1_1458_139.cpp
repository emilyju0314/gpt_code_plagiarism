#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,k;
    cin>>k>>a>>b;
    if(k<=a){
    	return puts("1"),0;
	}
    else if(a<=b){
    	return puts("-1"),0;
	}
    else{
    	 printf("%lld\n",((k-a)/(a-b)+bool((k-a)%(a-b)))<<1|1);
	}
}