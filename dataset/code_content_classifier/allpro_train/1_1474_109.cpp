#include<bits/stdc++.h>
using namespace std;
int main(void)
{
  int n,i=0,s[10000],flag=0,maxi=0,a,b,j,temp=0,te=0;
  cin>>n;
  for(i=0;i<n;i++)
  {
      scanf("%d",&s[i]);
  }
  for(i=0;i<n;i++)
    for(j=i+1;j<n;j++)
  {
      temp=s[i]*s[j];
      if(temp<10)
      {
          if(maxi<temp) maxi=temp;
      }
      else{  te=temp;
      while(temp!=0)
      {   a=temp%10;
          temp/=10;
          if(temp==0) break;
          if((a-1)==temp%10) flag=1;
          else {flag=0;break;}
      }
      if(flag)
      {
          if(maxi<te) maxi=te;
      }
      }
  }
  if(maxi==0) puts("-1");
  else
  printf("%d\n",maxi);
 return 0;
}