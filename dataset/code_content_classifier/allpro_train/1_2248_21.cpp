#include<bits/stdc++.h>
using namespace std;

long long num[9]={9,2*90,3*900,4*9000,5*90000,6*900000,7*9000000,
		  720000000,81000000000};

int main()
{
  int n,k;

  while(1){
    cin>>n>>k;
    if(n+k==0)break;

    string ans="";
    int index=0;
    for(int i=0;i<9;i++){
      if(n<=num[i]){
	n--;
	int sum=pow(10,i)+n/(i+1);
	index=n%(i+1);
	for(int i=sum;i<sum+101;i++){
	  ostringstream s;
	  s<<i;
	  ans+=s.str();
	}
	break;
      }
      n-=num[i];
    }
    for(int i=index;i<k+index;i++)cout<<ans[i];
    cout<<endl;
  }
  return 0;
}