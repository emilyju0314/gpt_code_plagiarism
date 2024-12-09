#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;
	int *A=new int[n];
	for(int i=0;i<n;++i)cin>>A[i];
	int q,k,sum=0;
    cin>>q;
    for(int i=0;i<q;++i){
    	cin>>k;
    	if(*(lower_bound(A,A+n,k))==k)sum++;
    }
    cout<<sum<<endl;
	return 0;
}
