#include<iostream>
#include<string.h>
int main(){for(int m,n,o,c,d,e,i;!(std::cin>>n).eof();){if(n<3)e=n>1;else{bool*v=new bool[c=(n&1?n:--n)/2+1];memset(v,1,c);for(i=m=e=1;i<c;i++){for(m=i;m<c&&!v[m];)m++;if(m==c)break;e++;for(d=o=m*2+1;d<n+1;d+=o*2)v[d/2]=0;if(n<o*o)break;}for(i=1;i<c;)e+=v[i++];delete[]v;}printf("%d\n",e);}}