#include<bits/stdc++.h>
using namespace std;

void z_algorithm(int *s,int *z,int n){
    int c=0;
    for(int i=1;i<n;i++){
        if(i+z[i-c]<c+z[c]){
            z[i]=z[i-c];
        }else{
            int j=max(0,c+z[c]-i);
            while(i+j<n&&s[j]==s[i+j])j++;
            z[i]=j;
            c=i;
        }
    }
    z[0]=n;
}

int n;
int a[200005],pa[200005];
int b[200005],pb[200005];
int s[600005],z[600005];

int main(){

    scanf("%d",&n);
    for(int i=0;i<n;i++)scanf("%d",a+i);
    for(int i=0;i<n;i++)scanf("%d",b+i);
    a[n]=a[0];
    b[n]=b[0];
    for(int i=0;i<n;i++){
        pa[i]=a[i]^a[i+1];
        pb[i]=b[i]^b[i+1];
    }
    memcpy(s,pb,n<<2);
    memcpy(s+n,pa,n<<2);
    memcpy(s+n+n,pa,n<<2);
    z_algorithm(s,z,n*3);
    for(int i=n;i<n<<1;i++){
        if(z[i]>=n)printf("%d %d\n",i-n,a[i-n]^b[0]);
    }

    return 0;
}