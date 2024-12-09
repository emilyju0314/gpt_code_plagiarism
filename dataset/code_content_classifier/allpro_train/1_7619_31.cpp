#include<iostream>
using namespace std;

#define MAX 200000
#define SEN 2000000000
typedef long long llong;

int L[MAX/2+2],R[MAX/2+2];

llong merge(int A[],int n,int l,int m,int r){
  int i,j,k;
  llong cnt=0;
  int n1=m-l;
  int n2=r-m;
  for(i=0;i<n1;i++) L[i]=A[l+i];

  for(i=0;i<n2;i++) R[i]=A[m+i];
  L[n1]=R[n2]=SEN;
  i=j=0;
  for(k=l;k<r;k++){

    if(L[i]<=R[j]){
      A[k]=L[i++];
    }
    else{
      A[k]=R[j++];
      cnt += n1 -i;
    }
  }
  return cnt;
}


llong mS(int A[],int n,int l,int r){
  int m;
  llong v1,v2,v3;
  if(l+1<r){
    m=(l+r)/2;
    v1=mS(A,n,l,m);
    v2=mS(A,n,m,r);
    v3=merge(A,n,l,m,r);
    return v1+v2+v3;
  }
  else return 0;
}



int main(){

  int A[MAX],n,i;

  cin >> n;
  for(i=0;i<n;i++){
    cin >> A[i];
  }

  llong ans=mS(A,n,0,n);
  cout << ans << endl;

  return 0;
}

