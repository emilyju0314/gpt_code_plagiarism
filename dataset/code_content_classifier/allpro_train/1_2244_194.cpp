#include<iostream>
using namespace std;

int main(){
  int a[3],b,c,m,n,x,ans;
  cin>>c;
  for(int i=0;i<c;i++){
    for(int j=0;j<3;j++)
      cin>>a[j];
    n=333-(a[0]/3);
    m=999-a[0]-n;
    x=10-a[1];
    b=n*200+m*195;
    
    if(a[0]%3!=0 && a[1]%2==0)
      ans=(19-a[2])+(x/2*39)+b+1;
    else if(a[0]%3!=0 && a[1]%2!=0)
      ans=(20-a[2])+(x/2*20)+(x/2+1)*19+b+1;
    else if(a[0]%3==0)
      ans=20-a[2]+x*20+b+1;

    cout<<ans<<endl;
  }
  return 0;
}